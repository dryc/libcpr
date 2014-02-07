/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_ERROR_H
#define CPR_ERROR_H

/**
 * @file
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Signals an error and invokes error handling.
 */
#define cpr_error(ec, em) cpr_error_trigger(__func__, ec, em)

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
} cpr_error_t;

/**
 * Sets `errno` and invokes the error callback function.
 */
void cpr_error_trigger(
  const char* caller_name,
  cpr_error_code_t error_code,
  const char* error_message, ...);

/**
 * The type signature for the error callback function.
 */
typedef bool (*cpr_error_callback_t)(const cpr_error_t* error);

/**
 * The current error callback function, if any.
 */
extern cpr_error_callback_t cpr_error_callback;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_ERROR_H */
