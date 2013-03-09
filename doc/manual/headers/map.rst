``<cpr/map.h>``
===============

.. c:type:: cpr_map_t

An opaque type representing a key-value map.

.. c:var:: const size_t cpr_map_sizeof

The size of the :c:type:`cpr_map_t` opaque type, i.e., ``sizeof(cpr_map_t)``.

.. c:function:: cpr_map_t* cpr_map_alloc(void)

Returns a pointer to a new heap-allocated ``cpr_map_t`` structure.

.. c:function:: void cpr_map_free(cpr_map_t* map)
