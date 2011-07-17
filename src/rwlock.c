/* This is free and unencumbered software released into the public domain. */

#include "build.h"

rwlock_t*
rwlock_alloc() {
  rwlock_t* rwlock = malloc(sizeof(rwlock_t));
  rwlock_init(rwlock);
  return rwlock;
}

void
rwlock_free(rwlock_t* rwlock) {
  if (likely(rwlock != NULL)) {
    rwlock_dispose(rwlock);
    free(rwlock);
  }
}

int
rwlock_init(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

#ifndef DEBUG
  bzero(rwlock, sizeof(rwlock_t));
#endif

  const int rc = pthread_rwlock_init(&rwlock->id, NULL);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
rwlock_dispose(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

  const int rc = pthread_rwlock_destroy(&rwlock->id);

#ifndef NDEBUG
  bzero(rwlock, sizeof(rwlock_t));
#endif

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
rwlock_rdlock(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

  const int rc = pthread_rwlock_rdlock(&rwlock->id);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
rwlock_tryrdlock(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

  const int rc = pthread_rwlock_tryrdlock(&rwlock->id);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
rwlock_wrlock(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

  const int rc = pthread_rwlock_wrlock(&rwlock->id);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
rwlock_trywrlock(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

  const int rc = pthread_rwlock_trywrlock(&rwlock->id);

  return likely(rc == 0) ? 0 : -(errno = rc);
}

int
rwlock_unlock(rwlock_t* rwlock) {
  validate_with_errno_return(rwlock != NULL);

  const int rc = pthread_rwlock_unlock(&rwlock->id);

  return likely(rc == 0) ? 0 : -(errno = rc);
}
