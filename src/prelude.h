/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_PRELUDE_H
#define _CPRIME_PRELUDE_H

#ifdef __cplusplus
extern "C" {
#endif

//#include <stdlib.h>
//#include <stdint.h>
//#include <string.h>
//#include <strings.h>

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

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_PRELUDE_H */
