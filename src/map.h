/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_MAP_H
#define _CPRIME_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

typedef struct {
  void* data;
  size_t count;
} map_t;

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_MAP_H */
