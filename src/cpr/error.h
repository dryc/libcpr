/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_ERROR_H
#define CPR_ERROR_H

/**
 * @file
 */

#ifdef __cplusplus
extern "C" {
#endif

#define cpr_error(ec, em) cpr_error_trigger(__func__, ec, em)

/**
 * Sets `errno` and invokes the error callback function.
 */
void cpr_error_trigger(
  const char* caller_name,
  int error_code,
  const char* error_message, ...);

/**
 * The type signature of the error callback function.
 */
typedef bool (*cpr_error_callback_t)(
  int error_code,
  const char* error_message,
  const char* function);

/**
 * The current error callback function, if any.
 */
extern cpr_error_callback_t cpr_error_callback;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_ERROR_H */
