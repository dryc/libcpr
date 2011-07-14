/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_PRELUDE_H
#define _CPRIME_PRELUDE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>  /* for the system error constants, e.g. EINVAL */
#include <stddef.h> /* for NULL, size_t, wchar_t, ptrdiff_t, and offsetof() */

/* for branch prediction hints */
#ifndef likely
#  define likely(x)   __builtin_expect(!!(x), 1) // `x` is likely to evaluate to TRUE
#endif /* likely */
#ifndef unlikely
#  define unlikely(x) __builtin_expect(!!(x), 0) // `x` is unlikely to evaluate to TRUE
#endif /* unlikely */

#ifndef max
#  define max(a, b) ((a) > (b) ? (a) : (b))
#endif /* max */

#ifndef min
#  define min(a, b) ((a) < (b) ? (a) : (b))
#endif /* min */

#define choose            __builtin_choose_expr
#define typep(expr, type) __builtin_types_compatible_p(typeof(expr), type)

/* for argument validation at function entry points */
#define validate_with_errno_return(expr) \
  if (unlikely(!(expr))) return -(errno = EINVAL);
#define validate_with_null_return(expr) \
  if (unlikely(!(expr))) return errno = EINVAL, NULL;

/* helpers for defining overloaded constructor macros */
#define __dispatch_begin(expr) \
  do { \
    typeof(expr) __dispatch_value = expr; \
    if (0) (void)0;
#define __dispatch(function, object, type, argument, default_value) \
    else if (typep(argument, type)) \
      function(object, choose(typep(argument, type), \
                              __dispatch_value, default_value));
#define __dispatch_end \
    else abort(); \
  } while (0);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_PRELUDE_H */
