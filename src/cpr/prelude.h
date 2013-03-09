/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_PRELUDE_H
#define CPR_PRELUDE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __has_builtin
  #define __has_builtin(x) 0
#endif

#ifndef __has_feature
  #define __has_feature(x) 0
#endif

#ifndef __has_extension
  #define __has_extension __has_feature
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_PRELUDE_H */
