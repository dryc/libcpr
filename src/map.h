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
 * Checks whether a map contains any key-value pairs.
 */
extern bool map_is_empty(map_t* map);

/**
 * Returns the number of key-value pairs in a map.
 */
extern long map_count(map_t* restrict map,
  const void* restrict key);

/**
 * Looks up a key-value pair in a map.
 */
extern bool map_lookup(map_t* restrict map,
  const void* restrict key,
  void** restrict value);

/**
 * Removes all key-value pairs from a map.
 */
extern int map_clear(map_t* map);

/**
 * Inserts a key-value pair into a map.
 */
extern int map_insert(map_t* restrict map,
  const void* restrict key,
  const void* restrict value);

/**
 * Removes a key-value pair from a map.
 */
extern int map_remove(map_t* restrict map,
  const void* restrict key);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_MAP_H */
