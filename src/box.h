/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_BOX_H
#define CPRIME_BOX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> /* for int*_t, uint*_t */

/**
 * Represents a boxed value.
 *
 * @see http://en.wikipedia.org/wiki/Object_type_(object-oriented_programming)#Boxing
 * @see http://en.wikipedia.org/wiki/Value_type#Boxing_and_Unboxing
 */
typedef struct box_t {
  const struct box_vtable_t* restrict vtable;
  union {
    int8_t    i8;
    int16_t   i16;
    int32_t   i32;
    int64_t   i64;
    intmax_t  i;
    uint8_t   u8;
    uint16_t  u16;
    uint32_t  u32;
    uint64_t  u64;
    uintmax_t u;
    float     f;
    double    d;
    void*     p;
  } value;
} box_t;

/**
 * Represents a boxed value's virtual dispatch table.
 *
 * @see http://en.wikipedia.org/wiki/Virtual_method_table
 */
typedef struct box_vtable_t {
  const struct class_t* restrict klass;
  const hashable_vtable_t hashable;
  const comparable_vtable_t comparable;
  const iterable_vtable_t iterable;
  int (*init)(box_t* box, va_list args);
  int (*reset)(box_t* box);
  int (*clear)(box_t* box);
} box_vtable_t;

/**
 * Allocates heap memory for a new boxed value.
 */
extern box_t* box_alloc();

/**
 * Releases the heap memory used by a boxed value.
 */
extern void box_free(box_t* box);

/**
 * Initializes a heap-allocated boxed value.
 */
extern int box_init(box_t* restrict box,
  const box_vtable_t* restrict vtable, ...);

/**
 * Resets a boxed value back to an uninitialized state.
 */
extern int box_reset(box_t* box);

/**
 * Clears a boxed value.
 */
extern int box_clear(box_t* box);

/**
 * Returns the byte size of a boxed value.
 */
extern long box_size(const box_t* box);

/**
 * Calculates a hash code for a boxed value.
 */
extern hash_t box_hash(const box_t* box);

/**
 * Compares two boxed values.
 */
extern int box_compare(const box_t* box1, const box_t* box2);

/**
 * Checks whether two boxed values compare equal.
 */
extern bool box_equal(const box_t* box1, const box_t* box2);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_BOX_H */
