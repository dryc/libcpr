.. highlightlang:: c

Sets (``set_t``)
================

.. c:type:: set_t

   Represents a set.

.. c:function:: set_t* set_alloc()

   Allocates heap memory for a new set.

.. c:function:: void set_free(set_t* set)

   Releases the heap memory used by a set.

.. c:function:: int set_init(set_t* set, const class_t* klass, unsigned long element_size, const hash_func_t hash_func, const compare_func_t compare_func, const free_func_t free_func, ...)

   Initializes a set.

.. c:function:: int set_dispose(set_t* set)

   Resets a set back to an uninitialized state.

.. c:function:: int set_clear(set_t* set)

   Removes all elements from a set.

.. c:function:: set_is_empty(const set_t* set)

   Checks whether a set contains any elements.

.. c:function:: long set_count(set_t* set, const void* elt)

   Returns the cardinality of a set.

.. c:function:: bool set_lookup(set_t* set, const void* elt)

   Checks whether a set contains a given element.

.. c:function:: int set_insert(set_t* set, const void* elt)

   Inserts a given element into a set.

.. c:function:: int set_remove(set_t* set, const void* elt)

   Removes a given element from a set.

.. c:function:: int set_replace(set_t* set, const void* restrict elt1, const void* restrict elt2)

   Replaces a given element in a set with another element.
