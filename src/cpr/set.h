/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_SET_H
#define CPR_SET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for size_t */

typedef struct cpr_set cpr_set_t;

/**
 * The size of the cpr_set_t opaque type, i.e., sizeof(cpr_set_t).
 */
extern const size_t cpr_set_sizeof;

cpr_set_t* cpr_set_alloc(void);

void cpr_set_free(cpr_set_t* set);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_SET_H */
