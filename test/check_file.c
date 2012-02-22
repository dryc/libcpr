#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include "build.h"

static void
check_file_exists(void) {
  assert(file_exists(__FILE__));
}

int
main(void) {
  check_file_exists();
  return EXIT_SUCCESS;
}
