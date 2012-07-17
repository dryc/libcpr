/* This is free and unencumbered software released into the public domain. */

#include "build.h"

public int
map_iter_init(map_iter_t* const restrict iter,
              map_t* const restrict map) {
  (void)iter, (void)map;
  return FAILURE(ENOTSUP); // TODO
}

public int
map_iter_dispose(map_iter_t* const restrict iter) {
  (void)iter;
  return FAILURE(ENOTSUP); // TODO
}

public bool
map_iter_next(map_iter_t* const restrict iter,
              void** key,
              void** value) {
  (void)iter, (void)key, (void)value;
  return (void)FAILURE(ENOTSUP), FALSE; // TODO
}

public int
map_iter_remove(map_iter_t* const restrict iter) {
  (void)iter;
  return FAILURE(ENOTSUP); // TODO
}
