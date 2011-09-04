/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_ATOM_H
#define _CPRIME_ATOM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>     /* for int*_t, INT*_MIN, INT*_MAX */

#define ATOM8_SIZE      sizeof(int8_t)
#define ATOM8_MIN       INT8_MIN
#define ATOM8_MAX       INT8_MAX

typedef struct atom8_t {
  volatile int8_t value;
} atom8_t;

#define ATOM16_SIZE     sizeof(int16_t)
#define ATOM16_MIN      INT16_MIN
#define ATOM16_MAX      INT16_MAX

typedef struct atom16_t {
  volatile int16_t value;
} atom16_t;

#define ATOM32_SIZE     sizeof(int32_t)
#define ATOM32_MIN      INT32_MIN
#define ATOM32_MAX      INT32_MAX

typedef struct atom32_t {
  volatile int32_t value;
} atom32_t;

#define ATOM64_SIZE     sizeof(int64_t)
#define ATOM64_MIN      INT64_MIN
#define ATOM64_MAX      INT64_MAX

typedef struct atom64_t {
  volatile int64_t value;
} atom64_t;

#define ATOM_INIT(v)    {.value = (v)}

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_ATOM_H */
