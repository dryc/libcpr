/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_BASE64_H
#define CPRIME_BASE64_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> /* for int8_t */

extern const char const base64_alphabet[64];

extern const int8_t const base64_decode_table[256];

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_BASE64_H */
