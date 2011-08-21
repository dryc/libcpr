/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <string.h> /* for strlen(), strcmp(), strncmp(), strstr() */

long
str_size(const char* const restrict str) {
  validate_with_zero_return(str != NULL);

  if (unlikely(*str == '\0'))
    return 0; // the string is empty

  return strlen(str);
}

long
str_length(const char* const restrict str) {
  validate_with_zero_return(str != NULL);

  if (unlikely(*str == '\0'))
    return 0; // the string is empty

#ifdef DISABLE_UNICODE
  return strlen(str); // ASCII only
#else
  long length = 0;
  const char* data = str;
  while (likely(*data != '\0')) {
    length++;
    data = UTF8_SKIP_CHAR(data);
  }
  return length;
#endif /* DISABLE_UNICODE */
}

int
str_hash(const char* const restrict str) {
  validate_with_errno_return(str != NULL);

  uint32_t hash = 5381;
  const int8_t* data = (int8_t*)str;
  while (likely(*data != '\0')) {
    hash = ((hash << 5) + hash) + *data++; // hash * 33 + c
  }
  return (hash & INT32_MAX);
}

int
str_compare(const char* const str1, const char* const str2) {
  if (unlikely(str1 == str2))
    return 0;

  return strcmp(str1, str2);
}

bool
str_equal(const char* const str1, const char* const str2) {
  if (unlikely(str1 == str2))
    return TRUE;

  return (strcmp(str1, str2) == 0) ? TRUE : FALSE;
}

bool
str_is_empty(const char* const restrict str) {
  if (unlikely(str == NULL))
    return errno = EINVAL, TRUE;

  return unlikely(*str == '\0') ? TRUE : FALSE;
}

bool
str_is_ascii(const char* const restrict str) {
  validate_with_false_return(str != NULL);

  const char* chr = str;
  while (likely(*chr != '\0')) {
    if (unlikely(!char_is_ascii(chr[0]))) {
      return FALSE;
    }
  }
  return TRUE;
}

bool
str_is_utf8(const char* const restrict str) {
  validate_with_false_return(str != NULL);

#ifdef DISABLE_UNICODE
  return errno = ENOTSUP, FALSE;
#else
  const char* chr = str;
  while (likely(*chr != '\0')) {
    // TODO: UTF8_DECODE()
    chr = UTF8_SKIP_CHAR(chr);
  }
  return TRUE;
#endif /* DISABLE_UNICODE */
}

static inline bool
str_is(const char* const restrict str, int (*predicate)(const char_t chr)) {
  validate_with_false_return(str != NULL && predicate != NULL);

  const char* chr = str;
  while (likely(*chr != '\0')) {
#ifdef DISABLE_UNICODE
    if (unlikely(predicate(chr[0]) != TRUE)) {
      return FALSE;
    }
    chr++; // ASCII only
#else
    if (unlikely(predicate(chr[0]) != TRUE)) { // TODO: UTF8_DECODE()
      return FALSE;
    }
    chr = UTF8_SKIP_CHAR(chr);
#endif /* DISABLE_UNICODE */
  }
  return TRUE;
}

bool
str_is_alnum(const char* const restrict str) {
  return str_is(str, char_is_alnum);
}

bool
str_is_alpha(const char* const restrict str) {
  return str_is(str, char_is_alpha);
}

bool
str_is_blank(const char* const restrict str) {
  return str_is(str, char_is_blank);
}

bool
str_is_cntrl(const char* const restrict str) {
  return str_is(str, char_is_cntrl);
}

bool
str_is_digit(const char* const restrict str) {
  return str_is(str, char_is_digit);
}

bool
str_is_graph(const char* const restrict str) {
  return str_is(str, char_is_graph);
}

bool
str_is_lower(const char* const restrict str) {
  return str_is(str, char_is_lower);
}

bool
str_is_print(const char* const restrict str) {
  return str_is(str, char_is_print);
}

bool
str_is_punct(const char* const restrict str) {
  return str_is(str, char_is_punct);
}

bool
str_is_space(const char* const restrict str) {
  return str_is(str, char_is_space);
}

bool
str_is_upper(const char* const restrict str) {
  return str_is(str, char_is_upper);
}

bool
str_is_xdigit(const char* const restrict str) {
  return str_is(str, char_is_xdigit);
}

bool
str_has_prefix(const char* const restrict str, const char* const restrict prefix) {
  validate_with_false_return(str != NULL && prefix != NULL);

  const size_t string_size = strlen(str);
  const size_t prefix_size = strlen(prefix);

  if (unlikely(string_size < prefix_size)) {
    return FALSE;
  }

  return unlikely(strncmp(str, prefix, prefix_size) == 0) ? TRUE : FALSE;
}

bool
str_has_suffix(const char* const restrict str, const char* const restrict suffix) {
  validate_with_false_return(str != NULL && suffix != NULL);

  const size_t string_size = strlen(str);
  const size_t suffix_size = strlen(suffix);

  if (unlikely(string_size < suffix_size)) {
    return FALSE;
  }

  return unlikely(strcmp(str + string_size - suffix_size, suffix) == 0) ? TRUE : FALSE;
}

bool
str_contains(const char* const restrict str, const char* const restrict substr) {
  validate_with_false_return(str != NULL && substr != NULL);

  return unlikely(strstr(str, substr) != NULL) ? TRUE : FALSE;
}
