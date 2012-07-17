/* This is free and unencumbered software released into the public domain. */

#include "build.h"

static int
treeset_init(treeset_t* const restrict set, va_list args) {
  (void)set, (void)args;
  return FAILURE(ENOTSUP); // TODO
}

static int
treeset_dispose(treeset_t* const restrict set) {
  (void)set;
  return FAILURE(ENOTSUP); // TODO
}

static int
treeset_clear(treeset_t* const restrict set) {
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

public const class_t treeset_class = {
  .name    = "treeset",
  .super   = &set_class,
  .vtable  = &treeset_vtable.base,
};

public const set_vtable_t treeset_vtable = {
  .base    = {.klass = &treeset_class},
  .init    = treeset_init,
  .dispose = treeset_dispose,
  .clear   = treeset_clear,
  .count   = treeset_count,
  .lookup  = treeset_lookup,
  .insert  = treeset_insert,
  .remove  = treeset_remove,
  .replace = NULL,
};
