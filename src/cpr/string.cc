/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "error.h"
#include "string.h"

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

extern const size_t cpr_string_npos = std::string::npos;

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

bool
cpr_string_empty(const cpr_string_t* const string) {
  assert(string != nullptr);

  /* Guaranteed to never throw an exception: */
  return string->data.empty();
#ifdef DEBUG
  static_assert(noexcept(string->data.empty()),
    "std::string::empty() declaration is missing the noexcept specifier");
#endif
}

std::size_t
cpr_string_size(const cpr_string_t* const string) {
  assert(string != nullptr);

  /* Guaranteed to never throw an exception: */
  return string->data.size();
#ifdef DEBUG
  static_assert(noexcept(string->data.size()),
    "std::string::size() declaration is missing the noexcept specifier");
#endif
}

std::size_t
cpr_string_length(const cpr_string_t* const string) {
  assert(string != nullptr);

  return cpr_string_size(string);
}

std::size_t
cpr_string_max_size(const cpr_string_t* const string) {
  assert(string != nullptr);

  /* Guaranteed to never throw an exception: */
  return string->data.max_size();
#ifdef DEBUG
  static_assert(noexcept(string->data.size()),
    "std::string::max_size() declaration is missing the noexcept specifier");
#endif
}

std::size_t
cpr_string_capacity(const cpr_string_t* const string) {
  assert(string != nullptr);

  /* Guaranteed to never throw an exception: */
  return string->data.capacity();
#ifdef DEBUG
  static_assert(noexcept(string->data.size()),
    "std::string::capacity() declaration is missing the noexcept specifier");
#endif
}
