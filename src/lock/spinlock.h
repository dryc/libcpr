/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_SPINLOCK_H
#define CPRIME_SPINLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Spin locks.
 *
 * @see http://en.wikipedia.org/wiki/Spinlock
 */

#include <pthread.h> /* for pthread_spinlock_t */

extern const class_t spinlock_class;

typedef struct spinlock_t {
  pthread_spinlock_t id;
} spinlock_t;

extern spinlock_t* spinlock_alloc();
extern void spinlock_free(spinlock_t* spinlock);

#define SPINLOCK_INIT {.id = PTHREAD_SPINLOCK_INITIALIZER}

extern int spinlock_init(spinlock_t* spinlock);

extern int spinlock_dispose(spinlock_t* spinlock);

extern int spinlock_lock(spinlock_t* spinlock);
extern int spinlock_trylock(spinlock_t* spinlock);

extern int spinlock_unlock(spinlock_t* spinlock);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_SPINLOCK_H */
