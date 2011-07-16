/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_PRELUDE_H
#define _CPRIME_PRELUDE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>  /* for the system error constants, e.g. EINVAL */
#include <stddef.h> /* for NULL, size_t, wchar_t, ptrdiff_t, and offsetof() */

#ifdef __STDC__
#  define __STDC_1989__ 1               /* ANSI X3.159-1989    */
#  ifdef __STDC_VERSION__
#    define __STDC_1990__ 1             /* ISO/IEC 9899:1990   */
#    if __STDC_VERSION__ >= 199409L
#      define __STDC_1994__ 1           /* ISO/IEC 9899-1:1994 */
#    endif
#    if __STDC_VERSION__ >= 199901L
#      define __STDC_1999__ 1           /* ISO/IEC 9899:1999   */
#    endif
#  endif
#endif

#ifdef __GNUC__
#  ifdef __GNUC_PATCHLEVEL__
#    define __GNUC_VERSION__ \
            (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#  else
#    define __GNUC_VERSION__ \
            (__GNUC__ * 10000 + __GNUC_MINOR__ * 100)
#  endif
#endif

/* for the `__func__` identifier in pre-C99 compilers */
#ifndef __STDC_1999__
#  if __GNUC__ >= 2
#    define __func__ __FUNCTION__
#  else
#    define __func__ "<unknown>"
#  endif
#endif

/* for the `restrict` keyword in pre-C99 compilers */
#ifndef __STDC_1999__
#  ifdef __GNUC__ >= 4 // FIXME
#    define restrict __restrict__
#  else
#    define restrict
#  endif
#endif

/* for checking return values */
#define failed(expr)    (expr < 0)
#define succeeded(expr) (expr >= 0)

/* for branch prediction hints */
#ifdef __GNUC__
#  define likely(x)   __builtin_expect(!!(x), 1) // `x` is likely to evaluate to TRUE
#  define unlikely(x) __builtin_expect(!!(x), 0) // `x` is unlikely to evaluate to TRUE
#else
#  define likely(x)   x
#  define unlikely(x) x
#endif /* __GNUC__ */

/* maximum and minimum value macros */
#ifdef __GNUC__
#  define max(a, b) ({          \
          typeof(a) _a = (a);   \
          typeof(b) _b = (b);   \
          _a > _b ? _a : _b; })
#  define min(a, b) ({          \
          typeof(a) _a = (a);   \
          typeof(b) _b = (b);   \
          _a < _b ? _a : _b; })
#else
#  define max(a, b) ((a) > (b) ? (a) : (b))
#  define min(a, b) ((a) < (b) ? (a) : (b))
#endif /* __GNUC__ */

#define choose            __builtin_choose_expr
#define typep(expr, type) __builtin_types_compatible_p(typeof(expr), type)

/* for argument validation at function entry points */
#define validate_with_errno_return(expr) \
  if (unlikely(!(expr))) return -(errno = EINVAL);
#define validate_with_null_return(expr) \
  if (unlikely(!(expr))) return errno = EINVAL, NULL;
#define validate_with_false_return(expr) \
  if (unlikely(!(expr))) return errno = EINVAL, FALSE;
#define validate_with_zero_return(expr) \
  if (unlikely(!(expr))) return errno = EINVAL, 0;
#define validate_with_void_return(expr) \
  if (unlikely(!(expr))) return;

/* helpers for defining overloaded constructor macros */
#define DISPATCH_BEGIN(expr) \
  do { \
    typeof(expr) __dispatch_value = expr; \
    if (0) (void)0;
#define DISPATCH(function, object, type, argument, default_value) \
    else if (typep(argument, type)) \
      function(object, choose(typep(argument, type), \
                              __dispatch_value, default_value));
#define DISPATCH_END(function, object) \
    else function(object, __dispatch_value); \
  } while (0);

/* helpers for token concatenation in macros */
#define CONCAT(A, B)  CONCAT_(A, B)
#define CONCAT_(A, B) A ## B

/* helpers for determining variadic macro arity */
#define ARITY(...)  ARITY_(__VA_ARGS__, ARITY_SEQ_N())
#define ARITY_(...) ARITY_N(__VA_ARGS__)
#define ARITY_N( \
         _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, _10, \
        _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
        _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
        _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
        _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, \
        _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, \
        _61, _62, _63, N, ...) N
#define ARITY_SEQ_N() \
        63, 62, 61, 60,                         \
        59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
        49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
        39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
        29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
        19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
         9,  8,  7,  6,  5,  4,  3,  2,  1,  0

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_PRELUDE_H */
