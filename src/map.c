/* This is free and unencumbered software released into the public domain. */

#include "build.h"

public const class_t map_class = {
  .name    = "map",
  .super   = NULL,
  .vtable  = NULL, /* abstract class */
};

public map_t*
map_alloc() {
  return calloc(1, sizeof(map_t));
}

public void
map_free(map_t* const map) {
  validate_with_void_return(is_nonnull(map));
  map_dispose(map);
  free(map);
}

public int
map_init(map_t* const restrict map,
         const class_t* restrict klass,
         const hash_func_t hash_func,
         const compare_func_t compare_func,
         const free_func_t free_key_func,
         const free_func_t free_value_func, ...) {
  validate_with_errno_return(is_nonnull(map));

  const map_vtable_t* const vtable = is_nonnull(klass) ?
    (map_vtable_t*)klass->vtable : &hashmap_vtable;
  assert(is_nonnull(vtable));

  bzero(map, sizeof(map_t));

  map->vtable          = vtable;
  map->hash_func       = is_nonnull(hash_func)    ? hash_func    : ptr_hash;
  map->compare_func    = is_nonnull(compare_func) ? compare_func : ptr_compare;
  map->free_key_func   = free_key_func;
  map->free_value_func = free_value_func;

  if (is_nonnull(vtable->init)) {
    va_list args;
    va_start(args, free_value_func);
    const int rc = vtable->init(map, args);
    va_end(args);
    return rc;
  }

  return SUCCESS;
}

public int
map_dispose(map_t* const map) {
  validate_with_errno_return(is_nonnull(map));

  const map_vtable_t* const vtable = map->vtable;
  if (is_nonnull(vtable) && is_nonnull(vtable->dispose)) {
    return vtable->dispose(map);
  }

#ifndef NDEBUG
  bzero(map, sizeof(map_t));
#endif

  return SUCCESS;
}

public int
map_clear(map_t* const map) {
  validate_with_errno_return(is_nonnull(map));

  const map_vtable_t* const vtable = map->vtable;
  assert(is_nonnull(vtable));
  if (is_nonnull(vtable->clear)) {
    return vtable->clear(map);
  }

  return FAILURE(ENOTSUP); // operation not supported
}

public bool
map_is_empty(map_t* const map) {
  validate_with_true_return(is_nonnull(map));

  return unlikely(is_null(map->instance) || map_count((map_t*)map, NULL) == 0);
}

public long
map_count(map_t* const restrict map, const void* const restrict key) {
  validate_with_zero_return(is_nonnull(map));

  const map_vtable_t* const vtable = map->vtable;
  assert(is_nonnull(vtable));
  if (is_nonnull(vtable->count)) {
    return vtable->count(map, key);
  }

  return (void)FAILURE(ENOTSUP), 0; // operation not supported
}

public bool
map_lookup(map_t* const restrict map, const void* const restrict key,
                                      void** const restrict value) {
  validate_with_false_return(is_nonnull(map) && is_nonnull(key));

  const map_vtable_t* const vtable = map->vtable;
  assert(is_nonnull(vtable));
  if (is_nonnull(vtable->lookup)) {
    return vtable->lookup(map, key, value);
  }

  return (void)FAILURE(ENOTSUP), FALSE; // operation not supported
}

public int
map_insert(map_t* const restrict map, const void* const restrict key,
                                      const void* const restrict value) {
  validate_with_errno_return(is_nonnull(map) && is_nonnull(key));

  const map_vtable_t* const vtable = map->vtable;
  assert(is_nonnull(vtable));
  if (is_nonnull(vtable->insert)) {
    return vtable->insert(map, key, value);
  }

  return FAILURE(ENOTSUP); // operation not supported
}

public int
map_remove(map_t* const restrict map, const void* const restrict key) {
  validate_with_errno_return(is_nonnull(map) && is_nonnull(key));

  const map_vtable_t* const vtable = map->vtable;
  assert(is_nonnull(vtable));
  if (is_nonnull(vtable->remove)) {
    return vtable->remove(map, key);
  }

  return FAILURE(ENOTSUP); // operation not supported
}
