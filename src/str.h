/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_STR_H
#define _CPRIME_STR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */

extern bool str_has_prefix(
  const char* restrict str,
  const char* restrict prefix);

extern bool str_has_suffix(
  const char* restrict str,
  const char* restrict suffix);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_STR_H */
