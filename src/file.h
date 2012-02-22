/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_FILE_H
#define CPRIME_FILE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char* path;
  int fd;
} file_t;

extern bool file_exists(const char* path);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_FILE_H */
