/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_NULLMAP_H
#define _CPRIME_NULLMAP_H

#ifdef __cplusplus
extern "C" {
#endif

static int
nullmap_init(nullmap_t* const map, va_list args) {
  (void)map, (void)args;
  return SUCCESS;
}

static int
nullmap_reset(nullmap_t* const map) {
  (void)map;
  return SUCCESS;
}

static int
nullmap_clear(nullmap_t* const map) {
  (void)map;
  return SUCCESS;
}

static long
nullmap_count(nullmap_t* const restrict map,
              const void* const restrict key) {
  (void)map, (void)key;
  return 0; // the map is empty
}

static bool
nullmap_lookup(nullmap_t* const restrict map,
               const void* const restrict key,
               void** const restrict value) {
  (void)map, (void)key;
  if (is_nonnull(value)) {
    *value = NULL;
  }
  return FALSE; // key not found
}

static int
nullmap_insert(nullmap_t* const restrict map,
               const void* const restrict key,
               const void* const restrict value) {
  (void)map, (void)key, (void)value;
  return FAILURE(ENOTSUP); // operation not supported
}

static int
nullmap_remove(nullmap_t* const restrict map,
               const void* const restrict key) {
  (void)map, (void)key;
  return FAILURE(ENOTSUP); // operation not supported
}

/**
 * The canonical immutable empty map.
 */
const map_vtable_t nullmap_vtable = {
  .super   = NULL,
  .name    = "nullmap",
  .init    = nullmap_init,
  .reset   = nullmap_reset,
  .clear   = nullmap_clear,
  .count   = nullmap_count,
  .lookup  = nullmap_lookup,
  .insert  = nullmap_insert,
  .remove  = nullmap_remove,
};

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_NULLMAP_H */
