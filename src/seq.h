/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_SEQ_H
#define _CPRIME_SEQ_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */
#include <stddef.h>  /* for size_t */

#define NULLSEQ (&nullseq_class)

/**
 * The base class for sequence classes.
 */
extern const class_t seq_class;
extern const class_t nullseq_class;

/**
 * Represents a sequence.
 *
 * @see http://en.wikipedia.org/wiki/Sequence
 */
typedef struct seq_t {
  const struct seq_vtable_t* restrict vtable;
  void* data;
  size_t length;
  compare_func_t compare_func;
  free_func_t free_func;
} seq_t;

typedef seq_t nullseq_t;

/**
 * Defines a sequence's sort order, for use with `seq_sort()`.
 */
typedef enum seq_sort_type_t {
  SEQ_SORT_NONE = 0,
  SEQ_SORT_ASCENDING,
  SEQ_SORT_DESCENDING,
} seq_sort_type_t;

/**
 * Represents a sequence's virtual dispatch table.
 *
 * @see http://en.wikipedia.org/wiki/Virtual_method_table
 */
typedef struct seq_vtable_t {
  const vtable_t base;
  const hashable_vtable_t hashable;
  const comparable_vtable_t comparable;
  const iterable_vtable_t iterable;
  int (*init)(seq_t* seq, va_list args);
  int (*reset)(seq_t* seq);
  int (*clear)(seq_t* seq);
  long (*length)(seq_t* seq);
  long (*count)(seq_t* restrict seq,
    const void* restrict elt);
  bool (*lookup)(seq_t* restrict seq,
    const void* restrict elt);
  int (*insert)(seq_t* restrict seq,
    const void* restrict elt);
  int (*remove)(seq_t* restrict seq,
    const void* restrict elt);
  int (*replace)(seq_t* restrict seq,
    const void* restrict elt1,
    const void* restrict elt2);
  int (*reverse)(seq_t* seq);
  int (*sort)(seq_t* seq, seq_sort_type_t how);
} seq_vtable_t;

extern const seq_vtable_t nullseq_vtable;

/**
 * Allocates heap memory for a new sequence.
 */
extern seq_t* seq_alloc();

/**
 * Releases the heap memory used by a sequence.
 */
extern void seq_free(seq_t* seq);

/**
 * Initializes a heap-allocated sequence.
 */
extern int seq_init(seq_t* restrict seq,
  const class_t* restrict klass,
  const compare_func_t compare_func,
  const free_func_t free_func, ...);

/**
 * Resets a sequence back to an uninitialized state.
 */
extern int seq_reset(seq_t* seq);

/**
 * Removes all elements from a sequence.
 */
extern int seq_clear(seq_t* seq);

/**
 * Checks whether a sequence contains any elements.
 */
extern bool seq_is_empty(const seq_t* seq);

/**
 * Returns the length of a sequence.
 */
extern long seq_length(seq_t* seq);

/**
 * Counts occurrences of a given element in a sequence.
 */
extern long seq_count(seq_t* restrict seq,
  const void* restrict elt);

/**
 * Checks whether a sequence contains a given element.
 */
extern bool seq_lookup(seq_t* restrict seq,
  const void* restrict elt);

/**
 * Inserts a given element into a sequence.
 */
extern int seq_insert(seq_t* restrict seq,
  const void* restrict elt);

/**
 * Removes a given element from a sequence.
 */
extern int seq_remove(seq_t* restrict seq,
  const void* restrict elt);

/**
 * Replaces a given element in a sequence with another element.
 */
extern int seq_replace(seq_t* restrict seq,
  const void* restrict elt1,
  const void* restrict elt2);

/**
 * Reverses a sequence.
 */
extern int seq_reverse(seq_t* seq);

/**
 * Sorts a sequence in ascending or descending order.
 */
extern int seq_sort(seq_t* seq, seq_sort_type_t how);

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_SEQ_H */
