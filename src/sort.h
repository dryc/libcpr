/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_SORT_H
#define CPRIME_SORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */
#include <stdint.h> /* for uint32_t, uint64_t */

/**
 * Sorts a vector of unsigned 32-bit integers.
 */
void uint32_sort(uint32_t* data, size_t count);

/**
 * Sorts a vector of unsigned 64-bit integers.
 */
void uint64_sort(uint64_t* data, size_t count);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_SORT_H */
