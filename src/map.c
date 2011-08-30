/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include "map/int_map.h"
#include "map/hash_map.h"

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

long
map_count(map_t* const restrict map, const void* const restrict key) {
  validate_with_zero_return(map != NULL);

  (void)key;
  return (errno = ENOTSUP), 0; // TODO
}

bool
map_lookup(map_t* const restrict map, const void* const restrict key,
                                      void** const restrict value) {
  validate_with_false_return(map != NULL && key != NULL);

  (void)value;
  return (errno = ENOTSUP), FALSE; // TODO
}

int
map_clear(map_t* const restrict map) {
  validate_with_errno_return(map != NULL);

  return -(errno = ENOTSUP); // TODO
}

int
map_insert(map_t* const restrict map, const void* const restrict key,
                                      const void* const restrict value) {
  validate_with_errno_return(map != NULL && key != NULL);

  (void)value;
  return -(errno = ENOTSUP); // TODO
}

int
map_remove(map_t* const restrict map, const void* const restrict key) {
  validate_with_errno_return(map != NULL && key != NULL);

  return -(errno = ENOTSUP); // TODO
}
