/* This is free and unencumbered software released into the public domain. */

#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include <cpr/string.h>

static void
test_construct_empty(void) {
  cpr_string_t* string = cpr_string(NULL);
  assert(string != NULL);
  assert(cpr_string_empty(string));
  assert(cpr_string_size(string) == 0);
}

static void
test_construct_nonempty(void) {
  cpr_string_t* string = cpr_string("Hello, world!");
  assert(string != NULL);
  assert(!cpr_string_empty(string));
  assert(cpr_string_size(string) == 13);
}

int
main(void) {
  test_construct_empty();
  test_construct_nonempty();
  return EXIT_SUCCESS;
}
