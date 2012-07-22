#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include "build.h"

static void
test_uint32_compare(void) {
  assert(uint32_compare(0, 0) == COMPARE_EQ);
  assert(uint32_compare(0, 1) <= COMPARE_LT);
  assert(uint32_compare(1, 0) >= COMPARE_GT);
  assert(uint32_compare(0, UINT32_MAX) <= COMPARE_LT);
  assert(uint32_compare(UINT32_MAX, 0) >= COMPARE_GT);
}

static void
test_uint64_compare(void) {
  assert(uint64_compare(0, 0) == COMPARE_EQ);
  assert(uint64_compare(0, 1) <= COMPARE_LT);
  assert(uint64_compare(1, 0) >= COMPARE_GT);
  assert(uint64_compare(0, UINT64_MAX) <= COMPARE_LT);
  assert(uint64_compare(UINT64_MAX, 0) >= COMPARE_GT);
}

int
main(void) {
  test_uint32_compare();
  test_uint64_compare();
  return EXIT_SUCCESS;
}
