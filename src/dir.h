/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_DIR_H
#define _CPRIME_DIR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <dirent.h> /* for DIR, dirent */

typedef struct {
  char* path;
  DIR* dir;
  struct dirent* dirent;
} dir_t;

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_DIR_H */
