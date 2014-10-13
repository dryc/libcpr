/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_MAP_H
#define CPR_MAP_H

/**
 * @file
 *
 * @include map.c
 *
 * @see http://en.wikipedia.org/wiki/Associative_array
 *
 * @example map.c
 */

#include "types.h"

#include <stddef.h> /* for size_t */

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
/* Constants */

/**
 * The size of the `cpr_map_t` opaque type, i.e., `sizeof(cpr_map_t)`.
 */
extern const size_t cpr_map_sizeof;

////////////////////////////////////////////////////////////////////////////////
/* Constructors */

/**
 * Allocates heap memory for a new `cpr_map_t` structure.
 *
 * @error  ENOMEM if the allocation of storage failed
 * @return a pointer to the beginning of the allocated heap space,
 *         or a `NULL` pointer if an error occurred
 * @note   before use, the structure must first be initialized
 * @see    cpr_map_alloca()
 */
cpr_map_t* cpr_map_alloc(void);

////////////////////////////////////////////////////////////////////////////////
/* Destructor */

/**
 * Deallocates the heap memory used by a map.
 *
 * @param map a pointer to the map to deallocate, or a `NULL` pointer
 * @post  the `map` pointer is invalidated
 */
void cpr_map_free(cpr_map_t* map);

////////////////////////////////////////////////////////////////////////////////
/* Abbreviations */

/*
 * Abbreviated type, variable, and function names if the `CPR_ABBREV`
 * preprocessor symbol is defined:
 */
#ifdef CPR_ABBREV
  /** Alias for `::cpr_map_t` when `CPR_ABBREV` is defined. */
  #define map_t      cpr_map_t
  /** Alias for `#cpr_map_sizeof` when `CPR_ABBREV` is defined. */
  #define map_sizeof cpr_map_sizeof
  /** Alias for `cpr_map_alloc()` when `CPR_ABBREV` is defined. */
  #define map_alloc  cpr_map_alloc
  /** Alias for `cpr_map_free()` when `CPR_ABBREV` is defined. */
  #define map_free   cpr_map_free
#endif /* CPR_ABBREV */

////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_MAP_H */
