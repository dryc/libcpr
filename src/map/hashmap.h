/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_HASHMAP_H
#define _CPRIME_HASHMAP_H

#ifdef __cplusplus
extern "C" {
#endif

static int
hashmap_init(hashmap_t* const map, va_list args) {
  (void)map, (void)args;
  return -(errno = ENOTSUP); // TODO
}

static int
hashmap_reset(hashmap_t* const map) {
  (void)map;
  return -(errno = ENOTSUP); // TODO
}

static int
hashmap_clear(hashmap_t* const map) {
  (void)map;
  return -(errno = ENOTSUP); // TODO
}

static long
hashmap_count(hashmap_t* const restrict map,
              const void* const restrict key) {
  (void)map, (void)key;
  return (errno = ENOTSUP), 0; // TODO
}

static bool
hashmap_lookup(hashmap_t* const restrict map,
               const void* const restrict key,
               void** const restrict value) {
  (void)map, (void)key, (void)value;
  return (errno = ENOTSUP), FALSE; // TODO
}

static int
hashmap_insert(hashmap_t* const restrict map,
               const void* const restrict key,
               const void* const restrict value) {
  (void)map, (void)key, (void)value;
  return -(errno = ENOTSUP); // TODO
}

static int
hashmap_remove(hashmap_t* const restrict map,
               const void* const restrict key) {
  (void)map, (void)key;
  return -(errno = ENOTSUP); // TODO
}

const map_vtable_t hashmap = {
  .super   = NULL,
  .name    = "hashmap",
  .options = 0,
  .init    = hashmap_init,
  .reset   = hashmap_reset,
  .clear   = hashmap_clear,
  .count   = hashmap_count,
  .lookup  = hashmap_lookup,
  .insert  = hashmap_insert,
  .remove  = hashmap_remove,
};

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_HASHMAP_H */
