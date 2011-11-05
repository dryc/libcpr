/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_RWLOCK_H_
#define _CPRIME_RWLOCK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h> /* for pthread_rwlock_t */

extern const class_t rwlock_class;

typedef struct rwlock_t {
  pthread_rwlock_t id;
} rwlock_t;

extern rwlock_t* rwlock_alloc();
extern void rwlock_free(rwlock_t* rwlock);

#define RWLOCK_INIT {.id = PTHREAD_RWLOCK_INITIALIZER}

extern int rwlock_init(rwlock_t* rwlock);

extern int rwlock_dispose(rwlock_t* rwlock);

extern int rwlock_rdlock(rwlock_t* rwlock);
extern int rwlock_tryrdlock(rwlock_t* rwlock);

extern int rwlock_wrlock(rwlock_t* rwlock);
extern int rwlock_trywrlock(rwlock_t* rwlock);

extern int rwlock_unlock(rwlock_t* rwlock);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CPRIME_RWLOCK_H_ */
