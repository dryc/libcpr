/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "cpr/string.h"
#include "cpr/error.h"

#include <cassert>      /* for assert() */
#include <cstdlib>      /* for std::calloc(), std::free() */
#include <new>          /* for std::bad_alloc */
#include <stdexcept>    /* for std::length_error */
#include <string>       /* for std::string */
#include <system_error> /* for std::errc */

struct cpr_string {
  public:
    std::string data;

    cpr_string() : data() {}

    cpr_string(const char* str) : data(str) {}
};

extern const size_t cpr_string_sizeof = sizeof(cpr_string_t);

cpr_string_t*
cpr_string(const char* const str) {
  cpr_string_t* const string = reinterpret_cast<cpr_string_t*>(cpr_calloc(1, sizeof(cpr_string_t)));

  if (string != nullptr) {
    try {
      if (str == nullptr) {
        new(string) cpr_string_t();
      }
      else {
        new(string) cpr_string_t(str);
      }
    }
    catch (const std::length_error&) {
      cpr_error(std::errc::invalid_argument, nullptr);  /* EINVAL */
    }
    catch (const std::bad_alloc&) {
      cpr_error(std::errc::not_enough_memory, nullptr); /* ENOMEM */
    }
  }

  return string;
}
