/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_LISTMAP_H
#define _CPRIME_LISTMAP_H

#ifdef __cplusplus
extern "C" {
#endif

static int
listmap_init(listmap_t* const map, va_list args) {
  (void)args;
  map->instance = list_alloc();
  if (unlikely(map->instance == NULL)) {
    return -errno;
  }
  return list_init(map->instance);
}

static int
listmap_reset(listmap_t* const map) {
  if (likely(map->instance != NULL)) {
    list_free(map->instance);
    map->instance = NULL;
  }
  return 0;
}

static int
listmap_clear(listmap_t* const map) {
  return list_clear(map->instance);
}

static long
listmap_count(listmap_t* const restrict map, const void* const restrict key) {
  (void)map, (void)key;
  return (errno = ENOTSUP), 0; // TODO
}

static bool
listmap_lookup(listmap_t* const restrict map, const void* const restrict key,
                                              void** const restrict value) {
  (void)map, (void)key, (void)value;
  return (errno = ENOTSUP), FALSE; // TODO
}

static int
listmap_insert(listmap_t* const restrict map, const void* const restrict key,
                                              const void* const restrict value) {
  (void)map, (void)key, (void)value;
  return -(errno = ENOTSUP); // TODO
}

static int
listmap_remove(listmap_t* const restrict map, const void* const restrict key) {
  (void)map, (void)key;
  return -(errno = ENOTSUP); // TODO
}

const map_vtable_t listmap = {
  .super   = NULL,
  .name    = "listmap",
  .options = 0,
  .init    = listmap_init,
  .reset   = listmap_reset,
  .clear   = listmap_clear,
  .count   = listmap_count,
  .lookup  = listmap_lookup,
  .insert  = listmap_insert,
  .remove  = listmap_remove,
};

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_LISTMAP_H */
