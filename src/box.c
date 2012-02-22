/* This is free and unencumbered software released into the public domain. */

#include "build.h"

public const class_t box_class = {
  .name    = "box",
  .super   = NULL,
  .vtable  = NULL, /* abstract class */
};

public box_t*
box_alloc() {
#ifdef NDEBUG
  return malloc(sizeof(box_t));
#else
  return calloc(1, sizeof(box_t));
#endif
}

public void
box_free(box_t* const box) {
  validate_with_void_return(is_nonnull(box));
  box_reset(box);
  free(box);
}

public int
box_init(box_t* const restrict box,
         const box_vtable_t* const restrict vtable, ...) {
  validate_with_errno_return(is_nonnull(box) && is_nonnull(vtable));

  bzero(box, sizeof(box_t));

  box->vtable = vtable;

  if (is_nonnull(vtable->init)) {
    va_list args;
    va_start(args, vtable);
    const int rc = vtable->init(box, args);
    va_end(args);
    return rc;
  }

  return SUCCESS;
}

public int
box_reset(box_t* const box) {
  validate_with_errno_return(is_nonnull(box));

  const box_vtable_t* const vtable = box->vtable;
  if (is_nonnull(vtable->reset)) {
    return vtable->reset(box);
  }

#ifndef NDEBUG
  bzero(box, sizeof(box_t));
#endif

  return SUCCESS;
}

public int
box_clear(box_t* const box) {
  validate_with_errno_return(is_nonnull(box));

  const box_vtable_t* const vtable = box->vtable;
  if (is_nonnull(vtable->clear)) {
    return vtable->clear(box);
  }

  // The default implementation here presupposes that a cleared value has an
  // all-zeroes bit string representation, which is typically the case:
  bzero(&box->value, sizeof(&box->value));

  return SUCCESS;
}

public long
box_size(const box_t* const box) {
  validate_with_zero_return(is_nonnull(box));

  const box_vtable_t* const vtable = box->vtable;
  return vtable->klass->size;
}

public hash_t
box_hash(const box_t* const box) {
  validate_with_zero_return(is_nonnull(box));

  const box_vtable_t* const vtable = box->vtable;
  if (is_nonnull(vtable->hashable.hash)) {
    return vtable->hashable.hash(box);
  }

  return (void)FAILURE(ENOTSUP), 0;
}

public int
box_compare(const box_t* const box1, const box_t* const box2) {
  validate_with_errno_return(is_nonnull(box1) && is_nonnull(box2));

  if (unlikely(box1 == box2))
    return COMPARE_EQ;

  const box_vtable_t* const vtable = box1->vtable;
  if (is_nonnull(vtable->comparable.compare)) {
    return vtable->comparable.compare(box1, box2);
  }

  return FAILURE(ENOTSUP);
}

public bool
box_equal(const box_t* const box1, const box_t* const box2) {
  validate_with_false_return(is_nonnull(box1) && is_nonnull(box2));

  if (unlikely(box1 == box2))
    return TRUE;

  const box_vtable_t* const vtable = box1->vtable;
  if (is_nonnull(vtable->comparable.compare)) {
    return (vtable->comparable.compare(box1, box2) == 0);
  }

  return (void)FAILURE(ENOTSUP), FALSE;
}
