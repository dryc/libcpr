/* This is free and unencumbered software released into the public domain. */

#include "build.h"

#ifdef HAVE_UNISTD_H
  #include <unistd.h>  /* for POSIX system calls and functions */
#endif /* HAVE_UNISTD_H */

#ifdef HAVE_POLL_H
#  include <poll.h>    /* for poll() */
#endif /* HAVE_POLL_H */

#ifdef HAVE_PTHREAD_H
#  include <pthread.h> /* for pthread_create() */
#endif /* HAVE_PTHREAD_H */

#ifdef HAVE_MQUEUE_H
#  include <time.h>    /* for struct timespec */
#  include <mqueue.h>  /* for mq_send(), mq_receive() */
#endif /* HAVE_MQUEUE_H */

#ifdef HAVE_UNISTD_H
public int
posix_close(const int fd) {
  int result = 0;
  while (unlikely((result = close(fd)) == -1)) {
    switch (errno) {
      case EINTR:
        continue; // retry the syscall
      default:
        goto done;
    }
  }
done:
  return result;
}
#endif /* HAVE_UNISTD_H */

#ifdef HAVE_UNISTD_H
public ssize_t
posix_write(const int fd, const void* const buffer, const size_t count) {
  size_t result = 0;
  while (result < count) {
    const ssize_t rc = write(fd, buffer + result, count - result);
    if (unlikely(rc == -1)) {
      switch (errno) {
        case EINTR:
        case EAGAIN:
          continue; /* try again */
        default:
          return is_zero(result) ? rc : (ssize_t)result;
      }
    }
    result += rc;
  }
  return (ssize_t)result;
}
#endif /* HAVE_UNISTD_H */

#ifdef HAVE_POLL_H
public int
posix_poll(struct pollfd fds[], const nfds_t nfds, const int timeout) {
  int result = 0;
  while (unlikely((result = poll(fds, nfds, timeout)) == -1)) {
    switch (errno) {
      case EINTR:
      case EAGAIN:
        continue; // retry the syscall
      default:
        goto done;
    }
  }
done:
  return result;
}
#endif /* HAVE_POLL_H */

#ifdef HAVE_PTHREAD_H
#ifdef HAVE_PTHREAD_CREATE
public int
posix_pthread_create(pthread_t* restrict thread, const pthread_attr_t* restrict attr,
               void* (*start_routine)(void*), void* restrict arg) {
  int result = 0;
  while (unlikely((result = pthread_create(thread, attr, start_routine, arg)) != 0)) {
    switch (result) {
      case EAGAIN:
        // TODO: invoke the warning handler callback function.
        continue; // retry the syscall
      default:
        goto done;
    }
  }
done:
  return result;
}
#endif /* HAVE_PTHREAD_CREATE */
#endif /* HAVE_PTHREAD_H */

#ifdef HAVE_MQUEUE_H
public mqd_t
posix_mq_send(mqd_t mqdes, const char* msg_ptr, size_t msg_len, unsigned int msg_prio) {
  mqd_t result = 0;
  while (unlikely((result = mq_send(mqdes, msg_ptr, msg_len, msg_prio)) == -1)) {
    switch (errno) {
      case EINTR:
      case EAGAIN:
        continue; // retry the syscall
      default:
        goto done;
    }
  }
done:
  return result;
}
#endif /* HAVE_MQUEUE_H */

#ifdef HAVE_MQUEUE_H
public mqd_t
posix_mq_timedsend(mqd_t mqdes, const char* msg_ptr, size_t msg_len, unsigned int msg_prio, const struct timespec* abs_timeout) {
  mqd_t result = 0;
  while (unlikely((result = mq_timedsend(mqdes, msg_ptr, msg_len, msg_prio, abs_timeout)) == -1)) {
    switch (errno) {
      case EINTR:
      case EAGAIN:
        continue; // retry the syscall
      default:
        goto done;
    }
  }
done:
  return result;
}
#endif /* HAVE_MQUEUE_H */

#ifdef HAVE_MQUEUE_H
public ssize_t
posix_mq_receive(mqd_t mqdes, char* msg_ptr, size_t msg_len, unsigned int* msg_prio) {
  ssize_t result = 0;
  while (unlikely((result = mq_receive(mqdes, msg_ptr, msg_len, msg_prio)) == -1)) {
    switch (errno) {
      case EINTR:
      case EAGAIN:
        continue; // retry the syscall
      default:
        goto done;
    }
  }
done:
  return result;
}
#endif /* HAVE_MQUEUE_H */

#ifdef HAVE_MQUEUE_H
public ssize_t
posix_mq_timedreceive(mqd_t mqdes, char* msg_ptr, size_t msg_len, unsigned int* msg_prio, const struct timespec* abs_timeout) {
  ssize_t result = 0;
  while (unlikely((result = mq_timedreceive(mqdes, msg_ptr, msg_len, msg_prio, abs_timeout)) == -1)) {
    switch (errno) {
      case EINTR:
      case EAGAIN:
        continue; // retry the syscall
      default:
        goto done;
    }
  }
done:
  return result;
}
#endif /* HAVE_MQUEUE_H */
