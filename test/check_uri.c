#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include "build.h"

static void
check_uri_validate(void) {
  assert(!uri_validate(NULL));
  assert(!uri_validate(""));
  assert(uri_validate("http://example.org/"));
  assert(uri_validate("https://example.org/"));
  assert(uri_validate("ftp://example.org/"));
  assert(uri_validate("mailto:jhacker@example.org"));
}

int
main(void) {
  check_uri_validate();
  return EXIT_SUCCESS;
}
