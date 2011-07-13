/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <string.h>
#include <strings.h>

int
string_equal(const string_t* const string1, const string_t* const string2) {
  if (unlikely(string1 == NULL || string2 == NULL))
    return -EINVAL;

  if (unlikely(string1 == string2))
    return TRUE;
  if (likely(string1->size != string2->size))
    return FALSE;

  return (strcmp(string1->data, string2->data) == 0);
}

int
string_compare(const string_t* const string1, const string_t* const string2) {
  if (unlikely(string1 == NULL || string2 == NULL))
    return -EINVAL;

  if (unlikely(string1 == string2))
    return 0;

  return strcmp(string1->data, string2->data);
}
