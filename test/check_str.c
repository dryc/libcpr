#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include "build.h"

static void
check_str_is_empty(void) {
  assert(str_is_empty(NULL));
  assert(str_is_empty(""));
}

static void
check_str_size(void) {
  assert(str_size(NULL) == 0);
  assert(str_size("") == 0);
}

static void
check_str_length(void) {
  assert(str_length(NULL) == 0);
  assert(str_length("") == 0);
}

static void
check_str_equal(void) {
  assert(str_equal("", ""));
}

int
main(void) {
  check_str_is_empty();
  check_str_size();
  check_str_length();
  check_str_equal();
  return EXIT_SUCCESS;
}
