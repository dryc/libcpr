/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <stdlib.h> /* for calloc(), free(), malloc() */

const uuid_t uuid_zero = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

uuid_t*
uuid_alloc() {
  uuid_t* uuid = malloc(sizeof(uuid_t));
  uuid_init(uuid);
  return uuid;
}

int
uuid_init(uuid_t* uuid) {
  validate_with_errno_return(uuid != NULL);
  bzero(uuid, sizeof(uuid_t));
  return 0;
}

int
uuid_is_zero(const uuid_t* const uuid) {
  validate_with_errno_return(uuid != NULL);
  return unlikely(bcmp(uuid, &uuid_zero, sizeof(uuid_t)) == 0) ? TRUE : FALSE;
}
