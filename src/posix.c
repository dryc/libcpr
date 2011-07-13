/* This is free and unencumbered software released into the public domain. */

#include "build.h"
#include <unistd.h> /* for POSIX system calls and functions */

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
