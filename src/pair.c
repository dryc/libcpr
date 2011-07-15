/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <stdlib.h> /* for calloc(), free(), malloc() */

pair_t*
pair_alloc() {
  return calloc(1, sizeof(pair_t));
}

pair_t*
pair_construct_with(const void* const head, const pair_t* const tail) {
  pair_t* pair = malloc(sizeof(pair_t));
  pair_init_with(pair, head, tail);
  return pair;
}

int
pair_init_empty(pair_t* pair) {
  validate_with_errno_return(pair != NULL);

  bzero(pair, sizeof(pair_t));

  return 0;
}

int
pair_init_with(pair_t* pair, const void* const head, const pair_t* const tail) {
  const int result = pair_init_empty(pair);

  if (likely(succeeded(result))) {
    pair->head = (void*)head;
    pair->tail = (pair_t*)tail;
  }

  return result;
}
