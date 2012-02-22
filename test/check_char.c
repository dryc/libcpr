#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include "build.h"

static void
check_char_is_zero(void) {
  assert(char_is_zero('\0'));
  for (int c = 1; c <= 0xFF; c++)
    assert(!char_is_zero(c));
}

static void
check_char_is_alpha(void) {
  for (int c = 'A'; c <= 'Z'; c++)
    assert(char_is_alpha(c));
  for (int c = 'a'; c <= 'z'; c++)
    assert(char_is_alpha(c));
  for (int c = '0'; c <= '9'; c++)
    assert(!char_is_alpha(c));
}

static void
check_char_is_alnum(void) {
  for (int c = 'A'; c <= 'Z'; c++)
    assert(char_is_alnum(c));
  for (int c = 'a'; c <= 'z'; c++)
    assert(char_is_alnum(c));
  for (int c = '0'; c <= '9'; c++)
    assert(char_is_alnum(c));
}

static void
check_char_is_digit(void) {
  for (int c = '0'; c <= '9'; c++)
    assert(char_is_digit(c));
}

static void
check_char_is_ascii() {
  for (int c = 0; c <= 0x7F; c++)
    assert(char_is_ascii(c));
  for (int c = 0x80; c <= 0xFF; c++)
    assert(!char_is_ascii(c));
}

int
main(void) {
  check_char_is_zero();
  check_char_is_alpha();
  check_char_is_alnum();
  check_char_is_digit();
  check_char_is_ascii();
  return EXIT_SUCCESS;
}
