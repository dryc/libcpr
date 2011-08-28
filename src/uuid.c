/* This is free and unencumbered software released into the public domain. */

#include "build.h"

const uuid_t uuid_zero = UUID_INIT;

uuid_t*
uuid_alloc() {
  uuid_t* uuid = malloc(sizeof(uuid_t));
  uuid_init(uuid);
  return uuid;
}

void
uuid_free(uuid_t* uuid) {
  if (likely(uuid != NULL)) {
    uuid_dispose(uuid);
    free(uuid);
  }
}

uuid_t*
uuid_clone(const uuid_t* uuid) {
  validate_with_null_return(uuid != NULL);

  uuid_t* copy = malloc(sizeof(uuid_t));
  if (likely(copy != NULL)) {
    bcopy(uuid, copy, sizeof(uuid_t));
  }
  return copy;
}

int
uuid_init(uuid_t* uuid) {
  validate_with_errno_return(uuid != NULL);

  bzero(uuid, sizeof(uuid_t));

  return 0;
}

int
uuid_dispose(uuid_t* uuid) {
  validate_with_errno_return(uuid != NULL);

#ifndef NDEBUG
  bzero(uuid, sizeof(uuid_t));
#endif

  return 0;
}

int
uuid_is_zero(const uuid_t* const uuid) {
  validate_with_errno_return(uuid != NULL);

  return unlikely(bcmp(uuid, &uuid_zero, sizeof(uuid_t)) == 0) ? TRUE : FALSE;
}
