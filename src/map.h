/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_MAP_H
#define _CPRIME_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */

typedef struct map_t {
  void* root;
  hash_func_t hash_func;
  compare_func_t compare_func;
  free_func_t free_key_func;
  free_func_t free_value_func;
} map_t;

/**
 * Initializes a map.
 */
extern int map_init(map_t* restrict map,
  hash_func_t hash_func,
  compare_func_t compare_func,
  free_func_t free_key_func,
  free_func_t free_value_func);

/**
 * Returns `TRUE` if the map contains no key-value pairs.
 */
extern bool map_is_empty(map_t* map);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_MAP_H */
