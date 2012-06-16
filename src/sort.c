/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <stdlib.h> /* for qsort() */

static int
int32_compare(const int32_t* const restrict a,
              const int32_t* const restrict b) {
  if (*a < *b) return COMPARE_LT;
  if (*a > *b) return COMPARE_GT;
  return COMPARE_EQ;
}

static int
uint32_compare(const uint32_t* const restrict a,
               const uint32_t* const restrict b) {
  if (*a < *b) return COMPARE_LT;
  if (*a > *b) return COMPARE_GT;
  return COMPARE_EQ;
}

static int
int64_compare(const int64_t* const restrict a,
              const int64_t* const restrict b) {
  if (*a < *b) return COMPARE_LT;
  if (*a > *b) return COMPARE_GT;
  return COMPARE_EQ;
}

static int
uint64_compare(const uint64_t* const restrict a,
               const uint64_t* const restrict b) {
  if (*a < *b) return COMPARE_LT;
  if (*a > *b) return COMPARE_GT;
  return COMPARE_EQ;
}

public void
int32_sort(int32_t* const restrict data,
           const size_t count) {
  if (count <= 1) return;
  qsort(data, count, sizeof(int32_t), (compare_func_t)int32_compare);
}

public void
uint32_sort(uint32_t* const restrict data,
            const size_t count) {
  if (count <= 1) return;
  qsort(data, count, sizeof(uint32_t), (compare_func_t)uint32_compare);
}

public void
int64_sort(int64_t* const restrict data,
           const size_t count) {
  if (count <= 1) return;
  qsort(data, count, sizeof(int64_t), (compare_func_t)int64_compare);
}

public void
uint64_sort(uint64_t* const restrict data,
            const size_t count) {
  if (count <= 1) return;
  qsort(data, count, sizeof(uint64_t), (compare_func_t)uint64_compare);
}
