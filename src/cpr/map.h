/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_MAP_H
#define CPR_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

typedef struct cpr_map cpr_map_t;

/**
 * The size of the cpr_map_t opaque type, i.e., sizeof(cpr_map_t).
 */
extern const size_t cpr_map_sizeof;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_MAP_H */
