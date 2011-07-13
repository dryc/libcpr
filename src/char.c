/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <ctype.h>

int
char_hash(const char_t chr) {
  return (int)chr;
}

int
char_equal(const char_t chr1, const char_t chr2) {
  return (chr1 == chr2);
}
