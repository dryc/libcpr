#include <assert.h> /* for assert() */
#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for EXIT_SUCCESS */

#include "build.h"

#define COUNT 1000

static void
check_int32_sort(void) {
  int32_t* const data = calloc(COUNT, sizeof(int32_t));
  assert(is_nonnull(data));

  for (unsigned int i = 0; i < COUNT; i++) {
    data[i] = (int32_t)rand() * (rand() % 2 ? 1 : -1);
  }

  int32_sort(data, COUNT);

  {
    int32_t previous = INT32_MIN;
    int32_t current;
    for (unsigned int i = 0; i < COUNT; i++) {
      current = data[i];
      assert(current >= previous);
      previous = current;
    }
  }

  free(data);
}

static void
check_uint32_sort(void) {
  uint32_t* const data = calloc(COUNT, sizeof(uint32_t));
  assert(is_nonnull(data));

  for (unsigned int i = 0; i < COUNT; i++) {
    data[i] = (uint32_t)rand();
  }

  uint32_sort(data, COUNT);

  {
    uint32_t previous = 0;
    uint32_t current;
    for (unsigned int i = 0; i < COUNT; i++) {
      current = data[i];
      assert(current >= previous);
      previous = current;
    }
  }

  free(data);
}

static void
check_int64_sort(void) {
  int64_t* const data = calloc(COUNT, sizeof(int64_t));
  assert(is_nonnull(data));

  for (unsigned int i = 0; i < COUNT; i++) {
    data[i] = (int64_t)rand() * (rand() % 2 ? 1 : -1);
  }

  int64_sort(data, COUNT);

  {
    int64_t previous = INT64_MIN;
    int64_t current;
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
    uint64_t previous = 0;
    uint64_t current;
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
  check_int32_sort();
  check_uint32_sort();
  check_int64_sort();
  check_uint64_sort();
  return EXIT_SUCCESS;
}
