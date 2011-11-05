/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_URI_H_
#define _CPRIME_URI_H_

#ifdef __cplusplus
extern "C" {
#endif

/* @see http://tools.ietf.org/html/rfc3986#appendix-B */
#define URI_PATTERN "^(([^:/?#]+):)(//([^/?#]*))?([^?#]*)(\\?([^#]*))?(#(.*))?$"

typedef struct {
  char* string;
} uri_t;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _CPRIME_URI_H_ */
