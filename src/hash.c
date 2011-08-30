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
