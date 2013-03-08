/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_STRING_H
#define CPR_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

typedef struct cpr_string cpr_string_t;

/**
 * The size of the cpr_string_t opaque type, i.e., sizeof(cpr_string_t).
 */
extern const size_t cpr_string_sizeof;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_STRING_H */
