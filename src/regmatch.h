/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_REGMATCH_H
#define CPRIME_REGMATCH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <regex.h>   /* for regmatch_t, regoff_t */
#include <stdbool.h> /* for bool */
#include <stdlib.h>  /* for atoi(), atol() */
#include <strings.h> /* for bcopy() */

#define REGMATCH_INIT   {-1, -1}

static inline regoff_t
regmatch_length(const regmatch_t match) {
  return match.rm_eo - match.rm_so;
}

static inline bool
regmatch_is_empty(const regmatch_t match) {
  return (match.rm_eo - match.rm_so) == 0;
}

static inline regoff_t
regmatch_copy(const regmatch_t match,
              const char* const restrict string,
              char* restrict buffer) {
  const regoff_t length = regmatch_length(match);
  bcopy(string + match.rm_so, buffer, length);
  buffer[length] = '\0';
  return length;
}

static inline int
regmatch_to_int(const regmatch_t match,
                const char* const restrict string) {
  char buffer[regmatch_length(match) + 1];
  regmatch_copy(match, string, buffer);
  return atoi(buffer);
}

static inline long
regmatch_to_long(const regmatch_t match,
                 const char* const restrict string) {
  char buffer[regmatch_length(match) + 1];
  regmatch_copy(match, string, buffer);
  return atol(buffer);
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_REGMATCH_H */
