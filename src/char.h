/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_CHAR_H
#define _CPRIME_CHAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> /* for uint32_t, UINT32_MAX */

#define CHAR_EOF         (UINT32_MAX)
#define CHAR_MAX_ASCII   (0x7F)
#define CHAR_MAX_UCS     (0x10FFFF)

#define CHAR_IS_ASCII(c) (c <= CHAR_MAX_ASCII)
#define CHAR_IS_UCS(c)   (c <= 0x10FFFF)

typedef uint32_t char_t;

extern char_t* char_alloc();

extern char_t* char_construct(const char_t val);

extern char_t* char_clone(const char_t* const ptr);

#define CHAR_INIT (0)

extern hash_t char_hash(const char_t chr);
extern int char_equal(const char_t chr1, const char_t chr2);
extern int char_compare(const char_t chr1, const char_t chr2);
extern int char_validate(const char_t chr);

extern int char_is_valid(const char_t chr);
extern int char_is_zero(const char_t chr);

extern int char_is_alnum(const char_t chr);
extern int char_is_alpha(const char_t chr);
extern int char_is_ascii(const char_t chr);
extern int char_is_blank(const char_t chr);
extern int char_is_cntrl(const char_t chr);
extern int char_is_digit(const char_t chr);
extern int char_is_graph(const char_t chr);
extern int char_is_lower(const char_t chr);
extern int char_is_print(const char_t chr);
extern int char_is_punct(const char_t chr);
extern int char_is_space(const char_t chr);
extern int char_is_upper(const char_t chr);
extern int char_is_xdigit(const char_t chr);

extern struct string_t* char_to_string(const char_t chr);

extern int char_encode(const char_t input, byte_t* output);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_CHAR_H */
