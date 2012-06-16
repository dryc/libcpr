/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <stdlib.h> /* for qsort() */

static int
uint32_compare(const uint32_t* const restrict a,
               const uint32_t* const restrict b) {
  if (*a < *b) return COMPARE_LT;
  if (*a > *b) return COMPARE_GT;
  return COMPARE_EQ;
}

public void
uint32_sort(uint32_t* const restrict data,
            const size_t count) {
  if (count <= 1) return;
  qsort(data, count, sizeof(uint32_t), (compare_func_t)uint32_compare);
}

static int
uint64_compare(const uint64_t* const restrict a,
               const uint64_t* const restrict b) {
  if (*a < *b) return COMPARE_LT;
  if (*a > *b) return COMPARE_GT;
  return COMPARE_EQ;
}

public void
uint64_sort(uint64_t* const restrict data,
            const size_t count) {
  if (count <= 1) return;
  qsort(data, count, sizeof(uint64_t), (compare_func_t)uint64_compare);
}
