/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_VECTOR_H
#define _CPRIME_VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

typedef struct {
  void* data; // TODO
  size_t count;
} vector_t;

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_VECTOR_H */
