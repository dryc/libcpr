/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_LISTMAP_H
#define CPRIME_LISTMAP_H

#ifdef __cplusplus
extern "C" {
#endif

const class_t listmap_class = {
  .name    = "listmap",
  .super   = &map_class,
  .vtable  = &listmap_vtable.base,
};

static int
listmap_init(listmap_t* const map, va_list args) {
  (void)args;
  map->instance = list_alloc();
  if (is_null(map->instance)) {
    return -errno; // pass on the error from list_alloc()
  }
  return list_init_with(map->instance, map->compare_func, free);
}

static int
listmap_dispose(listmap_t* const map) {
  if (likely(map->instance != NULL)) {
    list_free(map->instance);
    map->instance = NULL;
  }
  return SUCCESS;
}

static int
listmap_clear(listmap_t* const map) {
  return list_clear(map->instance);
}

static long
listmap_count(listmap_t* const restrict map,
              const void* const restrict key) {
  (void)map, (void)key;
  return (void)FAILURE(ENOTSUP), 0; // TODO
}

static bool
listmap_lookup(listmap_t* const restrict map,
               const void* const restrict key,
               void** const restrict value) {
  (void)map, (void)key, (void)value;
  return (void)FAILURE(ENOTSUP), FALSE; // TODO
}

static int
listmap_insert(listmap_t* const restrict map,
               const void* const restrict key,
               const void* const restrict value) {
  (void)map, (void)key, (void)value;
  return FAILURE(ENOTSUP); // TODO
}

static int
listmap_remove(listmap_t* const restrict map,
               const void* const restrict key) {
  (void)map, (void)key;
  return FAILURE(ENOTSUP); // TODO
}

const map_vtable_t listmap_vtable = {
  .base    = {.klass = &listmap_class},
  .init    = listmap_init,
  .dispose = listmap_dispose,
  .clear   = listmap_clear,
  .count   = listmap_count,
  .lookup  = listmap_lookup,
  .insert  = listmap_insert,
  .remove  = listmap_remove,
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_LISTMAP_H */
