/* This is free and unencumbered software released into the public domain. */

#include "build.h"

int
once(once_t* guard, void (*function)(void)) {
  validate_with_errno_return(guard != NULL);

  const int rc = pthread_once(&guard->id, function);

  return likely(rc == 0) ? 0 : -(errno = rc);
}
