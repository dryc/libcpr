/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <inttypes.h> /* for strtoimax() */

string_t*
string_alloc() {
  string_t* string = malloc(sizeof(string_t));
  string_init_empty(string);
  return string;
}

void
string_free(string_t* string) {
  if (likely(string != NULL)) {
    string_dispose(string);
    free(string);
  }
}

string_t*
string_construct_with(const char* const data, const size_t size) {
  string_t* string = malloc(sizeof(string_t));
  string_init_with(string, data, size);
  return string;
}

string_t*
string_construct_with_data(const char* const data) {
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
string_init_with(string_t* string, const char* const data, const size_t size) {
  validate_with_errno_return(string != NULL);
  if (likely(size > 0 && size != STRING_SIZE_UNKNOWN))
    validate_with_errno_return(data != NULL);

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
  validate_with_errno_return(string != NULL);

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
  validate_with_errno_return(string != NULL);

  int result = string_init_empty(string);

  if (likely(size > 0 && size != STRING_SIZE_UNKNOWN)) {
    // Allocate sufficient memory for the string contents, including an
    // extra byte for the terminating null sentinel:
    string->data = calloc(size + 1, sizeof(char));
    string->size = size;

    if (unlikely(string->data == NULL))
      result = -errno; // insufficient memory (ENOMEM)
  }

  return result;
}

int
string_dispose(string_t* string) {
  validate_with_errno_return(string != NULL);

  if (likely(string->data != NULL)) {
    free(string->data);
    string->data = NULL;
  }
  string->size = 0;

  return 0;
}

size_t
string_size(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  if (unlikely(string->size == 0))
    return 0; // the string is empty

  if (likely(string->size != STRING_SIZE_UNKNOWN))
    return string->size;

  return strlen(string->data);
}

size_t
string_length(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  if (unlikely(string->data == NULL))
    return 0; // the string is empty

#ifdef DISABLE_UNICODE
  return string_size(string); // ASCII only
#else
  size_t length = 0;
  const char* data = string->data;
  while (likely(*data != '\0')) {
    length++;
    data = UTF8_SKIP_CHAR(data);
  }
  return length;
#endif /* DISABLE_UNICODE */
}

int
string_hash(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  if (unlikely(string->data == NULL))
    return 0; // the string is empty

  return str_hash(string->data);
}

int
string_compare(const string_t* const string1, const string_t* const string2) {
  validate_with_errno_return(string1 != NULL && string2 != NULL);

  if (unlikely(string1 == string2))
    return 0;

  return strcmp(string1->data, string2->data);
}

int
string_equal(const string_t* const string1, const string_t* const string2) {
  validate_with_errno_return(string1 != NULL && string2 != NULL);

  if (unlikely(string1 == string2))
    return TRUE;

  if (likely(string1->size != string2->size))
    return FALSE;

  return unlikely(strcmp(string1->data, string2->data) == 0) ? TRUE : FALSE;
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

static inline int
string_is(const string_t* const string, int (*predicate)(const char_t chr)) {
  validate_with_errno_return(string != NULL && predicate != NULL);

  const size_t size = string_size(string);
  for (size_t pos = 0; pos < size; pos++) {
    if (unlikely(predicate(string->data[pos]) != TRUE)) {
      return FALSE;
    }
  } // FIXME: for UTF-8

  return TRUE;
}

int
string_is_alnum(const string_t* const string) {
  return string_is(string, char_is_alnum);
}

int
string_is_alpha(const string_t* const string) {
  return string_is(string, char_is_alpha);
}

int
string_is_ascii(const string_t* const string) {
  validate_with_errno_return(string != NULL);

  const char* data = string->data;
  char c;
  while (likely((c = *data) != '\0')) {
    if (unlikely(!char_is_ascii(c)))
      return FALSE;
    data++;
  }
  return TRUE;
}

int
string_is_blank(const string_t* const string) {
  return string_is(string, char_is_blank);
}

int
string_is_cntrl(const string_t* const string) {
  return string_is(string, char_is_cntrl);
}

int
string_is_digit(const string_t* const string) {
  return string_is(string, char_is_digit);
}

int
string_is_graph(const string_t* const string) {
  return string_is(string, char_is_graph);
}

int
string_is_lower(const string_t* const string) {
  return string_is(string, char_is_lower);
}

int
string_is_print(const string_t* const string) {
  return string_is(string, char_is_print);
}

int
string_is_punct(const string_t* const string) {
  return string_is(string, char_is_punct);
}

int
string_is_space(const string_t* const string) {
  return string_is(string, char_is_space);
}

int
string_is_upper(const string_t* const string) {
  return string_is(string, char_is_upper);
}

int
string_is_xdigit(const string_t* const string) {
  return string_is(string, char_is_xdigit);
}

int
string_has_prefix(const string_t* const string, const char* const prefix) {
  validate_with_errno_return(string != NULL && prefix != NULL);

  if (unlikely(string_is_empty(string) == TRUE))
    return FALSE; // empty strings don't have prefixes

  const size_t string_sz = string_size(string);
  const size_t prefix_sz = strlen(prefix);
  if (unlikely(string_sz < prefix_sz))
    return FALSE; // a string can't contain a prefix longer than itself

  const char* string_data = string->data;
  return unlikely(strncmp(string_data, prefix, prefix_sz) == 0) ? TRUE : FALSE;
}

int
string_has_suffix(const string_t* const string, const char* const suffix) {
  validate_with_errno_return(string != NULL && suffix != NULL);

  if (unlikely(string_is_empty(string) == TRUE))
    return FALSE; // empty strings don't have suffixes

  const size_t string_sz = string_size(string);
  const size_t suffix_sz = strlen(suffix);
  if (unlikely(string_sz < suffix_sz))
    return FALSE; // a string can't contain a suffix longer than itself

  const char* string_data = string->data + string_sz - suffix_sz; // FIXME: UTF-8 support
  return unlikely(strncmp(string_data, suffix, suffix_sz) == 0) ? TRUE : FALSE;
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
    unlikely(suffix->size == STRING_SIZE_UNKNOWN) ? -1 : (int)suffix->size);
}

int
string_append_char(string_t* string, const char_t suffix) {
  validate_with_errno_return(string != NULL && suffix > 0);

#ifdef DISABLE_UNICODE
  validate_with_errno_return(suffix <= CHAR_MAX_ASCII);
  const char bytes[2] = {suffix, '\0'}; // ASCII only
#else
  validate_with_errno_return(suffix <= CHAR_MAX_UCS);
  const char bytes[2] = {suffix, '\0'}; // TODO: UTF-8 support
#endif /* DISABLE_UNICODE */

  return string_append_bytes(string, bytes, sizeof(bytes) - 1);
}

int
string_append_bytes(string_t* string, const char* const restrict suffix, const int suffix_size) {
  validate_with_errno_return(string != NULL && suffix != NULL && suffix_size >= -1);

  const size_t string_sz = string_size(string);
  const size_t suffix_sz = (suffix_size == -1) ? strlen(suffix) : (size_t)suffix_size;

  string->data = realloc(string->data, string_sz + suffix_sz + 1);

  bcopy(suffix, string->data + string_sz, suffix_sz);
  string->data[string_sz + suffix_sz] = '\0'; // terminate with null sentinel byte

  return suffix_sz;
}

int
string_to_intmax(const string_t* restrict string, intmax_t* const restrict result) {
  validate_with_errno_return(string != NULL && !string_is_empty(string));
  validate_with_errno_return(result != NULL);

  errno = 0;
  *result = strtoimax(string->data, NULL, 10);
  return -errno;
}
