/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_HASH_H_
#define _CPRIME_HASH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> /* for UINT32_*, uint32_t, uint64_t */

#define HASH_MIN UINT32_MIN
#define HASH_MAX UINT32_MAX

typedef uint32_t hash_t;

/**
 * Calculates a hash code for the given 32-bit integer.
 */
extern hash_t uint32_hash(uint32_t n);

/**
 * Calculates a hash code for the given 64-bit integer.
 */
extern hash_t uint64_hash(uint64_t n);

/**
 * Calculates a hash code for the given pointer.
 */
extern hash_t ptr_hash(const void* ptr);
extern int ptr_compare(const void* ptr1, const void* ptr2);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CPRIME_HASH_H_ */
