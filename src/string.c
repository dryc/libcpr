/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <string.h>  /* for strlen(), strcmp() */
#include <strings.h>

size_t
string_size(const string_t* const string) {
  if (unlikely(string == NULL))
    return -EINVAL;

  if (unlikely(string->size == 0))
    return 0; // the string is empty

  if (likely(string->size != STRING_SIZE_UNKNOWN))
    return string->size;

  return strlen(string->data);
}

size_t
string_length(const string_t* const string) {
  if (unlikely(string == NULL))
    return -EINVAL;

#ifndef _CPRIME_HAVE_UTF8
  return string_size(string); // ASCII only
#else
#error UTF-8 support has not yet been implemented.
#endif /* !_CPRIME_HAVE_UTF8 */
}

int
string_equal(const string_t* const string1, const string_t* const string2) {
  if (unlikely(string1 == NULL || string2 == NULL))
    return -EINVAL;

  if (unlikely(string1 == string2))
    return TRUE;

  if (likely(string1->size != string2->size))
    return FALSE;

  return unlikely(strcmp(string1->data, string2->data) == 0) ? TRUE : FALSE;
}

int
string_compare(const string_t* const string1, const string_t* const string2) {
  if (unlikely(string1 == NULL || string2 == NULL))
    return -EINVAL;

  if (unlikely(string1 == string2))
    return 0;

  return strcmp(string1->data, string2->data);
}

int
string_is_empty(const string_t* const string) {
  if (unlikely(string == NULL))
    return -EINVAL;

  return unlikely(string_length(string) == 0) ? TRUE : FALSE;
}
