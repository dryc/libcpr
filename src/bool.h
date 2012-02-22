/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_BOOL_H
#define CPRIME_BOOL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for _Bool, true, false */

typedef _Bool bool_t;

#define TRUE  true
#define FALSE false

static inline int
bool_equal(const bool_t bool1, const bool_t bool2) {
  return (bool1 == bool2);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_BOOL_H */
