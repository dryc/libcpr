``<cpr/string.h>``
==================

.. c:type:: cpr_string_t

An opaque type representing a dynamic string.

.. c:var:: const size_t cpr_string_sizeof

The size of the :c:type:`cpr_string_t` opaque type, i.e., ``sizeof(cpr_string_t)``.

.. c:function:: cpr_string_t* cpr_string_alloc(void)

Returns a pointer to a new heap-allocated ``cpr_string_t`` structure.

.. c:function:: void cpr_string_free(cpr_string_t* string)
