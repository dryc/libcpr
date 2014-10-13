/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_TYPES_H
#define CPR_TYPES_H

/**
 * @file
 */

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
/* Typedefs */

/**
 * Indicates that the `cpr_list_t` structure type has been defined.
 */
#define CPR_LIST_T

/**
 * An opaque type representing a doubly-linked list.
 */
typedef struct cpr_list cpr_list_t;

/**
 * Indicates that the `cpr_map_t` structure type has been defined.
 */
#define CPR_MAP_T

/**
 * An opaque type representing a key-value map.
 */
typedef struct cpr_map cpr_map_t;

/**
 * Indicates that the `cpr_set_t` structure type has been defined.
 */
#define CPR_SET_T

/**
 * An opaque type representing a set of elements.
 */
typedef struct cpr_set cpr_set_t;

/**
 * Indicates that the `cpr_string_t` structure type has been defined.
 */
#define CPR_STRING_T

/**
 * An opaque type representing a dynamic string.
 */
typedef struct cpr_string cpr_string_t;

/**
 * Indicates that the `cpr_vector_t` structure type has been defined.
 */
#define CPR_VECTOR_T

/**
 * An opaque type representing a contiguous vector of elements.
 */
typedef struct cpr_vector cpr_vector_t;

////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_TYPES_H */
