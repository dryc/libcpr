/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include "map/listmap.h"
#include "map/treemap.h"
#include "map/hashmap.h"

map_t*
map_alloc() {
  return calloc(1, sizeof(map_t));
}

void
map_free(map_t* const map) {
  validate_with_void_return(map != NULL);
  map_reset(map);
  free(map);
}

int
map_init(map_t* const restrict map,
         const map_vtable_t* restrict vtable,
         const hash_func_t hash_func,
         const compare_func_t compare_func,
         const free_func_t free_key_func,
         const free_func_t free_value_func, ...) {
  validate_with_errno_return(map != NULL);

  bzero(map, sizeof(map_t));

  map->vtable          = vtable = (vtable != NULL) ? vtable : LISTMAP;
  map->hash_func       = hash_func;
  map->compare_func    = compare_func;
  map->free_key_func   = free_key_func;
  map->free_value_func = free_value_func;

  if (likely(vtable->init != NULL)) {
    va_list args;
    va_start(args, free_value_func);
    const int rc = vtable->init(map, args);
    va_end(args);
    return rc;
  }

  return 0;
}

int
map_reset(map_t* const map) {
  validate_with_errno_return(map != NULL);

  const map_vtable_t* const vtable = map->vtable;
  if (likely(vtable->reset != NULL)) {
    return vtable->reset(map);
  }

  return 0;
}

int
map_clear(map_t* const map) {
  validate_with_errno_return(map != NULL);

  const map_vtable_t* const vtable = map->vtable;
  if (likely(vtable->clear != NULL)) {
    return vtable->clear(map);
  }

  return -(errno = ENOTSUP); // operation not supported
}

bool
map_is_empty(map_t* const map) {
  validate_with_true_return(map != NULL);

  return unlikely(map->instance == NULL || map_count((map_t*)map, NULL) == 0);
}

long
map_count(map_t* const restrict map, const void* const restrict key) {
  validate_with_zero_return(map != NULL);

  const map_vtable_t* const vtable = map->vtable;
  if (likely(vtable->count != NULL)) {
    return vtable->count(map, key);
  }

  return (errno = ENOTSUP), 0; // operation not supported
}

bool
map_lookup(map_t* const restrict map, const void* const restrict key,
                                      void** const restrict value) {
  validate_with_false_return(map != NULL && key != NULL);

  const map_vtable_t* const vtable = map->vtable;
  if (likely(vtable->lookup != NULL)) {
    return vtable->lookup(map, key, value);
  }

  return (errno = ENOTSUP), FALSE; // operation not supported
}

int
map_insert(map_t* const restrict map, const void* const restrict key,
                                      const void* const restrict value) {
  validate_with_errno_return(map != NULL && key != NULL);

  const map_vtable_t* const vtable = map->vtable;
  if (likely(vtable->insert != NULL)) {
    return vtable->insert(map, key, value);
  }

  return -(errno = ENOTSUP); // operation not supported
}

int
map_remove(map_t* const restrict map, const void* const restrict key) {
  validate_with_errno_return(map != NULL && key != NULL);

  const map_vtable_t* const vtable = map->vtable;
  if (likely(vtable->remove != NULL)) {
    return vtable->remove(map, key);
  }

  return -(errno = ENOTSUP); // operation not supported
}
