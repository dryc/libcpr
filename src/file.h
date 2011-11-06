/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_FILE_H_
#define _CPRIME_FILE_H_

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

#endif /* _CPRIME_FILE_H_ */
