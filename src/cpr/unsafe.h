/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_UNSAFE_H
#define CPR_UNSAFE_H

/**
 * @file
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <alloca.h> /* for alloca() */

/**
 * Returns a pointer to a new stack-allocated `cpr_vector_t` structure.
 */
#define cpr_vector_alloca() alloca(cpr_vector_sizeof)

/**
 * Abbreviated type and function names if `CPR_ABBREV` is defined:
 */
#ifdef CPR_ABBREV
  #define vector_alloca cpr_vector_alloca
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_UNSAFE_H */
