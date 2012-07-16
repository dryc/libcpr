/* This is free and unencumbered software released into the public domain. */

#include "build.h"

public int
set_iter_init(set_iter_t* const restrict iter,
              set_t* const restrict set) {
  (void)iter, (void)set;
  return FAILURE(ENOTSUP); // TODO
}

public int
set_iter_dispose(set_iter_t* const restrict iter) {
  (void)iter;
  return FAILURE(ENOTSUP); // TODO
}

public bool
set_iter_next(set_iter_t* const restrict iter,
              void** elt) {
  (void)iter, (void)elt;
  return (void)FAILURE(ENOTSUP), FALSE; // TODO
}

public int
set_iter_remove(set_iter_t* const restrict iter) {
  (void)iter;
  return FAILURE(ENOTSUP); // TODO
}
