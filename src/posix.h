/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_POSIX_H
#define _CPRIME_POSIX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h> /* for ssize_t */

extern int posix_close(const int fd);
extern ssize_t posix_write(const int fd, const void* buf, const size_t count);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_POSIX_H */
