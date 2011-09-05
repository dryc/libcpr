/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <fcntl.h>    /* for the AT_* constants */
#include <stdio.h>    /* for snprintf() */
#include <sys/stat.h> /* for fstatat() */

int
dir_init_empty(dir_t* dir) {
  validate_with_errno_return(dir != NULL);

  bzero(dir, sizeof(dir_t));

  return SUCCESS;
}

int
dir_init_with_path(dir_t* dir, const char* const restrict path) {
  const int result = dir_init_empty(dir);

  if (likely(succeeded(result) && path != NULL)) {
    strncpy(dir->path, path, sizeof(dir->path) - 1);
  }

  return result;
}

int
dir_open(dir_t* dir) {
  validate_with_errno_return(dir != NULL);
  if (unlikely(dir->stream != NULL)) {
    return SUCCESS; // already opened
  }

#ifdef HAVE_OPENDIR
  dir->stream = opendir(dir->path);
#else
  return -(errno = ENOTSUP); // operation not supported
#endif

  if (unlikely(dir->stream == NULL)) {
    return -errno;
  }

  dir->entry = malloc(DIRENT_SIZE);

  return SUCCESS;
}

int
dir_close(dir_t* dir) {
  validate_with_errno_return(dir != NULL);

  int result = SUCCESS;

  if (likely(dir->entry != NULL)) {
    free(dir->entry);
    dir->entry = NULL;
  }

  if (likely(dir->stream != NULL)) {
#ifdef HAVE_CLOSEDIR
    if (unlikely(closedir(dir->stream) == -1)) {
      result = -errno;
    }
#else
    result = -(errno = ENOTSUP); // operation not supported
#endif
    dir->stream = NULL;
  }

  return result;
}

int
dir_read(dir_t* dir) {
  validate_with_errno_return(dir != NULL);

  struct dirent* result = NULL;
#ifdef HAVE_READDIR_R
  assert(dir->stream != NULL);
  assert(dir->entry != NULL);
  const int rc = readdir_r(dir->stream, dir->entry, &result);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? (result != NULL) : -(errno = rc);
}

long
dir_size(dir_t* dir) {
  validate_with_errno_return(dir != NULL);

  // Open the directory stream:
  DIR* stream = opendir(dir->path);
  if (unlikely(stream == NULL)) {
    return -errno;
  }

  // Obtain the file descriptor for the directory stream:
  const int fd = dirfd(stream);
  if (unlikely(fd == -1)) {
    return -errno;
  }

  // Obtain the size of the directory itself:
  struct stat st;
  if (unlikely(fstat(fd, &st))) {
    return -errno;
  }
  long result = st.st_size;

  // Iterate over every directory entry:
  struct dirent* entry = NULL;
  while ((entry = readdir(stream)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;

    // Obtain the size of the current directory entry:
#ifdef __linux__
    if (unlikely(fstatat(dirfd(stream), entry->d_name, &st, AT_SYMLINK_NOFOLLOW) == -1)) {
      return -errno;
    }
#else
    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s/%s", dir->path, entry->d_name);
    if (unlikely(lstat(path, &st) == -1)) {
      return -errno;
    }
#endif

    result += st.st_size;
  }

  // Close the directory stream:
  closedir(stream), stream = NULL;

  return result;
}
