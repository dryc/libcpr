``cpr_vector_alloca()``
=======================

.. c:function:: cpr_vector_t* cpr_vector_alloca(void)

Returns a pointer to a new stack-allocated ``cpr_vector_t`` structure.

This is a macro that translates into the following code:

.. code-block:: c

   alloca(cpr_vector_sizeof)
