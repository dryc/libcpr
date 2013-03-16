/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_MAP_H
#define CPR_MAP_H

/**
 * @file
 *
 * @include map.c
 * @example map.c
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

/**
 * An opaque type representing a key-value map.
 */
typedef struct cpr_map cpr_map_t;

/**
 * The size of the `cpr_map_t` opaque type, i.e., `sizeof(cpr_map_t)`.
 */
extern const size_t cpr_map_sizeof;

/**
 * Returns a pointer to a new heap-allocated `cpr_map_t` structure.
 *
 * @see cpr_map_alloca()
 */
cpr_map_t* cpr_map_alloc(void);

/**
 * ...
 */
void cpr_map_free(cpr_map_t* map);

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

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_MAP_H */
