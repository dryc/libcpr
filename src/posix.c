/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <unistd.h>  /* for POSIX system calls and functions */
#include <poll.h>    /* for poll() */
#include <pthread.h> /* for pthread_create() */

int
posix_close(const int fd) {
  int result = 0;
  while (unlikely((result = close(fd)) == -1)) {
    switch (errno) {
      case EINTR:
        continue; // retry the syscall
      default:
        break;
    }
  }
  return result;
}

ssize_t
posix_write(const int fd, const void* buf, const size_t count) {
  ssize_t result = 0;
  while (unlikely((result = write(fd, buf, count)) == -1)) {
    switch (errno) {
      case EINTR:
      case EAGAIN:
        continue; // retry the syscall
      default:
        break;
    }
  }
  return result;
}

int
posix_poll(struct pollfd fds[], const nfds_t nfds, const int timeout) {
  int result = 0;
  while (unlikely((result = poll(fds, nfds, timeout)) == -1)) {
    switch (errno) {
      case EINTR:
      case EAGAIN:
        continue; // retry the syscall
      default:
        break;
    }
  }
  return result;
}

int
posix_pthread_create(pthread_t* restrict thread, const pthread_attr_t* restrict attr,
               void* (*start_routine)(void*), void* restrict arg) {
  int result = 0;
  while (unlikely((result = pthread_create(thread, attr, start_routine, arg)) != 0)) {
    switch (result) {
      case EAGAIN:
        // TODO: invoke the warning handler callback function.
        continue; // retry the syscall
      default:
        break;
    }
  }
  return result;
}
