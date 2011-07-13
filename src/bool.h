/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_BOOL_H
#define _CPRIME_BOOL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for _Bool, true, false */

typedef _Bool bool_t;

extern int bool_equal(const bool_t bool1, const bool_t bool2);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_BOOL_H */
