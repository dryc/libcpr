/* This is free and unencumbered software released into the public domain. */

#include "build.h"

#ifdef HAVE_REGEX_H
#include <regex.h> /* for regex_t, regcomp(), regexec() */
#endif

#ifdef HAVE_REGEX_H
static once_t  uri_validate_once = ONCE_INIT;
static regex_t uri_validate_regex;

static void
uri_validate_init() {
  const int rc = regcomp(&uri_validate_regex, URI_PATTERN, REG_EXTENDED | REG_NOSUB);
  assert(is_zero(rc));
}
#endif /* HAVE_REGEX_H */

bool
uri_validate(const char* const restrict uri) {
  validate_with_false_return(is_nonnull(uri) && *uri != '\0');

  // TODO: ensure that the URI is a valid UTF-8 string.

#ifdef HAVE_REGEX_H
  once(&uri_validate_once, uri_validate_init);
  return regexec(&uri_validate_regex, uri, (size_t)0, NULL, 0) == 0;
#else
  return (errno = ENOTSUP), TRUE;
#endif /* HAVE_REGEX_H */
}
