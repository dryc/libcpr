/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "error.h"

#include <cerrno>  /* for errno */
#include <cstdarg> /* for va_list, va_*(), vsnprintf() */

cpr_error_callback_t cpr_error_callback = nullptr;

/**
 * A thread-local buffer large enough to hold typical formatted error
 * messages. Messages larger than the capacity of the buffer are truncated
 * at `sizeof(error_buffer)-1`. The buffer is always NUL-terminated.
 */
static __thread char error_buffer[4096];

bool
_cpr_error(const char* const function,
           const char* const file,
           const unsigned int line,
           const cpr_error_type_t error_type,
           const cpr_error_code_t error_code,
           const char* const error_format, ...) {
  errno = error_code;

  if (cpr_error_callback) {
    if (error_format) {
      va_list args;
      va_start(args, error_format);
      (void)vsnprintf(error_buffer, sizeof(error_buffer), error_format, args);
      va_end(args);
    }

    const cpr_error_t error = {
      .type     = error_type,
      .code     = error_code,
      .message  = error_format ? error_buffer : nullptr,
      .function = function,
      .file     = file,
      .line     = line,
    };

    return cpr_error_callback(&error);
  }

  return false; /* don't retry */
}
