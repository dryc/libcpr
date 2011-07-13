/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <stdlib.h> /* for calloc() */

list_t*
list_allocate() {
  return calloc(1, sizeof(list_t));
}
