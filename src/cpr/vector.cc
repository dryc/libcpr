/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "cpr/vector.h"

#include <cerrno>       /* for errno */
#include <cstdlib>      /* for std::calloc(), std::free() */
#include <new>          /* for std::bad_alloc */
#include <stdexcept>    /* for std::length_error, std::out_of_range */
#include <system_error> /* for std::errc */
#include <vector>       /* for std::vector */

struct cpr_vector : public std::vector<void*> {};

extern const size_t cpr_vector_sizeof = sizeof(cpr_vector);

cpr_vector*
cpr_vector_alloc(void) {
  return reinterpret_cast<cpr_vector*>(std::calloc(1, sizeof(cpr_vector)));
}

void
cpr_vector_free(cpr_vector* const vector) {
  std::free(vector);
}

void
cpr_vector_init(cpr_vector* const vector) {
  new(vector) cpr_vector(); // TODO: handle exceptions?
}

void
cpr_vector_dispose(cpr_vector* const vector) {
  /* Guaranteed to never throw an exception: */
  vector->~cpr_vector();
}

bool
cpr_vector_empty(const cpr_vector* const vector) {
  /* Guaranteed to never throw an exception: */
  return vector->empty();
#ifdef DEBUG
  static_assert(noexcept(vector->empty()),
    "std::vector::empty() declaration is missing the noexcept specifier");
#endif
}

size_t
cpr_vector_size(const cpr_vector* const vector) {
  /* Guaranteed to never throw an exception: */
  return vector->size();
#ifdef DEBUG
  static_assert(noexcept(vector->size()),
    "std::vector::size() declaration is missing the noexcept specifier");
#endif
}

size_t
cpr_vector_capacity(const cpr_vector* const vector) {
  /* Guaranteed to never throw an exception: */
  return vector->capacity();
#ifdef DEBUG
  static_assert(noexcept(vector->capacity()),
    "std::vector::capacity() declaration is missing the noexcept specifier");
#endif
}

void*
cpr_vector_data(const cpr_vector* const vector) {
  /* Guaranteed to never throw an exception: */
  return const_cast<cpr_vector*>(vector)->data();
#ifdef DEBUG
  static_assert(noexcept(vector->data()),
    "std::vector::data() declaration is missing the noexcept specifier");
#endif
}

void*
cpr_vector_at(const cpr_vector* const vector,
              const size_t position) {
  try {
    return vector->at(position);
  }
  catch (const std::out_of_range& error) {
    errno = static_cast<int>(std::errc::argument_out_of_domain); /* EDOM */
    return nullptr;
  }
}

void
cpr_vector_reserve(cpr_vector* const vector,
                   const size_t capacity) {
  try {
    vector->reserve(capacity);
  }
  catch (const std::length_error& error) {
    errno = static_cast<int>(std::errc::invalid_argument); /* EINVAL */
  }
}

void
cpr_vector_clear(cpr_vector* const vector) {
  /* Guaranteed to never throw an exception: */
  vector->clear();
#ifdef DEBUG
  static_assert(noexcept(vector->clear()),
    "std::vector::clear() declaration is missing the noexcept specifier");
#endif
}

void
cpr_vector_push_back(cpr_vector* const vector,
                     const void* const element) {
  try {
    vector->push_back(const_cast<void*>(element));
  }
  catch (const std::bad_alloc& error) {
    errno = static_cast<int>(std::errc::not_enough_memory); /* ENOMEM */
  }
}

void
cpr_vector_pop_back(cpr_vector* const vector) {
  if (vector->empty()) {
    /* Invoking #pop_back() on an empty vector is defined to result in
     * undefined behavior. We'd rather avoid undefined behavior, so we'll
     * just fail gracefully instead. */
    errno = static_cast<int>(std::errc::bad_address); /* EFAULT */
    return;
  }
  /* Guaranteed to never throw an exception: */
  vector->pop_back();
#if 0
  static_assert(noexcept(vector->pop_back()),
    "std::vector::pop_back() declaration is missing the noexcept specifier");
#endif
}
