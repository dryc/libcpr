/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_DIR_H
#define _CPRIME_DIR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <dirent.h> /* for DIR, dirent */

typedef struct {
  char path[PATH_MAX];
  DIR* dir;
  struct dirent* dirent;
} dir_t;

extern int dir_init_empty(dir_t* dir);
extern int dir_init_with_path(dir_t* dir, const char* const path);

#define dir_init1(dir) dir_init_empty(dir)
#define dir_init2(dir, arg1) \
  DISPATCH_BEGIN(arg1) \
    DISPATCH(dir_init_with_path, dir, char*, arg1, NULL) \
  DISPATCH_END
#define dir_init(...) \
  CONCAT(dir_init, ARITY(__VA_ARGS__))(__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_DIR_H */
