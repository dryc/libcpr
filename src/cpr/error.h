/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_ERROR_H
#define CPR_ERROR_H

/**
 * @file
 */

#include <stdbool.h> /* for bool */
#include <stddef.h>  /* for size_t */

#ifdef __cplusplus
extern "C" {
#endif

////////////////////////////////////////////////////////////////////////////////
/* Macros */

/**
 * Aborts the program, printing the caller location to `stderr`.
 *
 * @return never returns
 */
#define cpr_abort() _cpr_abort(__func__, __FILE__, __LINE__)

/**
 * Invokes the error hook with an error condition.
 *
 * @param  error_type the error type (logic, runtime, or fatal)
 * @param  error_code the error code (an integer)
 * @param  error_message the error message (a string)
 * @return the boolean returned by the error hook,
 *         or `false` if `cpr_error_hook` is `NULL`
 */
#define cpr_error(error_type, error_code, error_message)     \
  _cpr_error(__func__, __FILE__, __LINE__,                   \
    error_type, (int)(error_code), error_message)

/**
 * Invokes the error hook with a logic error condition.
 *
 * @param  error_code the error code (an integer)
 * @param  error_message the error message (a C string)
 * @return the boolean returned by the error hook,
 *         or `false` if `cpr_error_hook` is `NULL`
 */
#define cpr_logic_error(error_code, error_message)           \
  cpr_error(CPR_ERROR_TYPE_LOGIC, error_code, error_message)

/**
 * Invokes the error hook with a runtime error condition.
 *
 * @param  error_code the error code (an integer)
 * @param  error_message the error message (a C string)
 * @return the boolean returned by the error hook,
 *         or `false` if `cpr_error_hook` is `NULL`
 */
#define cpr_runtime_error(error_code, error_message)         \
  cpr_error(CPR_ERROR_TYPE_RUNTIME, error_code, error_message)

/**
 * Invokes the error hook with a fatal error condition.
 *
 * @param  error_code the error code (an integer)
 * @param  error_message the error message (a C string)
 * @return the boolean returned by the error hook,
 *         or `false` if `cpr_error_hook` is `NULL`
 */
#define cpr_fatal_error(error_code, error_message)           \
  cpr_error(CPR_ERROR_TYPE_FATAL, error_code, error_message)

////////////////////////////////////////////////////////////////////////////////
/* Typedefs */

/**
 * The error type.
 */
typedef enum cpr_error_type {
  CPR_ERROR_TYPE_UNDEFINED = 0,
  CPR_ERROR_TYPE_LOGIC     = 1,
  CPR_ERROR_TYPE_RUNTIME   = 2,
  CPR_ERROR_TYPE_FATAL     = 3,
} cpr_error_type_t;

/**
 * The error code.
 */
typedef int cpr_error_code_t;

/**
 * The description of an error.
 */
typedef struct cpr_error {
  cpr_error_type_t type;
  cpr_error_code_t code;
  const char* message;
  const char* function;
  const char* file;
  unsigned int line;
} cpr_error_t;

/**
 * The type signature of the error callback hook.
 */
typedef bool (*cpr_error_hook_t)(const cpr_error_t* error);

////////////////////////////////////////////////////////////////////////////////
/* Variables */

/**
 * The current error callback hook, if any.
 */
extern cpr_error_hook_t cpr_error_hook;

////////////////////////////////////////////////////////////////////////////////
/* Constants */

/**
 * The size of the `cpr_error_t` type, i.e., `sizeof(cpr_error_t)`.
 */
extern const size_t cpr_error_sizeof;

////////////////////////////////////////////////////////////////////////////////
/* Functions */

/**
 * Aborts the program, printing error information to `stderr`.
 *
 * @param  error the error to print
 * @return never returns
 */
bool cpr_abort_with_error(const cpr_error_t* error);

/**
 * Internal helper function that invokes `cpr_abort_with_error()`.
 *
 * @private
 */
void _cpr_abort(
  const char* function,
  const char* file,
  unsigned int line);

/**
 * Internal helper function that sets `errno` and invokes the error hook.
 *
 * @private
 */
bool _cpr_error(
  const char* function,
  const char* file,
  unsigned int line,
  cpr_error_type_t error_type,
  cpr_error_code_t error_code,
  const char* error_message, ...);

////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_ERROR_H */
