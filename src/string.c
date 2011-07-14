/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <stdlib.h> /* for calloc(), free(), malloc() */

string_t*
string_alloc() {
  string_t* string = malloc(sizeof(string_t));
  string_init_empty(string);
  return string;
}

string_t*
string_construct_with(const byte_t* const data, const size_t size) {
  string_t* string = malloc(sizeof(string_t));
  string_init_with(string, data, size);
  return string;
}

string_t*
string_construct_with_data(const byte_t* const data) {
  string_t* string = malloc(sizeof(string_t));
  string_init_with_data(string, data);
  return string;
}

string_t*
string_construct_with_size(const size_t size) {
  string_t* string = malloc(sizeof(string_t));
  string_init_with_size(string, size);
  return string;
}

string_t*
string_clone(const string_t* const string) {
  validate_with_null_return(string != NULL);
  if (likely(string->size > 0 && string->size != STRING_SIZE_UNKNOWN))
    validate_with_null_return(string->data != NULL);

  return string_construct_with(string->data, string->size);
}

int
string_init_empty(string_t* string) {
  validate_with_errno_return(string != NULL);

  bzero(string, sizeof(string_t));

  return 0;
}

int
string_init_with(string_t* string, const byte_t* const data, const size_t size) {
  validate_with_errno_return(string != NULL);
  if (likely(size > 0 && size != STRING_SIZE_UNKNOWN))
    validate_with_errno_return(data != NULL);

  int result = string_init_empty(string);

  if (likely(data != NULL && *data != '\0' && size > 0)) {
    // Copy the given string contents, up to the specified byte length:
    const size_t size2 = unlikely(size == STRING_SIZE_UNKNOWN) ? strlen((char*)data) : size;
    string->data = (byte_t*)strndup((char*)data, size2);
    string->size = size2;

    if (unlikely(string->data == NULL))
      result = -errno; // insufficient memory (ENOMEM)
  }

  return result;
}

int
string_init_with_data(string_t* string, const byte_t* const data) {
  validate_with_errno_return(string != NULL);

  int result = string_init_empty(string);

  if (likely(data != NULL && *data != '\0')) {
    // Copy the given string contents, also determining and memoizing the
    // byte length in order to speed up subsequent operations on the string:
    string->data = (byte_t*)strdup((char*)data);
    string->size = strlen((char*)data); // TODO: avoid traversing the input twice.

    if (unlikely(string->data == NULL))
      result = -errno; // insufficient memory (ENOMEM)
  }

  return result;
}

int
string_init_with_size(string_t* string, const size_t size) {
  validate_with_errno_return(string != NULL);

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
  validate_with_errno_return(string != NULL);

  if (unlikely(string->size == 0))
    return 0; // the string is empty

  if (likely(string->size != STRING_SIZE_UNKNOWN))
    return string->size;

  return strlen((char*)string->data);
}

size_t
string_length(const string_t* const string) {
  validate_with_errno_return(string != NULL);

#ifndef _CPRIME_HAVE_UTF8
  return string_size(string); // ASCII only
#else
#error UTF-8 support for string_length() has not yet been implemented.
#endif /* !_CPRIME_HAVE_UTF8 */
}

int
string_compare(const string_t* const string1, const string_t* const string2) {
  validate_with_errno_return(string1 != NULL && string2 != NULL);

  if (unlikely(string1 == string2))
    return 0;

  return strcmp((char*)string1->data, (char*)string2->data);
}

int
string_equal(const string_t* const string1, const string_t* const string2) {
  validate_with_errno_return(string1 != NULL && string2 != NULL);

  if (unlikely(string1 == string2))
    return TRUE;

  if (likely(string1->size != string2->size))
    return FALSE;

  return unlikely(strcmp((char*)string1->data, (char*)string2->data) == 0) ? TRUE : FALSE;
}

int
string_is_empty(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  if (unlikely(string->size == 0 || string->data == NULL))
    return TRUE;

  if (unlikely(*(string->data) == '\0'))
    return TRUE;

  return FALSE;
}

int
string_is_alnum(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_is_alpha(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_is_ascii(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_is_blank(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_is_cntrl(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_is_digit(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_is_graph(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_is_lower(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_is_print(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_is_punct(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_is_space(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_is_upper(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_is_xdigit(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  return FALSE; // TODO
}

int
string_has_prefix(const string_t* const string, const byte_t* const prefix) {
  validate_with_errno_return(string != NULL && prefix != NULL);

  if (unlikely(string_is_empty(string) == TRUE))
    return FALSE; // empty strings don't have prefixes

  const size_t string_sz = string_size(string);
  const size_t prefix_sz = strlen((char*)prefix);
  if (unlikely(string_sz < prefix_sz))
    return FALSE; // a string can't contain a prefix longer than itself

  const byte_t* string_data = string->data;
  return unlikely(strncmp((char*)string_data, (char*)prefix, prefix_sz) == 0) ? TRUE : FALSE;
}

int
string_has_suffix(const string_t* const string, const byte_t* const suffix) {
  validate_with_errno_return(string != NULL && suffix != NULL);

  if (unlikely(string_is_empty(string) == TRUE))
    return FALSE; // empty strings don't have suffixes

  const size_t string_sz = string_size(string);
  const size_t suffix_sz = strlen((char*)suffix);
  if (unlikely(string_sz < suffix_sz))
    return FALSE; // a string can't contain a suffix longer than itself

  const byte_t* string_data = string->data + string_sz - suffix_sz; // FIXME: UTF-8 support
  return unlikely(strncmp((char*)string_data, (char*)suffix, suffix_sz) == 0) ? TRUE : FALSE;
}

int
string_clear(string_t* string) {
  validate_with_errno_return(string != NULL);

  if (likely(string->data != NULL)) {
    free(string->data);
    string->data = NULL;
  }
  string->size = 0;

  return 0;
}

int
string_append_string(string_t* string, const string_t* const restrict suffix) {
  validate_with_errno_return(string != NULL && suffix != NULL);

  return string_append_bytes(string, suffix->data,
    unlikely(suffix->size == STRING_SIZE_UNKNOWN) ? -1 : suffix->size);
}

int
string_append_char(string_t* string, const char_t suffix) {
  validate_with_errno_return(string != NULL && suffix > 0);

  const byte_t bytes[2] = {suffix, '\0'}; // FIXME: UTF-8 support
  return string_append_bytes(string, bytes, sizeof(bytes) - 1);
}

int
string_append_bytes(string_t* string, const byte_t* const restrict suffix, const int suffix_size) {
  validate_with_errno_return(string != NULL && suffix != NULL && suffix_size >= -1);

  const size_t string_sz = string_size(string);
  const size_t suffix_sz = (suffix_size == -1) ? strlen((char*)suffix) : suffix_size;

  string->data = realloc(string->data, string_sz + suffix_sz + 1);

  bcopy(suffix, string->data + string_sz, suffix_sz);
  string->data[string_sz + suffix_sz] = '\0'; // terminate with null sentinel byte

  return suffix_sz;
}
