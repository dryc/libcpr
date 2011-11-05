/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_LISTSET_H_
#define _CPRIME_LISTSET_H_

#ifdef __cplusplus
extern "C" {
#endif

const class_t listset_class = {
  .name    = "listset",
  .super   = &set_class,
  .vtable  = &listset_vtable.base,
};

static int
listset_init(listset_t* const set, va_list args) {
  (void)args;
  set->instance = list_alloc();
  if (is_null(set->instance)) {
    return -errno; // pass on the error from list_alloc()
  }
  return list_init_with(set->instance, set->compare_func, set->free_func);
}

static int
listset_reset(listset_t* const set) {
  if (likely(set->instance != NULL)) {
    list_free(set->instance);
    set->instance = NULL;
  }
  return SUCCESS;
}

static int
listset_clear(listset_t* const set) {
  return list_clear(set->instance);
}

static long
listset_count(listset_t* const restrict set,
              const void* const restrict elt) {
  return likely(elt == NULL) ?
    list_length(set->instance) :
    (unlikely(list_lookup(set->instance, elt) == TRUE) ? 1 : 0);
}

static bool
listset_lookup(listset_t* const restrict set,
               const void* const restrict elt) {
  return list_lookup(set->instance, elt);
}

static int
listset_insert(listset_t* const restrict set,
               const void* const restrict elt) {
  if (unlikely(list_lookup(set->instance, elt) == TRUE)) {
    return FALSE; // the set already contains the element
  }
  return succeeded(list_prepend(set->instance, elt)) ? TRUE : -errno;
}

static int
listset_remove(listset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return FAILURE(ENOTSUP); // TODO
}

static int
listset_replace(listset_t* const restrict set,
                const void* const restrict elt1,
                const void* const restrict elt2) {
  (void)set, (void)elt1, (void)elt2;
  return FAILURE(ENOTSUP); // TODO
}

const set_vtable_t listset_vtable = {
  .base    = {.klass = &listset_class},
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
} /* extern "C" */
#endif

#endif /* _CPRIME_LISTSET_H_ */
