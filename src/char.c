/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <ctype.h>  /* for isascii(), etc. */
#include <stdlib.h> /* for calloc() */

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

int
char_hash(const char_t chr) {
  return (int)chr;
}

int
char_compare(const char_t chr1, const char_t chr2) {
  if (unlikely(chr1 == chr2))
    return 0;
  return likely(chr1 > chr2) ? 1 : -1;
}

int
char_equal(const char_t chr1, const char_t chr2) {
  return unlikely(chr1 == chr2) ? TRUE : FALSE;
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

int
char_encode(const char_t input, byte_t* output) {
  validate_with_errno_return(input <= 0x10FFFF);
  validate_with_errno_return(output != NULL);

  const byte_t* const start = output;
  UTF8_ENCODE(input, output);
  const byte_t* const end = output;

  const int size = (end - start);
  return size; // in bytes
}
