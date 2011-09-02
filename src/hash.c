/* This is free and unencumbered software released into the public domain. */

#include "build.h"

/**
 * @see http://burtleburtle.net/bob/hash/integer.html
 */
hash_t
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

/**
 * @see http://www.cris.com/~Ttwang/tech/inthash.htm
 */
hash_t
uint64_hash(uint64_t n) {
  n = (~n) + (n << 18);
  n ^= (n >> 31);
  n *= 21;
  n ^= (n >> 11);
  n += (n << 6);
  n ^= (n >> 22);
  return (hash_t)n;
}

hash_t
ptr_hash(const void* const ptr) {
  if (sizeof(void*) == sizeof(uint64_t))
    return uint64_hash((uintptr_t)ptr);
  if (sizeof(void*) == sizeof(uint32_t))
    return uint32_hash((uintptr_t)ptr);
  return uint64_hash((uintptr_t)ptr);
}

int
ptr_compare(const void* const ptr1, const void* const ptr2) {
  if (unlikely(ptr1 == ptr2))
    return 0;
  return ((uintptr_t)ptr1 < (uintptr_t)ptr2) ? -1 : 1;
}
