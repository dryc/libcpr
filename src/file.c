/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <sys/stat.h> /* for stat() */
#include <unistd.h>

const class_t file_class = {
  .name    = "file",
  .super   = NULL,
  .vtable  = NULL, // TODO
};

bool
file_exists(const char* const path) {
  validate_with_false_return(!str_is_empty(path));

  struct stat st;
  if (stat(path, &st) == -1) {
    return FALSE;
  }
  return TRUE;
}
