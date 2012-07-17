/* This is free and unencumbered software released into the public domain. */

#include "build.h"

static int
hashmap_init(hashmap_t* const restrict map, va_list args) {
  (void)map, (void)args;
  return FAILURE(ENOTSUP); // TODO
}

static int
hashmap_dispose(hashmap_t* const restrict map) {
  (void)map;
  return FAILURE(ENOTSUP); // TODO
}

static int
hashmap_clear(hashmap_t* const restrict map) {
  (void)map;
  return FAILURE(ENOTSUP); // TODO
}

static long
hashmap_count(hashmap_t* const restrict map,
              const void* const restrict key) {
  (void)map, (void)key;
  return (void)FAILURE(ENOTSUP), 0; // TODO
}

static bool
hashmap_lookup(hashmap_t* const restrict map,
               const void* const restrict key,
               void** const restrict value) {
  (void)map, (void)key, (void)value;
  return (void)FAILURE(ENOTSUP), FALSE; // TODO
}

static int
hashmap_insert(hashmap_t* const restrict map,
               const void* const restrict key,
               const void* const restrict value) {
  (void)map, (void)key, (void)value;
  return FAILURE(ENOTSUP); // TODO
}

static int
hashmap_remove(hashmap_t* const restrict map,
               const void* const restrict key) {
  (void)map, (void)key;
  return FAILURE(ENOTSUP); // TODO
}

public const class_t hashmap_class = {
  .name    = "hashmap",
  .super   = &map_class,
  .vtable  = &hashmap_vtable.base,
};

public const map_vtable_t hashmap_vtable = {
  .base    = {.klass = &hashmap_class},
  .init    = hashmap_init,
  .dispose = hashmap_dispose,
  .clear   = hashmap_clear,
  .count   = hashmap_count,
  .lookup  = hashmap_lookup,
  .insert  = hashmap_insert,
  .remove  = hashmap_remove,
};
