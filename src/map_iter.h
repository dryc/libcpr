/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_MAP_ITER_H
#define CPRIME_MAP_ITER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */
#include <stddef.h>  /* for size_t */

typedef struct map_iter {
  size_t position;
  map_t* map;
  void* key;
  void* value;
  void* data;
} map_iter_t;

int map_iter_init(map_iter_t* iter,
  map_t* map);

int map_iter_dispose(map_iter_t* iter);

bool map_iter_next(map_iter_t* iter,
  void** key,
  void** value);

int map_iter_remove(map_iter_t* iter);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_MAP_ITER_H */
