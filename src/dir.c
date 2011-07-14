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
