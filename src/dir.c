/* This is free and unencumbered software released into the public domain. */

#include "build.h"

int
dir_init_empty(dir_t* dir) {
  validate_with_errno_return(dir != NULL);

  bzero(dir, sizeof(dir_t));

  return 0;
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

  dir->stream = opendir(dir->path);

  return likely(dir->stream != NULL) ? 0 : -errno;
}

int
dir_close(dir_t* dir) {
  validate_with_errno_return(dir != NULL);

  int result = 0;

  if (likely(dir->stream != NULL)) {
    if (unlikely(closedir(dir->stream) == -1)) {
      result = -errno;
    }
    dir->stream = NULL;
  }

  return result;
}
