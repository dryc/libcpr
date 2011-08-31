/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include "set/listset.h"
#include "set/vectorset.h"
#include "set/treeset.h"
#include "set/hashset.h"

set_t*
set_alloc() {
  return calloc(1, sizeof(set_t));
}

void
set_free(set_t* const set) {
  validate_with_void_return(set != NULL);
  free(set);
}

int
set_init(set_t* const restrict set, const set_vtable_t* const restrict vtable) {
  validate_with_errno_return(set != NULL);

  (void)vtable;
  return -(errno = ENOTSUP); // TODO
}

bool
set_is_empty(const set_t* const set) {
  validate_with_true_return(set != NULL);

  return (errno = ENOTSUP), TRUE; // TODO
}

int
set_clear(set_t* const set) {
  validate_with_errno_return(set != NULL);

  return -(errno = ENOTSUP); // TODO
}

long
set_count(set_t* const restrict set, const void* const restrict elt) {
  validate_with_zero_return(set != NULL);

  (void)elt;
  return (errno = ENOTSUP), 0; // TODO
}

bool
set_lookup(set_t* const restrict set, const void* const restrict elt) {
  validate_with_false_return(set != NULL && elt != NULL);

  return (errno = ENOTSUP), FALSE; // TODO
}

int
set_insert(set_t* const restrict set, const void* const restrict elt) {
  validate_with_errno_return(set != NULL && elt != NULL);

  return -(errno = ENOTSUP); // TODO
}

int
set_remove(set_t* const restrict set, const void* const restrict elt) {
  validate_with_errno_return(set != NULL && elt != NULL);

  return -(errno = ENOTSUP); // TODO
}

int
set_replace(set_t* const restrict set, const void* const restrict elt1,
                                       const void* const restrict elt2) {
  validate_with_errno_return(set != NULL && elt1 != NULL);

  (void)elt2;
  return -(errno = ENOTSUP); // TODO
}
