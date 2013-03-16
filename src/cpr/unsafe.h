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

/*
 * Abbreviated type, variable, and function names if the `CPR_ABBREV`
 * preprocessor symbol is defined:
 */
#ifdef CPR_ABBREV
  /** Alias for `cpr_vector_alloca()` when `CPR_ABBREV` is defined. */
  #define vector_alloca cpr_vector_alloca
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_UNSAFE_H */
