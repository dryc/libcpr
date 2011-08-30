/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_HASH_MAP_H
#define _CPRIME_HASH_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */
#include <stddef.h>  /* for size_t */

typedef struct hash_map_t {
  size_t count;
} hash_map_t;

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_HASH_MAP_H */
