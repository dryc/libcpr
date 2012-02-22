/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_URI_H
#define CPRIME_URI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */

/* @see http://tools.ietf.org/html/rfc3986#appendix-B */
#define URI_PATTERN "^(([^:/?#]+):)(//([^/?#]*))?([^?#]*)(\\?([^#]*))?(#(.*))?$"

bool uri_validate(const char* uri);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_URI_H */
