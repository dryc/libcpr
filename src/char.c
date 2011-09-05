/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <ctype.h> /* for isascii(), etc. */

char_t*
char_alloc() {
  return calloc(1, sizeof(char_t));
}

char_t*
char_construct(const char_t val) {
  char_t* ptr = char_alloc();
  if (likely(ptr != NULL))
    *ptr = val;
  return ptr;
}

char_t*
char_clone(const char_t* const ptr) {
  validate_with_null_return(ptr != NULL);
  return char_construct(*ptr);
}

hash_t
char_hash(const char_t chr) {
  return uint32_hash(chr);
}

int
char_compare(const char_t chr1, const char_t chr2) {
  if (unlikely(chr1 == chr2))
    return COMPARE_EQ;
  return (chr1 < chr2) ? COMPARE_LT : COMPARE_GT;
}

int
char_equal(const char_t chr1, const char_t chr2) {
  return unlikely(chr1 == chr2) ? TRUE : FALSE;
}

int
char_validate(const char_t chr) {
  return char_is_valid(chr);
}

int
char_is_valid(const char_t chr) {
#ifdef DISABLE_UNICODE
  return likely(chr <= CHAR_MAX_ASCII) ? TRUE : FALSE;
#else
  return likely(chr <= CHAR_MAX_UCS) ? TRUE : FALSE;
#endif
}

int
char_is_zero(const char_t chr) {
  return unlikely(chr == 0) ? TRUE : FALSE;
}

int
char_is_alnum(const char_t chr) {
  return likely(isalnum(chr) != 0) ? TRUE : FALSE;
}

int
char_is_alpha(const char_t chr) {
  return likely(isalpha(chr) != 0) ? TRUE : FALSE;
}

int
char_is_ascii(const char_t chr) {
  return likely(isascii(chr) != 0) ? TRUE : FALSE;
}

int
char_is_blank(const char_t chr) {
  return likely(isblank(chr) != 0) ? TRUE : FALSE;
}

int
char_is_cntrl(const char_t chr) {
  return likely(iscntrl(chr) != 0) ? TRUE : FALSE;
}

int
char_is_digit(const char_t chr) {
  return likely(isdigit(chr) != 0) ? TRUE : FALSE;
}

int
char_is_graph(const char_t chr) {
  return likely(isgraph(chr) != 0) ? TRUE : FALSE;
}

int
char_is_lower(const char_t chr) {
  return likely(islower(chr) != 0) ? TRUE : FALSE;
}

int
char_is_print(const char_t chr) {
  return likely(isprint(chr) != 0) ? TRUE : FALSE;
}

int
char_is_punct(const char_t chr) {
  return likely(ispunct(chr) != 0) ? TRUE : FALSE;
}

int
char_is_space(const char_t chr) {
  return likely(isspace(chr) != 0) ? TRUE : FALSE;
}

int
char_is_upper(const char_t chr) {
  return likely(isupper(chr) != 0) ? TRUE : FALSE;
}

int
char_is_xdigit(const char_t chr) {
  return likely(isxdigit(chr) != 0) ? TRUE : FALSE;
}

string_t*
char_to_string(const char_t chr) {
#ifdef DISABLE_UNICODE
  validate_with_null_return(chr <= CHAR_MAX_ASCII);

  string_t* string = string_construct_with_size(1);

  if (likely(string != NULL)) {
    *(string->data) = chr;
  }
#else
  validate_with_null_return(chr <= CHAR_MAX_UCS);

  string_t* string = string_construct_with_size(UTF8_LENGTH(chr));

  if (likely(string != NULL)) {
    UTF8_ENCODE(chr, string->data);
  }
#endif /* DISABLE_UNICODE */

  return string;
}

int
char_encode(const char_t input, byte_t* output) {
  validate_with_errno_return(output != NULL);

#ifdef DISABLE_UNICODE
  validate_with_errno_return(input <= CHAR_MAX_ASCII);

  *output++ = input;
  const int size = 1;
#else
  validate_with_errno_return(input <= CHAR_MAX_UCS);

  const byte_t* const start = output;
  UTF8_ENCODE(input, output);
  const byte_t* const end = output;
  const int size = (end - start);
#endif /* DISABLE_UNICODE */

  return size; // in bytes
}
