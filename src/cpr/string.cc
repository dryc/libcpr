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
  std::string data;
  cpr_string() : data() {}
  cpr_string(const char* str) : data(str) {}
};

const std::size_t cpr_string_sizeof = sizeof(cpr_string_t);
const std::size_t cpr_string_npos   = std::string::npos;

cpr_string_t*
cpr_string(const char* const str) {
  cpr_string_t* const string = reinterpret_cast<cpr_string_t*>(cpr_calloc(1, sizeof(cpr_string_t)));

  if (string) {
    try {
      if (!str) {
        new(string) cpr_string_t();
      }
      else {
        new(string) cpr_string_t(str);
      }
    }
    catch (const std::length_error& error) {
      /* The resulting string length would exceed `max_size`: */
      cpr_logic_error(std::errc::value_too_large, error.what());   /* EOVERFLOW */
    }
    catch (const std::bad_alloc& error) {
      cpr_fatal_error(std::errc::not_enough_memory, error.what()); /* ENOMEM */
    }
  }

  return string;
}

void
cpr_string_append_char(cpr_string_t* const string,
                       const std::size_t count,
                       const char character) {
  assert(string != nullptr);

  try {
    string->data.append(count, character);
  }
  catch (const std::length_error& error) {
    /* The resulting string length would exceed `max_size`: */
    cpr_logic_error(std::errc::value_too_large, error.what());   /* EOVERFLOW */
  }
  catch (const std::bad_alloc& error) {
    cpr_fatal_error(std::errc::not_enough_memory, error.what()); /* ENOMEM */
  }
}

char*
cpr_string_at(cpr_string_t* const string,
              const std::size_t position) {
  assert(string != nullptr);

  try {
    return const_cast<char*>(&(string->data.at(position)));
  }
  catch (const std::out_of_range& error) {
    cpr_logic_error(std::errc::argument_out_of_domain, error.what()); /* EDOM */
    return nullptr;
  }
}

char*
cpr_string_back(cpr_string_t* const string) {
  assert(string != nullptr);

  if (string->data.empty()) {
    /* Calling #back() on an empty string results in undefined behavior.
     * We'd rather avoid undefined behavior, so we'll just fail gracefully
     * instead: */
    cpr_logic_error(std::errc::bad_address, nullptr); /* EFAULT */
    return nullptr;
  }

  /* Guaranteed to never throw an exception for nonempty strings: */
  return &(string->data.back());
#ifdef DEBUG
  static_assert(noexcept(string->data.back()),
    "std::string::back() declaration is missing the noexcept specifier");
#endif
}

std::size_t
cpr_string_capacity(const cpr_string_t* const string) {
  assert(string != nullptr);

  /* Guaranteed to never throw an exception: */
  return string->data.capacity();
#ifdef DEBUG
  static_assert(noexcept(string->data.capacity()),
    "std::string::capacity() declaration is missing the noexcept specifier");
#endif
}

void
cpr_string_clear(cpr_string_t* const string) {
  assert(string != nullptr);

  /* Guaranteed to never throw an exception: */
  string->data.clear();
#ifdef DEBUG
  static_assert(noexcept(string->data.clear()),
    "std::string::clear() declaration is missing the noexcept specifier");
#endif
}

char*
cpr_string_data(cpr_string_t* const string) {
  assert(string != nullptr);

  /* Guaranteed to never throw an exception: */
  return const_cast<char*>(string->data.data());
#ifdef DEBUG
  static_assert(noexcept(string->data.data()),
    "std::string::data() declaration is missing the noexcept specifier");
#endif
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

void
cpr_string_free(cpr_string_t* const string) {
  if (!string) return;

  /* Guaranteed to never throw an exception: */
  string->~cpr_string();

  cpr_free(string);
}

char*
cpr_string_front(cpr_string_t* const string) {
  assert(string != nullptr);

  if (string->data.empty()) {
    /* Calling #front() on an empty string results in undefined behavior.
     * We'd rather avoid undefined behavior, so we'll just fail gracefully
     * instead: */
    cpr_logic_error(std::errc::bad_address, nullptr); /* EFAULT */
    return nullptr;
  }

  /* Guaranteed to never throw an exception for nonempty strings: */
  return &(string->data.front());
#ifdef DEBUG
  static_assert(noexcept(string->data.front()),
    "std::string::front() declaration is missing the noexcept specifier");
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
  static_assert(noexcept(string->data.max_size()),
    "std::string::max_size() declaration is missing the noexcept specifier");
#endif
}

void
cpr_string_pop_back(cpr_string_t* const string) {
  assert(string != nullptr);

  if (string->data.empty()) {
    /* Calling #pop_back() on an empty string results in undefined behavior.
     * We'd rather avoid undefined behavior, so we'll just fail gracefully
     * instead: */
    cpr_logic_error(std::errc::bad_address, nullptr); /* EFAULT */
    return;
  }

  /* Guaranteed to never throw an exception for nonempty strings: */
  string->data.pop_back();
#ifdef DEBUG
  static_assert(noexcept(string->data.pop_back()),
    "std::string::pop_back() declaration is missing the noexcept specifier");
#endif
}

void
cpr_string_push_back(cpr_string_t* const string,
                     const char character) {
  assert(string != nullptr);

  try {
    string->data.push_back(character);
  }
  catch (const std::length_error& error) {
    /* The resulting string length would exceed `max_size`: */
    cpr_logic_error(std::errc::value_too_large, error.what());   /* EOVERFLOW */
  }
  catch (const std::bad_alloc& error) {
    cpr_fatal_error(std::errc::not_enough_memory, error.what()); /* ENOMEM */
  }
}

void
cpr_string_reserve(cpr_string_t* const string,
                   const std::size_t capacity) {
  assert(string != nullptr);

  try {
    string->data.reserve(capacity);
  }
  catch (const std::length_error& error) {
    /* The resulting string capacity would exceed `max_size`: */
    cpr_logic_error(std::errc::value_too_large, error.what());   /* EOVERFLOW */
  }
  catch (const std::bad_alloc& error) {
    cpr_fatal_error(std::errc::not_enough_memory, error.what()); /* ENOMEM */
  }
}

void
cpr_string_resize(cpr_string_t* const string,
                  const std::size_t size,
                  const char character) {
  assert(string != nullptr);

  try {
    string->data.resize(size, character);
  }
  catch (const std::length_error& error) {
    /* The resulting string length would exceed `max_size`: */
    cpr_logic_error(std::errc::value_too_large, error.what());   /* EOVERFLOW */
  }
  catch (const std::bad_alloc& error) {
    cpr_fatal_error(std::errc::not_enough_memory, error.what()); /* ENOMEM */
  }
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
