/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <string.h> /* for strlen(), strcmp(), strncmp(), strstr() */

int
str_compare(const char* str1, const char* str2) {
  if (unlikely(str1 == str2))
    return 0;
  return strcmp(str1, str2);
}

bool
str_equal(const char* str1, const char* str2) {
  if (unlikely(str1 == str2))
    return TRUE;
  return (strcmp(str1, str2) == 0) ? TRUE : FALSE;
}

int
str_hash(const char* restrict str) {
  validate_with_errno_return(str != NULL);

  uint32_t hash = 5381;
  const int8_t* data = (int8_t*)str;
  while (likely(*data != '\0')) {
    hash = ((hash << 5) + hash) + *data++; // hash * 33 + c
  }
  return (hash & INT32_MAX);
}

bool
str_contains(const char* restrict str, const char* restrict substr) {
  validate_with_false_return(str != NULL && substr != NULL);

  return unlikely(strstr(str, substr) != NULL) ? TRUE : FALSE;
}

bool
str_has_prefix(const char* restrict str, const char* restrict prefix) {
  validate_with_false_return(str != NULL && prefix != NULL);

  const size_t string_size = strlen(str);
  const size_t prefix_size = strlen(prefix);

  if (unlikely(string_size < prefix_size)) {
    return FALSE;
  }

  return unlikely(strncmp(str, prefix, prefix_size) == 0) ? TRUE : FALSE;
}

bool
str_has_suffix(const char* restrict str, const char* restrict suffix) {
  validate_with_false_return(str != NULL && suffix != NULL);

  const size_t string_size = strlen(str);
  const size_t suffix_size = strlen(suffix);

  if (unlikely(string_size < suffix_size)) {
    return FALSE;
  }

  return unlikely(strcmp(str + string_size - suffix_size, suffix) == 0) ? TRUE : FALSE;
}
