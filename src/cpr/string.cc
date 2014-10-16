/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "error.h"
#include "string.h"

#include <cassert>      /* for assert() */
#include <cstdlib>      /* for std::calloc(), std::free() */
#include <cstring>      /* for std::strlen() */
#include <new>          /* for std::bad_alloc */
#include <stdexcept>    /* for std::length_error */
#include <string>       /* for std::string */
#include <system_error> /* for std::errc */

////////////////////////////////////////////////////////////////////////////////
/* Internals */

struct cpr_string {
  std::string data;
  cpr_string() : data{} {}
  cpr_string(const char* str) : data{str} {}
};

////////////////////////////////////////////////////////////////////////////////
/* Constants */

const std::size_t cpr_string_sizeof = sizeof(cpr_string_t);
const std::size_t cpr_string_npos   = std::string::npos;

static_assert(std::string::npos == static_cast<std::size_t>(-1),
  "std::string::npos != static_cast<std::size_t>(-1)");

////////////////////////////////////////////////////////////////////////////////
/* Constructor */

cpr_string_t*
cpr_string(const char* const str) {
  cpr_string_t* const string = reinterpret_cast<cpr_string_t*>(cpr_calloc(1, sizeof(cpr_string_t)));

  if (string) {
    try {
      if (!str) {
        new(string) cpr_string_t{};
      }
      else {
        new(string) cpr_string_t{str};
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

////////////////////////////////////////////////////////////////////////////////
/* Destructor */

void
cpr_string_free(cpr_string_t* const string) {
  if (!string) return;

  /* Guaranteed to never throw an exception: */
  string->~cpr_string();

  cpr_free(string);
}

////////////////////////////////////////////////////////////////////////////////
/* Methods */

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

void
cpr_string_append_str(cpr_string_t* const string,
                      const char* const str,
                      const std::size_t length) {
  assert(string != nullptr);
  assert(str != nullptr);

  try {
    string->data.append(str,
      (length == std::string::npos) ? std::strlen(str) : length);
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
cpr_string_append_string(cpr_string_t* const string,
                         const cpr_string_t* const suffix,
                         const std::size_t length) {
  assert(string != nullptr);
  assert(suffix != nullptr);

  try {
    string->data.append(suffix->data, 0, length);
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
cpr_string_assign_char(cpr_string_t* const string,
                       const std::size_t count,
                       const char character) {
  assert(string != nullptr);

  try {
    string->data.assign(count, character);
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
cpr_string_assign_str(cpr_string_t* const string,
                      const char* const str,
                      const std::size_t length) {
  assert(string != nullptr);
  assert(str != nullptr);

  try {
    string->data.assign(str,
      (length == std::string::npos) ? std::strlen(str) : length);
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
cpr_string_assign_string(cpr_string_t* const string,
                         const cpr_string_t* const other,
                         const std::size_t length) {
  assert(string != nullptr);
  assert(other != nullptr);

  try {
    string->data.assign(other->data, 0, length);
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

int
cpr_string_compare(const cpr_string_t* const string1,
                   const cpr_string_t* const string2) {
  assert(string1 != nullptr);
  assert(string2 != nullptr);

  /* Guaranteed to never throw an exception: */
  return string1->data.compare(string2->data);
}

std::size_t
cpr_string_copy(const cpr_string_t* const string,
                char* const buffer,
                const std::size_t position,
                const std::size_t length) {
  assert(string != nullptr);

  try {
    return string->data.copy(buffer, length, position);
  }
  catch (const std::out_of_range& error) {
    cpr_logic_error(std::errc::argument_out_of_domain, error.what()); /* EDOM */
    return 0;
  }
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
cpr_string_erase(cpr_string_t* const string,
                 const std::size_t position,
                 const std::size_t length) {
  assert(string != nullptr);

  // TODO
}

std::size_t
cpr_string_find_char(const cpr_string_t* const string,
                     const char character,
                     const std::size_t position) {
  assert(string != nullptr);

}

std::size_t
cpr_string_find_str(const cpr_string_t* const string,
                    const char* const substr,
                    const std::size_t position,
                    const std::size_t length) {
  assert(string != nullptr);
  assert(substr != nullptr);

}

std::size_t
cpr_string_find_string(const cpr_string_t* const string,
                       const cpr_string_t* const substring,
                       const std::size_t position,
                       const std::size_t length) {
  assert(string != nullptr);
  assert(substring != nullptr);

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

void
cpr_string_insert_char(cpr_string_t* const string,
                       const std::size_t position,
                       const char character,
                       const std::size_t count) {
}

void
cpr_string_insert_str(cpr_string_t* const string,
                      const std::size_t position,
                      const char* const substr,
                      const std::size_t length) {
}

void
cpr_string_insert_string(cpr_string_t* const string,
                         const std::size_t position,
                         const cpr_string_t* const substring,
                         const std::size_t length) {
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
cpr_string_rfind_char(const cpr_string_t* const string,
                      const char character,
                      const std::size_t position) {
  assert(string != nullptr);

}

std::size_t
cpr_string_rfind_str(const cpr_string_t* const string,
                     const char* const substr,
                     const std::size_t position,
                     const std::size_t length) {
  assert(string != nullptr);
  assert(substr != nullptr);

}

std::size_t
cpr_string_rfind_string(const cpr_string_t* const string,
                        const cpr_string_t* const substring,
                        const std::size_t position,
                        const std::size_t length) {
  assert(string != nullptr);
  assert(substring != nullptr);

}

void
cpr_string_shrink_to_fit(cpr_string_t* const string) {
  assert(string != nullptr);

  try {
    return string->data.shrink_to_fit();
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

cpr_string_t*
cpr_string_substr(const cpr_string_t* const string,
                  const std::size_t position,
                  const std::size_t length) {
  // TODO
}

void
cpr_string_swap(cpr_string_t* const string1,
                cpr_string_t* const string2) {
  assert(string1 != nullptr);
  assert(string2 != nullptr);

  /* Guaranteed to never throw an exception: */
  return string1->data.swap(string2->data);
}
