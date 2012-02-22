/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_ATOM_H
#define CPRIME_ATOM_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Atomic counters and operations.
 *
 * @see http://en.wikipedia.org/wiki/Linearizability#Primitive_atomic_instructions
 * @see http://en.wikipedia.org/wiki/Fetch-and-add
 * @see http://en.wikipedia.org/wiki/Compare-and-swap
 */

#include <stdint.h>             /* for int*_t, INT*_MIN, INT*_MAX */

#define ATOM8_SIZE              sizeof(int8_t)
#define ATOM8_MIN               INT8_MIN
#define ATOM8_MAX               INT8_MAX

typedef struct atom8_t {
  volatile int8_t counter;
} atom8_t;

#define ATOM16_SIZE             sizeof(int16_t)
#define ATOM16_MIN              INT16_MIN
#define ATOM16_MAX              INT16_MAX

typedef struct atom16_t {
  volatile int16_t counter;
} atom16_t;

#define ATOM32_SIZE             sizeof(int32_t)
#define ATOM32_MIN              INT32_MIN
#define ATOM32_MAX              INT32_MAX

typedef struct atom32_t {
  volatile int32_t counter;
} atom32_t;

#define ATOM64_SIZE             sizeof(int64_t)
#define ATOM64_MIN              INT64_MIN
#define ATOM64_MAX              INT64_MAX

typedef struct atom64_t {
  volatile int64_t counter;
} atom64_t;

/**
 * Initializes a statically-allocated atomic counter.
 */
#define ATOM_INIT(value)        {.counter = (value)}

/**
 * Loads the value of an atomic counter.
 */
#define ATOM_GET(atom)          ((atom)->counter)

/**
 * Stores a value in an atomic counter.
 */
#define ATOM_SET(atom, value)   ((atom)->counter = (value))

/**
 * Adds an integer to an atomic counter.
 */
#define ATOM_ADD(atom, count) \
  ((void)__sync_add_and_fetch(&(atom)->counter, count))

/**
 * Adds an integer to an atomic counter, returning the old value.
 */
#define ATOM_GET_AND_ADD(atom, count) \
  (__sync_fetch_and_add(&(atom)->counter, count))

/**
 * Adds an integer to an atomic counter, returning the new value.
 */
#define ATOM_ADD_AND_GET(atom, count) \
  (__sync_add_and_fetch(&(atom)->counter, count))

/**
 * Subtracts an integer from an atomic counter.
 */
#define ATOM_SUB(atom, count) \
  ((void)__sync_sub_and_fetch(&(atom)->counter, count))

/**
 * Subtracts an integer from an atomic counter, returning the old value.
 */
#define ATOM_GET_AND_SUB(atom, count) \
  (__sync_fetch_and_sub(&(atom)->counter, count))

/**
 * Subtracts an integer from an atomic counter, returning the new value.
 */
#define ATOM_SUB_AND_GET(atom, count) \
  (__sync_sub_and_fetch(&(atom)->counter, count))

/**
 * Subtracts an integer from an atomic counter, returning TRUE if the new
 * value is zero.
 */
#define ATOM_SUB_AND_TEST(atom, count) \
  (__sync_sub_and_fetch(&(atom)->counter, count) == 0)

/**
 * Increments an atomic counter.
 */
#define ATOM_INC(atom)          ATOM_ADD(atom, 1)

/**
 * Increments an atomic counter, returning the old value.
 */
#define ATOM_GET_AND_INC(atom)  ATOM_GET_AND_ADD(atom, 1)

/**
 * Increments an atomic counter, returning the new value.
 */
#define ATOM_INC_AND_GET(atom)  ATOM_ADD_AND_GET(atom, 1)

/**
 * Decrements an atomic counter.
 */
#define ATOM_DEC(atom)          ATOM_SUB(atom, 1)

/**
 * Decrements an atomic counter, returning the old value.
 */
#define ATOM_GET_AND_DEC(atom)  ATOM_GET_AND_SUB(atom, 1)

/**
 * Decrements an atomic counter, returning the new value.
 */
#define ATOM_DEC_AND_GET(atom)  ATOM_SUB_AND_GET(atom, 1)

/**
 * Decrements an atomic counter, returning TRUE if the new value is zero.
 */
#define ATOM_DEC_AND_TEST(atom) ATOM_SUB_AND_TEST(atom, 1)

/**
 * Stores a new value in an atomic counter if and only if its old value
 * equals the expected one. Returns the old value.
 */
#define ATOM_CMP_AND_SWAP(atom, old_value, new_value) \
  (__sync_val_compare_and_swap(&(atom)->counter, old_value, new_value))

/**
 * Stores a new value in an atomic counter if and only if its old value
 * equals the expected one. Returns TRUE if the operation succeeded.
 */
#define ATOM_CMP_AND_SET(atom, old_value, new_value) \
  (__sync_bool_compare_and_swap(&(atom)->counter, old_value, new_value))

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_ATOM_H */
