.. highlightlang:: c

Sequences (``seq_t``)
=====================

.. c:type:: seq_t

   Represents a sequence.

.. c:type:: seq_sort_type_t

   Defines a sequence's sort order, for use with :c:func:`seq_sort`.

.. c:function:: seq_t* seq_alloc()

   Allocates heap memory for a new sequence.

.. c:function:: void seq_free(seq_t* seq)

   Releases the heap memory used by a sequence.

.. c:function:: int seq_init(seq_t* seq, const class_t* klass, const compare_func_t compare_func, const free_func_t free_func, ...)

   Initializes a heap-allocated sequence.

.. c:function:: int seq_dispose(seq_t* seq)

   Resets a sequence back to an uninitialized state.

.. c:function:: int seq_clear(seq_t* seq)

   Removes all elements from a sequence.

.. c:function:: seq_is_empty(const seq_t* seq)

   Checks whether a sequence contains any elements.

.. c:function:: long seq_length(seq_t* seq)

   Returns the length of a sequence.

.. c:function:: long seq_count(seq_t* seq, const void* elt)

   Counts occurrences of a given element in a sequence.

.. c:function:: bool seq_lookup(seq_t* seq, const void* elt)

   Checks whether a sequence contains a given element.

.. c:function:: int seq_insert(seq_t* seq, const void* elt)

   Inserts a given element into a sequence.

.. c:function:: int seq_remove(seq_t* seq, const void* elt)

   Removes a given element from a sequence.

.. c:function:: int seq_replace(seq_t* seq, const void* restrict elt1, const void* restrict elt2)

   Replaces a given element in a sequence with another element.

.. c:function:: int seq_reverse(seq_t* seq)

   Reverses a sequence.

.. c:function:: int seq_sort(seq_t* seq, seq_sort_type_t how)

   Sorts a sequence in ascending or descending order.
