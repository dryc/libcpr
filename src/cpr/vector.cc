/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "error.h"
#include "string.h"
#include "vector.h"

#include <cassert>      /* for assert() */
#include <cstdarg>      /* for std::va_list, va_*() */
#include <cstdlib>      /* for std::calloc(), std::free() */
#include <new>          /* for std::bad_alloc */
#include <stdexcept>    /* for std::length_error, std::out_of_range */
#include <system_error> /* for std::errc */
#include <vector>       /* for std::vector */

////////////////////////////////////////////////////////////////////////////////
/* Internals */

struct cpr_vector {
  std::vector<void*> data;
  void (*erase_hook)(void*);

  cpr_vector()
    : data{}, erase_hook{nullptr} {}

  cpr_vector(void (*erase_hook)(void*))
    : data{}, erase_hook{erase_hook} {}

  cpr_vector(std::size_t size, void (*erase_hook)(void*))
    : data{size}, erase_hook{erase_hook} {}
};

////////////////////////////////////////////////////////////////////////////////
/* Constants */

extern const size_t cpr_vector_sizeof = sizeof(cpr_vector_t);

////////////////////////////////////////////////////////////////////////////////
/* Constructors */

cpr_vector_t*
cpr_vector(const void* element, ...) {
  cpr_vector_t* const vector = cpr_vector_alloc();
  if (!vector) return nullptr;

  /* Should never throw an exception: */
  new(vector) cpr_vector_t();

  if (element) {
    std::va_list arguments;

    va_start(arguments, element);

    try {
      for (; element; element = va_arg(arguments, const void*)) {
        vector->data.push_back(const_cast<void*>(element));
      }
    }
    catch (const std::bad_alloc& error) {
      cpr_fatal_error(std::errc::not_enough_memory, error.what()); /* ENOMEM */
    }

    va_end(arguments);
  }

  return vector;
}

cpr_vector_t*
cpr_vector_of_strings(cpr_string_t* element, ...) {
  cpr_vector_t* const vector = cpr_vector_alloc();
  if (!vector) return nullptr;

  /* Should never throw an exception: */
  new(vector) cpr_vector_t(reinterpret_cast<void (*)(void*)>(cpr_string_free));

  if (element) {
    std::va_list arguments;

    va_start(arguments, element);

    try {
      for (; element; element = va_arg(arguments, cpr_string_t*)) {
        vector->data.push_back(element);
      }
    }
    catch (const std::bad_alloc& error) {
      cpr_fatal_error(std::errc::not_enough_memory, error.what()); /* ENOMEM */
    }

    va_end(arguments);
  }

  return vector;
}

cpr_vector_t*
cpr_vector_of_vectors(cpr_vector_t* element, ...) {
  cpr_vector_t* const vector = cpr_vector_alloc();
  if (!vector) return nullptr;

  /* Should never throw an exception: */
  new(vector) cpr_vector_t(reinterpret_cast<void (*)(void*)>(cpr_vector_free));

  if (element) {
    std::va_list arguments;

    va_start(arguments, element);

    try {
      for (; element; element = va_arg(arguments, cpr_vector_t*)) {
        vector->data.push_back(element);
      }
    }
    catch (const std::bad_alloc& error) {
      cpr_fatal_error(std::errc::not_enough_memory, error.what()); /* ENOMEM */
    }

    va_end(arguments);
  }

  return vector;
}

cpr_vector_t*
cpr_vector_alloc(void) {
  cpr_vector_t* const vector = reinterpret_cast<cpr_vector_t*>(cpr_calloc(1, sizeof(cpr_vector_t)));

  if (!vector) {
    cpr_fatal_error(std::errc::not_enough_memory, nullptr); /* ENOMEM */
  }

  return vector;
}

////////////////////////////////////////////////////////////////////////////////
/* Destructor */

void
cpr_vector_free(cpr_vector_t* const vector) {
  cpr_free(vector);
}

////////////////////////////////////////////////////////////////////////////////

void
cpr_vector_init(cpr_vector_t* const vector,
                void (*erase_hook)(void*)) {
  assert(vector != nullptr);

  /* Should never throw an exception: */
  new(vector) cpr_vector_t{erase_hook};
}

void
cpr_vector_init_with_capacity(cpr_vector_t* const vector,
                              void (*erase_hook)(void*),
                              const std::size_t capacity) {
  assert(vector != nullptr);

  try {
    new(vector) cpr_vector_t(capacity, erase_hook);
  }
  catch (const std::bad_alloc&) {
    cpr_fatal_error(std::errc::not_enough_memory, nullptr); /* ENOMEM */
    return; /* vector remains uninitalized */
  }

  /* This sets the size to zero, but retains the initial capacity: */
  if (capacity > 0) {
    vector->data.clear();
  }
}

void
cpr_vector_dispose(cpr_vector_t* const vector) {
  assert(vector != nullptr);

  /* Call the erase hook on all elements: */
  if (vector->erase_hook != nullptr) {
    for (void* const element : vector->data) {
      vector->erase_hook(element);
    }
  }

  /* Guaranteed to never throw an exception: */
  vector->~cpr_vector();
}

