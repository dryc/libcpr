/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_LISTSET_H
#define _CPRIME_LISTSET_H

#ifdef __cplusplus
extern "C" {
#endif

static int
listset_init(set_t* const set, va_list args) {
  (void)args;
  set->instance = list_alloc();
  if (likely(set->instance != NULL)) {
    return list_init(set->instance);
  }
  return -errno;
}

static int
listset_reset(set_t* const set) {
  if (likely(set->instance != NULL)) {
    list_clear(set->instance);
    free(set->instance);
    set->instance = NULL;
  }
  return 0;
}

static int
listset_clear(set_t* const set) {
  return list_clear(set->instance);
}

static long
listset_count(set_t* const restrict set, const void* const restrict elt) {
  return likely(elt == NULL) ?
    list_length(set->instance) :
    list_count(set->instance, elt);
}

static bool
listset_lookup(set_t* const restrict set, const void* const restrict elt) {
  return (list_count(set->instance, elt) > 0) ? TRUE : FALSE;
}

static int
listset_insert(set_t* const restrict set, const void* const restrict elt) {
  (void)set, (void)elt;
  return -(errno = ENOTSUP); // TODO
}

static int
listset_remove(set_t* const restrict set, const void* const restrict elt) {
  (void)set, (void)elt;
  return -(errno = ENOTSUP); // TODO
}

static int
listset_replace(set_t* const restrict set, const void* const restrict elt1,
                                           const void* const restrict elt2) {
  (void)set, (void)elt1, (void)elt2;
  return -(errno = ENOTSUP); // TODO
}

const set_vtable_t listset = {
  .super   = NULL,
  .name    = "listset",
  .options = 0,
  .init    = listset_init,
  .reset   = listset_reset,
  .clear   = listset_clear,
  .count   = listset_count,
  .lookup  = listset_lookup,
  .insert  = listset_insert,
  .remove  = listset_remove,
  .replace = listset_replace,
};

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_LISTSET_H */
