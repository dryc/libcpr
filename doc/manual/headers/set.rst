``<cpr/set.h>``
===============

.. c:type:: cpr_set_t

An opaque type representing a set of elements.

.. c:var:: const size_t cpr_set_sizeof

The size of the :c:type:`cpr_set_t` opaque type, i.e., ``sizeof(cpr_set_t)``.

.. c:function:: cpr_set_t* cpr_set_alloc(void)

.. c:function:: void cpr_set_free(cpr_set_t* set)
