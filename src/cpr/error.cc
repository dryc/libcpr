/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "error.h"

#include <cerrno> /* for errno */

cpr_error_callback_t cpr_error_callback = nullptr;

void
cpr_error_trigger(const char* const caller_name,
                  const int error_code,
                  const char* const error_message, ...) {
  (void)caller_name, (void)error_message; /* unused at present */

  errno = error_code;

  // TODO: invoke error callback function, if set.
}
