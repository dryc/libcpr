/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_TREESET_H_
#define _CPRIME_TREESET_H_

#ifdef __cplusplus
extern "C" {
#endif

const class_t treeset_class = {
  .name    = "treeset",
  .super   = &set_class,
  .vtable  = &treeset_vtable.base,
};

static int
treeset_init(treeset_t* const set, va_list args) {
  (void)set, (void)args;
  return FAILURE(ENOTSUP); // TODO
}

static int
treeset_reset(treeset_t* const set) {
  (void)set;
  return FAILURE(ENOTSUP); // TODO
}

static int
treeset_clear(treeset_t* const set) {
  (void)set;
  return FAILURE(ENOTSUP); // TODO
}

static long
treeset_count(treeset_t* const restrict set,
              const void* const restrict elt) {
  (void)set, (void)elt;
  return (void)FAILURE(ENOTSUP), 0; // TODO
}

static bool
treeset_lookup(treeset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return (void)FAILURE(ENOTSUP), FALSE; // TODO
}

static int
treeset_insert(treeset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return FAILURE(ENOTSUP); // TODO
}

static int
treeset_remove(treeset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return FAILURE(ENOTSUP); // TODO
}

static int
treeset_replace(treeset_t* const restrict set,
                const void* const restrict elt1,
                const void* const restrict elt2) {
  (void)set, (void)elt1, (void)elt2;
  return FAILURE(ENOTSUP); // TODO
}

const set_vtable_t treeset_vtable = {
  .base    = {.klass = &treeset_class},
  .init    = treeset_init,
  .reset   = treeset_reset,
  .clear   = treeset_clear,
  .count   = treeset_count,
  .lookup  = treeset_lookup,
  .insert  = treeset_insert,
  .remove  = treeset_remove,
  .replace = treeset_replace,
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CPRIME_TREESET_H_ */
