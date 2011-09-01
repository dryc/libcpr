/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include "set/vectorset.h"
#include "set/listset.h"
#include "set/treeset.h"
#include "set/hashset.h"

set_t*
set_alloc() {
  return calloc(1, sizeof(set_t));
}

void
set_free(set_t* const set) {
  validate_with_void_return(set != NULL);
  set_reset(set);
  free(set);
}

int
set_init(set_t* const restrict set, const set_vtable_t* restrict vtable, ...) {
  validate_with_errno_return(set != NULL);

  bzero(set, sizeof(set_t));
  set->vtable = vtable = (vtable != NULL) ? vtable : NULL; // TODO

  if (likely(vtable->init != NULL)) {
    va_list args;
    va_start(args, vtable);
    const int rc = vtable->init(set, args);
    va_end(args);
    return rc;
  }

  return 0;
}

int
set_reset(set_t* const set) {
  validate_with_errno_return(set != NULL);

  const set_vtable_t* const vtable = set->vtable;
  if (likely(vtable->reset != NULL)) {
    return vtable->reset(set);
  }

  return 0;
}

int
set_clear(set_t* const set) {
  validate_with_errno_return(set != NULL);

  const set_vtable_t* const vtable = set->vtable;
  if (likely(vtable->clear != NULL)) {
    return vtable->clear(set);
  }

  return -(errno = ENOTSUP); // operation not supported
}

bool
set_is_empty(const set_t* const set) {
  validate_with_true_return(set != NULL);

  return unlikely(set->instance == NULL || set_count((set_t*)set, NULL) == 0);
}

long
set_count(set_t* const restrict set, const void* const restrict elt) {
  validate_with_zero_return(set != NULL);

  const set_vtable_t* const vtable = set->vtable;
  if (likely(vtable->count != NULL)) {
    return vtable->count(set, elt);
  }

  return (errno = ENOTSUP), 0; // operation not supported
}

bool
set_lookup(set_t* const restrict set, const void* const restrict elt) {
  validate_with_false_return(set != NULL && elt != NULL);

  const set_vtable_t* const vtable = set->vtable;
  if (likely(vtable->lookup != NULL)) {
    return vtable->lookup(set, elt);
  }

  return (errno = ENOTSUP), FALSE; // operation not supported
}

int
set_insert(set_t* const restrict set, const void* const restrict elt) {
  validate_with_errno_return(set != NULL && elt != NULL);

  const set_vtable_t* const vtable = set->vtable;
  if (likely(vtable->insert != NULL)) {
    return vtable->insert(set, elt);
  }

  return -(errno = ENOTSUP); // operation not supported
}

int
set_remove(set_t* const restrict set, const void* const restrict elt) {
  validate_with_errno_return(set != NULL && elt != NULL);

  const set_vtable_t* const vtable = set->vtable;
  if (likely(vtable->remove != NULL)) {
    return vtable->remove(set, elt);
  }

  return -(errno = ENOTSUP); // operation not supported
}

int
set_replace(set_t* const restrict set, const void* const restrict elt1,
                                       const void* const restrict elt2) {
  validate_with_errno_return(set != NULL && elt1 != NULL);

  const set_vtable_t* const vtable = set->vtable;
  if (likely(vtable->replace != NULL)) {
    return vtable->replace(set, elt1, elt2);
  }

  return -(errno = ENOTSUP); // operation not supported
}
