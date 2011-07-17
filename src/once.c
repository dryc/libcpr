/* This is free and unencumbered software released into the public domain. */

#include "build.h"

int
once(once_t* guard, void (*function)(void)) {
  validate_with_errno_return(guard != NULL);

#ifdef HAVE_PTHREAD_ONCE
  const int rc = pthread_once(&guard->id, function);
#else
  const int rc = ENOTSUP; // operation not supported
#endif

  return likely(rc == 0) ? 0 : -(errno = rc);
}
