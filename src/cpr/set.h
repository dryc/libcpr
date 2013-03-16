/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_SET_H
#define CPR_SET_H

/**
 * @file
 *
 * @include set.c
 * @example set.c
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

/**
 * An opaque type representing a set of elements.
 */
typedef struct cpr_set cpr_set_t;

/**
 * The size of the `cpr_set_t` opaque type, i.e., `sizeof(cpr_set_t)`.
 */
extern const size_t cpr_set_sizeof;

/**
 * Returns a pointer to a new heap-allocated `cpr_set_t` structure.
 */
cpr_set_t* cpr_set_alloc(void);

/**
 * ...
 */
void cpr_set_free(cpr_set_t* set);

/**
 * Abbreviated type and function names when `CPR_ABBREV` is defined:
 */
#ifdef CPR_ABBREV
  #define set_t      cpr_set_t
  #define set_sizeof cpr_set_sizeof
  #define set_alloc  cpr_set_alloc
  #define set_free   cpr_set_free
#endif /* CPR_ABBREV */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_SET_H */
