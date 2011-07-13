/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_CHAR_H
#define _CPRIME_CHAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> /* for uint32_t */

typedef uint32_t char_t;

extern int char_hash(const char_t chr);
extern int char_equal(const char_t chr1, const char_t chr2);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_CHAR_H */
