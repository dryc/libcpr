.. currentmodule:: cpr_set

``cpr_set_alloca()``
=======================

.. only:: man

   Library
   -------

   libcpr, -lcpr

Synopsis
--------

.. describe:: #include <cpr/unsafe.h>
.. describe:: #include <cpr/set.h>

.. c:function:: cpr_set_t* cpr_set_alloca(void)

Description
-----------

Returns a pointer to a new stack-allocated ``cpr_set_t`` structure.

This is a macro that translates into the following code:

.. code-block:: c

   alloca(cpr_set_sizeof)

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
