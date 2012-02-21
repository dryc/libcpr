/* This is free and unencumbered software released into the public domain. */

#include "build.h"

#include <regex.h> /* for regex_t, regcomp(), regexec() */

static once_t  uri_validate_once = ONCE_INIT;
static regex_t uri_validate_regex;

static void
uri_validate_init() {
  const int rc = regcomp(&uri_validate_regex, URI_PATTERN, REG_EXTENDED | REG_NOSUB);
  assert(is_zero(rc));
}

bool
uri_validate(const char* const restrict uri) {
  validate_with_false_return(is_nonnull(uri) && *uri != '\0');

  // TODO: ensure that the URI is a valid UTF-8 string.

  once(&uri_validate_once, uri_validate_init);

  return regexec(&uri_validate_regex, uri, (size_t)0, NULL, 0) == 0;
}
