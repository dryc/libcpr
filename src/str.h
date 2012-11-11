/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_STR_H
#define CPRIME_STR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */
#include <stddef.h>  /* for size_t */

extern char* str_dup(const char* str);

extern char* str_ndup(const char* str,
  size_t size);

extern char* str_format(const char* fmt, ...);

extern long str_size(const char* str);

extern long str_length(const char* str);

extern hash_t str_hash(const char* str);

extern int str_compare(const char* str1, const char* str2);

extern bool str_equal(const char* str1, const char* str2);

extern bool str_is_empty(const char* str);

extern bool str_is_ascii(const char* str);
extern bool str_is_utf8(const char* str);

extern bool str_is_alnum(const char* str);
extern bool str_is_alpha(const char* str);
extern bool str_is_blank(const char* str);
extern bool str_is_cntrl(const char* str);
extern bool str_is_digit(const char* str);
extern bool str_is_graph(const char* str);
extern bool str_is_lower(const char* str);
extern bool str_is_print(const char* str);
extern bool str_is_punct(const char* str);
extern bool str_is_space(const char* str);
extern bool str_is_upper(const char* str);
extern bool str_is_xdigit(const char* str);

extern bool str_is_uuid(const char* str);

extern bool str_has_prefix(const char* restrict str,
  const char* restrict prefix);

extern bool str_has_suffix(const char* restrict str,
  const char* restrict suffix);

extern bool str_contains(const char* restrict str,
  const char* restrict substr);

extern bool str_matches(const char* restrict str,
  const char* restrict pattern);

extern int str_to_int(const char* restrict str);
extern long str_to_long(const char* restrict str);
extern intmax_t str_to_intmax(const char* restrict str);
extern float str_to_float(const char* restrict str);
extern double str_to_double(const char* restrict str);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_STR_H */
