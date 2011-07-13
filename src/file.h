/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_FILE_H
#define _CPRIME_FILE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char* path;
  int fd;
} file_t;

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_FILE_H */
