/* This is free and unencumbered software released into the public domain. */

#include "build.h"

static int
vectset_init(vectset_t* const restrict set, va_list args) {
  (void)set, (void)args;
  return FAILURE(ENOTSUP); // TODO
}

static int
vectset_dispose(vectset_t* const restrict set) {
  (void)set;
  return FAILURE(ENOTSUP); // TODO
}

static int
vectset_clear(vectset_t* const restrict set) {
  (void)set;
  return FAILURE(ENOTSUP); // TODO
}

static long
vectset_count(vectset_t* const restrict set,
              const void* const restrict elt) {
  (void)set, (void)elt;
  return (void)FAILURE(ENOTSUP), 0; // TODO
}

static bool
vectset_lookup(vectset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return (void)FAILURE(ENOTSUP), FALSE; // TODO
}

static int
vectset_insert(vectset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return FAILURE(ENOTSUP); // TODO
}

static int
vectset_remove(vectset_t* const restrict set,
               const void* const restrict elt) {
  (void)set, (void)elt;
  return FAILURE(ENOTSUP); // TODO
}

public const class_t vectset_class = {
  .name    = "vectset",
  .super   = &set_class,
  .vtable  = &vectset_vtable.base,
};

public const set_vtable_t vectset_vtable = {
  .base    = {.klass = &vectset_class},
  .init    = vectset_init,
  .dispose = vectset_dispose,
  .clear   = vectset_clear,
  .count   = vectset_count,
  .lookup  = vectset_lookup,
  .insert  = vectset_insert,
  .remove  = vectset_remove,
  .replace = NULL,
};
