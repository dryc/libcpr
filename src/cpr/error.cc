/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "error.h"

#include <cassert> /* for assert() */
#include <cerrno>  /* for errno */
#include <cstdarg> /* for va_list, va_*(), std::vsnprintf() */
#include <cstdio>  /* for std::fprintf() */
#include <cstdlib> /* for std::abort() */
#include <cstring> /* for std::strerror() */

////////////////////////////////////////////////////////////////////////////////
/* Constants */

const std::size_t cpr_error_sizeof = sizeof(cpr_error_t);

////////////////////////////////////////////////////////////////////////////////
/* Variables */

cpr_error_hook_t cpr_error_hook = nullptr;

/**
 * A thread-local buffer large enough to hold typical formatted error
 * messages. Messages larger than the capacity of the buffer are truncated
 * at `sizeof(error_buffer)-1`. The buffer is always NUL-terminated.
 */
#if __has_feature(cxx_thread_local)
static thread_local char error_buffer[4096];
#else
static __thread char error_buffer[4096];
#endif

static const char* error_types[] = {
  nullptr,   /* CPR_ERROR_TYPE_UNDEFINED */
  "Logic",   /* CPR_ERROR_TYPE_LOGIC     */
  "Runtime", /* CPR_ERROR_TYPE_RUNTIME   */
  "Fatal",   /* CPR_ERROR_TYPE_FATAL     */
  nullptr
};

static const std::size_t error_types_count =
  (sizeof(error_types) / sizeof(error_types[0])) - 1;

////////////////////////////////////////////////////////////////////////////////
/* Helpers */

static void
cpr_error_print(const cpr_error_t* const error,
                FILE* const stream) {
  if (!error || !error->code) return;

  assert(error->type >= CPR_ERROR_TYPE_UNDEFINED &&
         error->type <= CPR_ERROR_TYPE_FATAL);
  const char* const error_type = (static_cast<std::size_t>(error->type) < error_types_count) ?
    error_types[error->type] : nullptr;

  const char* const error_message = error->message ?
    error->message : std::strerror(error->code);

  if (!error_type) {
    std::fprintf(stream, "Error: ");
  }
  else {
    std::fprintf(stream, "%s error: ", error_type);
  }

  std::fprintf(stream, "%s (%d)\n", error_message, error->code);
}

////////////////////////////////////////////////////////////////////////////////
/* Functions */

bool
cpr_abort_with_error(const cpr_error_t* const error) {
  if (error) {
    cpr_error_print(error, stderr);
    std::fprintf(stderr, "Aborted in function %s() on line %u of %s.\n",
      error->function, error->line, error->file);
  }

  std::abort();

  return false; /* never reached */
}

void
_cpr_abort(const char* const function,
           const char* const file,
           const unsigned int line) {
  const cpr_error_t error = {
    /*.type     =*/ CPR_ERROR_TYPE_UNDEFINED,
    /*.code     =*/ 0,
    /*.message  =*/ nullptr,
    /*.function =*/ function,
    /*.file     =*/ file,
    /*.line     =*/ line,
  };

  static_cast<void>(cpr_abort_with_error(&error));
}

bool
_cpr_error(const char* const function,
           const char* const file,
           const unsigned int line,
           const cpr_error_type_t error_type,
           const cpr_error_code_t error_code,
           const char* const error_format, ...) {
  errno = error_code;

  if (!cpr_error_hook) {
    return false; /* don't retry */
  }

  if (error_format) {
    va_list args;
    va_start(args, error_format);
    static_cast<void>(std::vsnprintf(error_buffer, sizeof(error_buffer), error_format, args));
    va_end(args);
  }

  const cpr_error_t error = {
    /*.type     =*/ error_type,
    /*.code     =*/ error_code,
    /*.message  =*/ error_format ? error_buffer : nullptr,
    /*.function =*/ function,
    /*.file     =*/ file,
    /*.line     =*/ line,
  };

  return cpr_error_hook(&error);
}
