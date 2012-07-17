/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_SET_ITER_H
#define CPRIME_SET_ITER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */
#include <stddef.h>  /* for size_t */
#include <stdint.h>  /* for uint64_t */

typedef struct set_iter {
  size_t position;
  uint64_t flags;
  set_t* set;
  void* elt;
  void* data;
} set_iter_t;

int set_iter_init(set_iter_t* iter,
  set_t* set);

int set_iter_dispose(set_iter_t* iter);

bool set_iter_next(set_iter_t* iter,
  void** elt);

int set_iter_remove(set_iter_t* iter);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_SET_ITER_H */
