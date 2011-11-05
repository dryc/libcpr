/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_BOOL_H_
#define _CPRIME_BOOL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for _Bool, true, false */

typedef _Bool bool_t;

#define TRUE  true
#define FALSE false

extern int bool_equal(const bool_t bool1, const bool_t bool2);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CPRIME_BOOL_H_ */
