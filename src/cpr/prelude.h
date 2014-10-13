/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_PRELUDE_H
#define CPR_PRELUDE_H

/**
 * @file
 *
 * @note This header file is only for builds; it does not get installed.
 */

////////////////////////////////////////////////////////////////////////////////
/* Macros */

#define cpr_malloc(s)     std::malloc(s)
#define cpr_free(p)       std::free(p)
#define cpr_calloc(n, s)  std::calloc(n, s)
#define cpr_realloc(p, s) std::realloc(p, s)

#ifndef __has_builtin
  #define __has_builtin(x) 0
#endif

#ifndef __has_feature
  #define __has_feature(x) 0
#endif

#ifndef __has_extension
  #define __has_extension __has_feature
#endif

////////////////////////////////////////////////////////////////////////////////

#endif /* CPR_PRELUDE_H */