////////////////////////////////////////////////////////////////////////////////
/* Methods */

bool
cpr_vector_empty(const cpr_vector_t* const vector) {
  assert(vector != nullptr);

  /* Guaranteed to never throw an exception: */
  return vector->data.empty();
#ifdef DEBUG
  static_assert(noexcept(vector->data.empty()),
    "std::vector::empty() declaration is missing the noexcept specifier");
#endif
}

size_t
cpr_vector_size(const cpr_vector_t* const vector) {
  assert(vector != nullptr);

  /* Guaranteed to never throw an exception: */
  return vector->data.size();
#ifdef DEBUG
  static_assert(noexcept(vector->data.size()),
    "std::vector::size() declaration is missing the noexcept specifier");
#endif
}

size_t
cpr_vector_capacity(const cpr_vector_t* const vector) {
  assert(vector != nullptr);

  /* Guaranteed to never throw an exception: */
  return vector->data.capacity();
#ifdef DEBUG
  static_assert(noexcept(vector->data.capacity()),
    "std::vector::capacity() declaration is missing the noexcept specifier");
#endif
}

void*
cpr_vector_data(const cpr_vector_t* const vector) {
  assert(vector != nullptr);

  /* Guaranteed to never throw an exception: */
  return const_cast<cpr_vector_t*>(vector)->data.data();
#ifdef DEBUG
  static_assert(noexcept(vector->data.data()),
    "std::vector::data() declaration is missing the noexcept specifier");
#endif
}

void*
cpr_vector_at(const cpr_vector_t* const vector,
              const size_t position) {
  assert(vector != nullptr);

  try {
    return vector->data.at(position);
  }
  catch (const std::out_of_range&) {
    cpr_logic_error(std::errc::argument_out_of_domain, nullptr); /* EDOM */
    return nullptr;
  }
}

void*
cpr_vector_front(const cpr_vector_t* const vector) {
  assert(vector != nullptr);

  if (vector->data.empty()) {
    /* Calling #front() on an empty vector results in undefined behavior.
     * We'd rather avoid undefined behavior, so we'll return NULL instead: */
    cpr_logic_error(std::errc::bad_address, nullptr); /* EFAULT */
    return nullptr;
  }

  /* Guaranteed to never throw an exception for nonempty vectors: */
  return vector->data.front();
}

void*
cpr_vector_back(const cpr_vector_t* const vector) {
  assert(vector != nullptr);

  if (vector->data.empty()) {
    /* Calling #back() on an empty vector results in undefined behavior.
     * We'd rather avoid undefined behavior, so we'll return NULL instead: */
    cpr_logic_error(std::errc::bad_address, nullptr); /* EFAULT */
    return nullptr;
  }

  /* Guaranteed to never throw an exception for nonempty vectors: */
  return vector->data.back();
}

void
cpr_vector_reserve(cpr_vector_t* const vector,
                   const size_t capacity) {
  assert(vector != nullptr);

  try {
    vector->data.reserve(capacity);
  }
  catch (const std::length_error&) {
    cpr_logic_error(std::errc::invalid_argument, nullptr);  /* EINVAL */
  }
  catch (const std::bad_alloc&) {
    cpr_fatal_error(std::errc::not_enough_memory, nullptr); /* ENOMEM */
  }
}

void
cpr_vector_clear(cpr_vector_t* const vector) {
  assert(vector != nullptr);

  /* Call the erase hook on all elements: */
  if (vector->erase_hook != nullptr) {
    for (void* const element : vector->data) {
      vector->erase_hook(element);
    }
  }

  /* Guaranteed to never throw an exception: */
  vector->data.clear();
#ifdef DEBUG
  static_assert(noexcept(vector->data.clear()),
    "std::vector::clear() declaration is missing the noexcept specifier");
#endif
}

void
cpr_vector_push_back(cpr_vector_t* const vector,
                     const void* const element) {
  assert(vector != nullptr);
  assert(element != nullptr);

  try {
    vector->data.push_back(const_cast<void*>(element));
  }
  catch (const std::bad_alloc&) {
    cpr_fatal_error(std::errc::not_enough_memory, nullptr); /* ENOMEM */
  }
}

void
cpr_vector_pop_back(cpr_vector_t* const vector) {
  assert(vector != nullptr);

  if (vector->data.empty()) {
    /* Calling #pop_back() on an empty vector results in undefined behavior.
     * We'd rather avoid undefined behavior, so we'll just fail gracefully
     * instead: */
    cpr_logic_error(std::errc::bad_address, nullptr); /* EFAULT */
    return;
  }

  /* Call the erase hook on the last element: */
  if (vector->erase_hook != nullptr) {
    /* Guaranteed to never throw an exception for nonempty vectors: */
    vector->erase_hook(vector->data.back());
  }

  /* Guaranteed to never throw an exception for nonempty vectors: */
  vector->data.pop_back();
}
