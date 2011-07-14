/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <stdlib.h> /* for calloc() */

list_t*
list_alloc() {
  return calloc(1, sizeof(list_t));
}

int
list_is_empty(const list_t* const list) {
  return unlikely(list->first == NULL) ? TRUE : FALSE;
}
