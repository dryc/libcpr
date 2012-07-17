/* This is free and unencumbered software released into the public domain. */

#include "build.h"

static int
nullset_init(nullset_t* const restrict set, va_list args) {
  (void)set, (void)args;
  return SUCCESS;
}

static int
nullset_dispose(nullset_t* const restrict set) {
  (void)set;
  return SUCCESS;
}

static int
nullset_clear(nullset_t* const restrict set) {
  (void)set;
  return SUCCESS;
}

static long
nullset_count(nullset_t* const restrict set,
              const void* const restrict elt) {
  (void)set, (void)elt;
  return 0; /* the set is empty */
}

static bool
nullset_lookup(nullset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return FALSE; /* element not found */
}

static int
nullset_insert(nullset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return FAILURE(ENOTSUP); /* operation not supported */
}

static int
nullset_remove(nullset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return FAILURE(ENOTSUP); /* operation not supported */
}

static int
nullset_replace(nullset_t* const restrict set,
                const void* const restrict elt1,
                const void* const restrict elt2) {
  (void)set, (void)elt1, (void)elt2;
  return FAILURE(ENOTSUP); /* operation not supported */
}

public const class_t nullset_class = {
  .name    = "nullset",
  .super   = &set_class,
  .vtable  = &nullset_vtable.base,
};

public const set_vtable_t nullset_vtable = {
  .base    = {.klass = &nullset_class},
  .init    = nullset_init,
  .dispose = nullset_dispose,
  .clear   = nullset_clear,
  .count   = nullset_count,
  .lookup  = nullset_lookup,
  .insert  = nullset_insert,
  .remove  = nullset_remove,
  .replace = nullset_replace,
};

/**
 * The canonical immutable empty set.
 */
