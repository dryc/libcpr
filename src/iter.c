/* This is free and unencumbered software released into the public domain. */

#include "build.h"

iter_t*
iter_alloc() {
  iter_t* iter = malloc(sizeof(iter_t));
  //iter_init(iter);
  return iter;
}

void
iter_free(iter_t* iter) {
  if (likely(iter != NULL)) {
    //iter_dispose(iter);
    free(iter);
  }
}
