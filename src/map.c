/* This is free and unencumbered software released into the public domain. */

#include "build.h"

int
map_init(map_t* const restrict map,
         const hash_func_t hash_func, const compare_func_t compare_func,
         const free_func_t free_key_func, const free_func_t free_value_func) {
  validate_with_errno_return(map != NULL);
  validate_with_errno_return(hash_func != NULL && compare_func != NULL);

  bzero(map, sizeof(map_t));

  map->hash_func       = hash_func;
  map->compare_func    = compare_func;
  map->free_key_func   = free_key_func;
  map->free_value_func = free_value_func;

  return 0;
}

bool
map_is_empty(map_t* const map) {
  validate_with_false_return(map != NULL);

  return unlikely(map->root == NULL) ? TRUE : FALSE;
}
