/* This is free and unencumbered software released into the public domain. */

#include "build.h"

public hash_t
nop_hash(const uint64_t n) {
  return n;
}

/**
 * @see http://burtleburtle.net/bob/hash/integer.html
 */
public hash_t
uint32_hash(uint32_t n) {
  n -= (n << 6);
  n ^= (n >> 17);
  n -= (n << 9);
  n ^= (n << 4);
  n -= (n << 3);
  n ^= (n << 10);
  n ^= (n >> 15);
  return (hash_t)n;
}

public int
uint32_compare(const uint32_t n1,
               const uint32_t n2) {
  if (unlikely(n1 == n2))
    return COMPARE_EQ;
  return (n1 < n2) ? COMPARE_LT : COMPARE_GT;
}

/**
 * @see http://www.cris.com/~Ttwang/tech/inthash.htm
 */
public hash_t
uint64_hash(uint64_t n) {
  n = (~n) + (n << 18);
  n ^= (n >> 31);
  n *= 21;
  n ^= (n >> 11);
  n += (n << 6);
  n ^= (n >> 22);
  return (hash_t)n;
}

public int
uint64_compare(const uint64_t n1,
               const uint64_t n2) {
  if (unlikely(n1 == n2))
    return COMPARE_EQ;
  return (n1 < n2) ? COMPARE_LT : COMPARE_GT;
}

public hash_t
ptr_hash(const void* const ptr) {
  if (sizeof(void*) == sizeof(uint64_t))
    return uint64_hash((uintptr_t)ptr);
  if (sizeof(void*) == sizeof(uint32_t))
    return uint32_hash((uintptr_t)ptr);
  return uint64_hash((uintptr_t)ptr);
}

public int
ptr_compare(const void* const ptr1, const void* const ptr2) {
  if (unlikely(ptr1 == ptr2))
    return COMPARE_EQ;
  return ((uintptr_t)ptr1 < (uintptr_t)ptr2) ? COMPARE_LT : COMPARE_GT;
}
