/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_UUID_H
#define _CPRIME_UUID_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> /* for uint8_t */
#include <unistd.h> /* for uuid_t on Darwin */

#ifndef _UUID_T
#define _UUID_T
typedef uint8_t uuid_t[16];
#endif /* _UUID_T */

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_UUID_H */
