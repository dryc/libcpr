``cpr_vector_alloca()``
=======================

Synopsis
--------

.. describe:: #include <cpr/unsafe.h>
.. describe:: #include <cpr/vector.h>

.. c:function:: cpr_vector_t* cpr_vector_alloca(void)

Description
-----------

Returns a pointer to a new stack-allocated ``cpr_vector_t`` structure.

This is a macro that translates into the following code:

.. code-block:: c

   alloca(cpr_vector_sizeof)

Parameters
----------

None.

Return Value
------------

TODO

Errors
------

TODO

Complexity
----------

Constant.

Example
-------

TODO
