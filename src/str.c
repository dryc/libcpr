/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <string.h> /* for strlen(), strcmp(), strncmp() */

bool
str_has_prefix(const char* restrict str, const char* restrict prefix) {
  validate_with_false_return(str != NULL && prefix != NULL);

  const size_t string_size = strlen(str);
  const size_t prefix_size = strlen(prefix);

  if (unlikely(string_size < prefix_size)) {
    return FALSE;
  }

  return (strncmp(str, prefix, prefix_size) == 0) ? TRUE : FALSE;
}

bool
str_has_suffix(const char* restrict str, const char* restrict suffix) {
  validate_with_false_return(str != NULL && suffix != NULL);

  const size_t string_size = strlen(str);
  const size_t suffix_size = strlen(suffix);

  if (unlikely(string_size < suffix_size)) {
    return FALSE;
  }

  return (strcmp(str + string_size - suffix_size, suffix) == 0) ? TRUE : FALSE;
}
