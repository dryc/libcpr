/* This is free and unencumbered software released into the public domain. */

#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include <cpr/feature.h>

////////////////////////////////////////////////////////////////////////////////

static void
test_exists(void) {
  assert(cpr_feature_exists("ascii"));   /* always present */
  assert(!cpr_feature_exists("foobar")); /* not present */
}

////////////////////////////////////////////////////////////////////////////////

int
main(void) {
  test_exists();
  return EXIT_SUCCESS;
}
