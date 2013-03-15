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
 * Sets errno and invokes the error callback function.
 */
void cpr_error_trigger(
  const char* caller_name,
  int error_code,
  const char* error_message, ...);

#ifdef __cplusplus
} /* extern "C" */
#endif

#ifdef __cplusplus
#include <system_error> /* for std::errc */

static inline void
cpr_error_trigger(const char* caller_name,
                  const std::errc& error_code,
                  const char* error_message, ...) {
  cpr_error_trigger(caller_name,
    static_cast<int>(error_code), error_message); // TODO
}
#endif

#define cpr_error(ec, em) cpr_error_trigger(__func__, ec, em)

#endif /* CPR_ERROR_H */
