/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <stdlib.h> /* for calloc(), free(), malloc() */

string_t*
string_alloc_empty() {
  string_t* string = malloc(sizeof(string_t));
  string_init_empty(string);
  return string;
}

string_t*
string_alloc_with(const char* const data, const size_t size) {
  string_t* string = malloc(sizeof(string_t));
  string_init_with(string, data, size);
  return string;
}

string_t*
string_alloc_with_data(const char* const data) {
  string_t* string = malloc(sizeof(string_t));
  string_init_with_data(string, data);
  return string;
}

string_t*
string_alloc_with_size(const size_t size) {
  string_t* string = malloc(sizeof(string_t));
  string_init_with_size(string, size);
  return string;
}

int
string_init_empty(string_t* string) {
  validate_arguments(string != NULL);

  bzero(string, sizeof(string_t));

  return 0;
}

int
string_init_with(string_t* string, const char* const data, const size_t size) {
  validate_arguments(string != NULL);
  if (likely(size > 0 && size != STRING_SIZE_UNKNOWN))
    validate_arguments(data != NULL);

  int result = string_init_empty(string);

  if (likely(data != NULL && *data != '\0' && size > 0)) {
    // Copy the given string contents, up to the specified byte length:
    const size_t size2 = unlikely(size == STRING_SIZE_UNKNOWN) ? strlen(data) : size;
    string->data = strndup(data, size2);
    string->size = size2;

    if (unlikely(string->data == NULL))
      result = -errno; // insufficient memory (ENOMEM)
  }

  return result;
}

int
string_init_with_data(string_t* string, const char* const data) {
  validate_arguments(string != NULL);

  int result = string_init_empty(string);

  if (likely(data != NULL && *data != '\0')) {
    // Copy the given string contents, also determining and memoizing the
    // byte length in order to speed up subsequent operations on the string:
    string->data = strdup(data);
    string->size = strlen(data); // TODO: avoid traversing the input twice.

    if (unlikely(string->data == NULL))
      result = -errno; // insufficient memory (ENOMEM)
  }

  return result;
}

int
string_init_with_size(string_t* string, const size_t size) {
  validate_arguments(string != NULL);

  int result = string_init_empty(string);

  if (likely(size > 0 && size != STRING_SIZE_UNKNOWN)) {
    // Allocate sufficient memory for the string contents, including an
    // extra byte for the terminating null sentinel:
    string->data = calloc(size + 1, sizeof(byte_t));
    string->size = size;

    if (unlikely(string->data == NULL))
      result = -errno; // insufficient memory (ENOMEM)
  }

  return result;
}

size_t
string_size(const string_t* const string) {
  validate_arguments(string != NULL);

  if (unlikely(string->size == 0))
    return 0; // the string is empty

  if (likely(string->size != STRING_SIZE_UNKNOWN))
    return string->size;

  return strlen(string->data);
}

size_t
string_length(const string_t* const string) {
  validate_arguments(string != NULL);

#ifndef _CPRIME_HAVE_UTF8
  return string_size(string); // ASCII only
#else
#error UTF-8 support for string_length() has not yet been implemented.
#endif /* !_CPRIME_HAVE_UTF8 */
}

int
string_compare(const string_t* const string1, const string_t* const string2) {
  validate_arguments(string1 != NULL && string2 != NULL);

  if (unlikely(string1 == string2))
    return 0;

  return strcmp(string1->data, string2->data);
}

int
string_equal(const string_t* const string1, const string_t* const string2) {
  validate_arguments(string1 != NULL && string2 != NULL);

  if (unlikely(string1 == string2))
    return TRUE;

  if (likely(string1->size != string2->size))
    return FALSE;

  return unlikely(strcmp(string1->data, string2->data) == 0) ? TRUE : FALSE;
}

int
string_is_empty(const string_t* const string) {
  validate_arguments(string != NULL);

  if (unlikely(string->size == 0 || string->data == NULL))
    return TRUE;

  if (unlikely(*(string->data) == '\0'))
    return TRUE;

  return FALSE;
}

int
string_is_alnum(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_is_alpha(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_is_ascii(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_is_blank(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_is_cntrl(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_is_digit(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_is_graph(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_is_lower(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_is_print(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_is_punct(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_is_space(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_is_upper(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_is_xdigit(const string_t* const string) {
  validate_arguments(string != NULL);

  return FALSE; // TODO
}

int
string_has_prefix(const string_t* const string, const char* const prefix) {
  validate_arguments(string != NULL && prefix != NULL);

  if (unlikely(string_is_empty(string) == TRUE))
    return FALSE; // empty strings don't have prefixes

  const size_t string_len = string_size(string);
  const size_t prefix_len = strlen(prefix);
  if (unlikely(string_len < prefix_len))
    return FALSE; // a string can't contain a prefix longer than itself

  const char* string_data = string->data;
  return unlikely(strncmp(string_data, prefix, prefix_len) == 0) ? TRUE : FALSE;
}

int
string_has_suffix(const string_t* const string, const char* const suffix) {
  validate_arguments(string != NULL && suffix != NULL);

  if (unlikely(string_is_empty(string) == TRUE))
    return FALSE; // empty strings don't have suffixes

  const size_t string_len = string_size(string);
  const size_t suffix_len = strlen(suffix);
  if (unlikely(string_len < suffix_len))
    return FALSE; // a string can't contain a suffix longer than itself

  const char* string_data = string->data + string_len - suffix_len; // FIXME: UTF-8 support
  return unlikely(strncmp(string_data, suffix, suffix_len) == 0) ? TRUE : FALSE;
}

int
string_clear(string_t* string) {
  validate_arguments(string != NULL);

  if (likely(string->data != NULL)) {
    free(string->data);
    string->data = NULL;
  }
  string->size = 0;

  return 0;
}
