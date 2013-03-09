``<cpr/vector.h>``
==================

.. c:type:: cpr_vector_t

.. c:var:: const size_t cpr_vector_sizeof

The size of the :c:type:`cpr_vector_t` opaque type, i.e., ``sizeof(cpr_vector_t)``.

.. c:function:: cpr_vector_t* cpr_vector_alloc(void)

.. c:function:: void cpr_vector_free(cpr_vector_t* vector)

.. c:function:: void cpr_vector_init(cpr_vector_t* vector)

.. c:function:: void cpr_vector_dispose(cpr_vector_t* vector)

.. c:function:: bool cpr_vector_empty(const cpr_vector_t* vector)

Tests whether a vector is empty, i.e., whether its size is 0.

.. c:function:: size_t cpr_vector_size(const cpr_vector_t* vector)

Returns the number of elements in a vector.

.. c:function:: size_t cpr_vector_capacity(const cpr_vector_t* vector)

Returns the number of elements that a vector has allocated space for.

.. c:function:: void* cpr_vector_data(const cpr_vector_t* vector)

Returns a direct pointer to a vector's internal memory array.

.. c:function:: void* cpr_vector_at(cpr_vector_t* vector, size_t position);

Returns a pointer to the element at the given position in a vector.

.. c:function:: void cpr_vector_reserve(cpr_vector_t* vector, size_t capacity)

Adjusts the minimum capacity of a vector, allocating storage if necessary.

.. c:function:: void cpr_vector_clear(cpr_vector_t* vector)

Removes all elements from a vector, leaving its size zero.

.. c:function:: void cpr_vector_push_back(cpr_vector_t* vector, const void* element)

Adds a new element at the end of a vector, after its current last element.

.. c:function:: void cpr_vector_pop_back(cpr_vector_t* vector)

Removes the last element in a vector, reducing the vector's size by one.
