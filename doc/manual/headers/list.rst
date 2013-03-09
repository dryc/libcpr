``<cpr/list.h>``
================

.. c:type:: cpr_list_t

An opaque type representing a doubly-linked list.

.. c:var:: const size_t cpr_list_sizeof

The size of the :c:type:`cpr_list_t` opaque type, i.e., ``sizeof(cpr_list_t)``.

.. c:function:: cpr_list_t* cpr_list_alloc(void)

.. c:function:: void cpr_list_free(cpr_list_t* list)
