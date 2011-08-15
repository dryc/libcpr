/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_URI_H
#define _CPRIME_URI_H

#ifdef __cplusplus
extern "C" {
#endif

/* @see http://tools.ietf.org/html/rfc3986#appendix-B */
#define URI_PATTERN "^(([^:/?#]+):)(//([^/?#]*))?([^?#]*)(\\?([^#]*))?(#(.*))?$"

typedef struct {
  char* string;
} uri_t;

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_URI_H */
