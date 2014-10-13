/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_SET_H
#define CPR_SET_H

/**
 * @file
 *
 * @include set.c
 *
 * @see http://en.wikipedia.org/wiki/Set_(computer_science)
 *
 * @example set.c
 */

#include "types.h"

#include <stddef.h> /* for size_t */

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
/* Constants */

/**
 * The size of the `cpr_set_t` opaque type, i.e., `sizeof(cpr_set_t)`.
 */
extern const size_t cpr_set_sizeof;

////////////////////////////////////////////////////////////////////////////////
/* Constructors */

/**
 * Allocates heap memory for a new `cpr_set_t` structure.
 *
 * @error  ENOMEM if the allocation of storage failed
 * @return a pointer to the beginning of the allocated heap space,
 *         or a `NULL` pointer if an error occurred
 * @note   before use, the structure must first be initialized
 * @see    cpr_set_alloca()
 */
cpr_set_t* cpr_set_alloc(void);

////////////////////////////////////////////////////////////////////////////////
/* Destructor */

/**
 * Deallocates the heap memory used by a set.
 *
 * @param set a pointer to the set to deallocate, or a `NULL` pointer
 * @post  the `set` pointer is invalidated
 */
void cpr_set_free(cpr_set_t* set);

////////////////////////////////////////////////////////////////////////////////
/* Abbreviations */

/*
 * Abbreviated type, variable, and function names if the `CPR_ABBREV`
 * preprocessor symbol is defined:
 */
#ifdef CPR_ABBREV
  /** Alias for `::cpr_set_t` when `CPR_ABBREV` is defined. */
  #define set_t      cpr_set_t
  /** Alias for `#cpr_set_sizeof` when `CPR_ABBREV` is defined. */
  #define set_sizeof cpr_set_sizeof
  /** Alias for `cpr_set_alloc()` when `CPR_ABBREV` is defined. */
  #define set_alloc  cpr_set_alloc
  /** Alias for `cpr_set_free()` when `CPR_ABBREV` is defined. */
  #define set_free   cpr_set_free
#endif /* CPR_ABBREV */

////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_SET_H */
