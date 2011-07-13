/* This is free and unencumbered software released into the public domain. */

#include "prelude.h"
#include "char.h"
#include <ctype.h>

int
char_hash(const char_t chr) {
  return (int)chr;
}
