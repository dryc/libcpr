/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_UTF8_H
#define CPRIME_UTF8_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> /* for uint8_t */

#define UTF8_LENGTH(c) (                               \
  (c < 0x00080) ? 1 :                                  \
  (c < 0x00800) ? 2 :                                  \
  (c < 0x10000) ? 3 : 4                                \
)

#define UTF8_ENCODE(c, output) {                       \
  if (likely(c < 0x00080)) {                           \
    *output++ = (uint8_t)(c & 0xFF);                   \
  }                                                    \
  else if (likely(c < 0x00800)) {                      \
    *output++ = 0xC0 + (uint8_t)((c >> 6) & 0x1F);     \
    *output++ = 0x80 + (uint8_t)(c & 0x3F);            \
  }                                                    \
  else if (likely(c < 0x10000)) {                      \
    *output++ = 0xE0 + (uint8_t)((c >> 12) & 0x0F);    \
    *output++ = 0x80 + (uint8_t)((c >> 6)  & 0x3F);    \
    *output++ = 0x80 + (uint8_t)(c & 0x3F);            \
  }                                                    \
  else {                                               \
    *output++ = 0xF0 + (uint8_t)((c >> 18) & 0x07);    \
    *output++ = 0x80 + (uint8_t)((c >> 12) & 0x3F);    \
    *output++ = 0x80 + (uint8_t)((c >> 6) & 0x3F);     \
    *output++ = 0x80 + (uint8_t)(c & 0x3F);            \
  }                                                    \
}

#define UTF8_SKIP_CHAR(p)                              \
  (typeof(p))((p) + utf8_skip_table[*((const uint8_t*)(p))])

extern const uint8_t const utf8_skip_table[256];

/**
 * Encodes a single Unicode code point as UTF-8.
 *
 * The given output buffer must have at least 4 bytes of space.
 *
 * @return the number of bytes written
 */
int utf8_encode(unsigned int c, char* buffer);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_UTF8_H */
