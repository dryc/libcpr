/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_UNSAFE_H
#define CPR_UNSAFE_H

/**
 * @file
 *
 * Unsafe operations for advanced usage.
 *
 * These macros rely on the non-portable `alloca()` facility.
 *
 * @see http://en.wikipedia.org/wiki/Stack-based_memory_allocation
 * @see http://www.gnu.org/software/libc/manual/html_node/Variable-Size-Automatic.html
 */

#ifndef CPR_UNSAFE
#define CPR_UNSAFE
#endif

#include <alloca.h> /* for alloca() */

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
/* Macros */

/**
 * Allocates stack memory for a new `cpr_list_t` structure.
 *
 * @return a pointer to the beginning of the allocated stack space
 * @warning undefined behavior if the allocation causes stack overflow
 * @see cpr_list_alloc()
 */
#define cpr_list_alloca() alloca(cpr_list_sizeof)

/**
 * Allocates stack memory for a new `cpr_map_t` structure.
 *
 * @return a pointer to the beginning of the allocated stack space
 * @warning undefined behavior if the allocation causes stack overflow
 * @see cpr_map_alloc()
 */
#define cpr_map_alloca() alloca(cpr_map_sizeof)

/**
 * Allocates stack memory for a new `cpr_set_t` structure.
 *
 * @return a pointer to the beginning of the allocated stack space
 * @warning undefined behavior if the allocation causes stack overflow
 * @see cpr_set_alloc()
 */
#define cpr_set_alloca() alloca(cpr_set_sizeof)

/**
 * Allocates stack memory for a new `cpr_string_t` structure.
 *
 * @return a pointer to the beginning of the allocated stack space
 * @warning undefined behavior if the allocation causes stack overflow
 * @see cpr_string_alloc()
 */
#define cpr_string_alloca() alloca(cpr_string_sizeof)

/**
 * Allocates stack memory for a new `cpr_vector_t` structure.
 *
 * @return a pointer to the beginning of the allocated stack space
 * @warning undefined behavior if the allocation causes stack overflow
 * @see cpr_vector_alloc()
 */
#define cpr_vector_alloca() alloca(cpr_vector_sizeof)

////////////////////////////////////////////////////////////////////////////////
/* Abbreviations */

/*
 * Abbreviated type, variable, and function names if the `CPR_ABBREV`
 * preprocessor symbol is defined:
 */
#ifdef CPR_ABBREV
  /** Alias for `cpr_list_alloca()` when `CPR_ABBREV` is defined. */
  #define list_alloca   cpr_list_alloca
  /** Alias for `cpr_map_alloca()` when `CPR_ABBREV` is defined. */
  #define map_alloca    cpr_map_alloca
  /** Alias for `cpr_set_alloca()` when `CPR_ABBREV` is defined. */
  #define set_alloca    cpr_set_alloca
  /** Alias for `cpr_string_alloca()` when `CPR_ABBREV` is defined. */
  #define string_alloca cpr_string_alloca
  /** Alias for `cpr_vector_alloca()` when `CPR_ABBREV` is defined. */
  #define vector_alloca cpr_vector_alloca
#endif

////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_UNSAFE_H */
