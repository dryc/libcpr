/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_HASH_H
#define CPRIME_HASH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> /* for UINT32_*, uint32_t, uint64_t */

#define HASH_MIN UINT32_MIN
#define HASH_MAX UINT32_MAX

typedef uint32_t hash_t;

hash_t nop_hash(uint64_t n);

/**
 * Calculates a hash code for the given 32-bit integer.
 */
hash_t uint32_hash(uint32_t n);

/**
 * Calculates a hash code for the given 64-bit integer.
 */
hash_t uint64_hash(uint64_t n);

/**
 * Calculates a hash code for the given pointer.
 */
hash_t ptr_hash(const void* ptr);

int uint32_compare(uint32_t n1, uint32_t n2);
int uint64_compare(uint64_t n1, uint64_t n2);
int ptr_compare(const void* ptr1, const void* ptr2);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_HASH_H */
