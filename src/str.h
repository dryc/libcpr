/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_STR_H
#define _CPRIME_STR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */

extern long str_size(const char* restrict str);

extern long str_length(const char* restrict str);

extern int str_hash(const char* restrict str);

extern int str_compare(const char* str1, const char* str2);

extern bool str_equal(const char* str1, const char* str2);

extern bool str_is_empty(const char* restrict str);

extern bool str_is_ascii(const char* restrict str);
extern bool str_is_utf8(const char* restrict str);

extern bool str_is_alnum(const char* restrict str);
extern bool str_is_alpha(const char* restrict str);
extern bool str_is_blank(const char* restrict str);
extern bool str_is_cntrl(const char* restrict str);
extern bool str_is_digit(const char* restrict str);
extern bool str_is_graph(const char* restrict str);
extern bool str_is_lower(const char* restrict str);
extern bool str_is_print(const char* restrict str);
extern bool str_is_punct(const char* restrict str);
extern bool str_is_space(const char* restrict str);
extern bool str_is_upper(const char* restrict str);
extern bool str_is_xdigit(const char* restrict str);

extern bool str_has_prefix(const char* restrict str,
  const char* restrict prefix);

extern bool str_has_suffix(const char* restrict str,
  const char* restrict suffix);

extern bool str_contains(const char* restrict str,
  const char* restrict substr);

extern int str_to_intmax(const char* restrict str,
  intmax_t* restrict result);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_STR_H */
