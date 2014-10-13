/* This is free and unencumbered software released into the public domain. */

#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include <cpr/module.h>

////////////////////////////////////////////////////////////////////////////////

static void
test_exists(void) {
  assert(cpr_module_exists("vector"));  /* likely present */
  assert(!cpr_module_exists("foobar")); /* not present */
}

////////////////////////////////////////////////////////////////////////////////

int
main(void) {
  test_exists();
  return EXIT_SUCCESS;
}
