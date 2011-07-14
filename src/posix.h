/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_POSIX_H
#define _CPRIME_POSIX_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>  /* for ssize_t */
extern int posix_close(const int fd);
extern ssize_t posix_write(const int fd, const void* buf, const size_t count);
#endif /* HAVE_UNISTD_H */

#ifdef HAVE_POLL_H
#include <poll.h>    /* for pollfd, nfds_t */
extern int posix_poll(struct pollfd fds[], const nfds_t nfds, const int timeout);
#endif /* HAVE_POLL_H */

#ifdef HAVE_PTHREAD_H
#include <pthread.h> /* for pthread_t, pthread_attr_t */
extern int posix_pthread_create(pthread_t* thread,
                                const pthread_attr_t* attr,
                                void* (*start_routine)(void*), void* arg);
#endif /* HAVE_PTHREAD_H */

#ifdef HAVE_MQUEUE_H
#include <mqueue.h> /* for mqd_t */
extern mqd_t posix_mq_send(mqd_t mqdes, const char* msg_ptr,
                           size_t msg_len, unsigned int msg_prio);
extern ssize_t posix_mq_receive(mqd_t mqdes, char* msg_ptr,
                                size_t msg_len, unsigned int* msg_prio);
#endif /* HAVE_MQUEUE_H */

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_POSIX_H */
