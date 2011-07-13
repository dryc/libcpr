/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_UUID_H
#define _CPRIME_UUID_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> /* for uint8_t */

typedef struct {
  uint8_t data[16];
} uuid_t;

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_UUID_H */
