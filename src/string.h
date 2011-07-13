/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_STRING_H
#define _CPRIME_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

typedef struct {
  char* data;
  size_t size;
} string_t;

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_STRING_H */
