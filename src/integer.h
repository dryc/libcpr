/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_INTEGER_H_
#define _CPRIME_INTEGER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

typedef struct {
  void* data;
  size_t size;
} integer_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CPRIME_INTEGER_H_ */
