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
 * Sets errno and invokes the error callback function.
 */
void cpr_error_trigger(
  const char* caller_name,
  int error_code,
  const char* error_message, ...);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_ERROR_H */
