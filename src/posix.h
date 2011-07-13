/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_POSIX_H
#define _CPRIME_POSIX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h>  /* for ssize_t */
#include <poll.h>    /* for pollfd, nfds_t */
#include <pthread.h> /* for pthread_t, pthread_attr_t */

extern int posix_close(const int fd);
extern ssize_t posix_write(const int fd, const void* buf, const size_t count);

extern int posix_poll(struct pollfd fds[], const nfds_t nfds, const int timeout);

extern int posix_pthread_create(pthread_t* restrict thread,
                                const pthread_attr_t* restrict attr,
                                void* (*start_routine)(void*), void* restrict arg);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_POSIX_H */
