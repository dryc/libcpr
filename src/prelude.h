/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_PRELUDE_H
#define _CPRIME_PRELUDE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>  /* for the system error constants, e.g. EINVAL */
#include <stddef.h> /* for NULL, size_t, wchar_t, ptrdiff_t, and offsetof() */

/* branch prediction hints */
#ifndef likely
#define likely(x)   __builtin_expect(!!(x), 1) // `x` is likely to evaluate to TRUE
#endif

#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0) // `x` is unlikely to evaluate to TRUE
#endif

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif

#define validate_arguments(expr) \
  if (unlikely(!(expr))) return -EINVAL;

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_PRELUDE_H */
