#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include "build.h"

#define COUNT 1000

static void
check_uint32_sort(void) {
  uint32_t* const data = calloc(COUNT, sizeof(uint32_t));
  assert(is_nonnull(data));

  for (unsigned int i = 0; i < COUNT; i++) {
    data[i] = (uint32_t)rand();
  }

  uint32_sort(data, COUNT);

  {
    uint32_t previous = 0, current = 0;
    for (unsigned int i = 0; i < COUNT; i++) {
      current = data[i];
      assert(current >= previous);
      previous = current;
    }
  }

  free(data);
}

static void
check_uint64_sort(void) {
  uint64_t* const data = calloc(COUNT, sizeof(uint64_t));
  assert(is_nonnull(data));

  for (unsigned int i = 0; i < COUNT; i++) {
    data[i] = (uint64_t)rand();
  }

  uint64_sort(data, COUNT);

  {
    uint64_t previous = 0, current = 0;
    for (unsigned int i = 0; i < COUNT; i++) {
      current = data[i];
      assert(current >= previous);
      previous = current;
    }
  }

  free(data);
}

int
main(void) {
  check_uint32_sort();
  check_uint64_sort();
  return EXIT_SUCCESS;
}
