.. currentmodule:: cpr_string

``cpr_string_alloca()``
=======================

.. only:: man

   Library
   -------

   libcpr, -lcpr

Synopsis
--------

.. describe:: #include <cpr/unsafe.h>
.. describe:: #include <cpr/string.h>

.. c:function:: cpr_string_t* cpr_string_alloca(void)

Description
-----------

Returns a pointer to a new stack-allocated ``cpr_string_t`` structure.

This is a macro that translates into the following code:

.. code-block:: c

   alloca(cpr_string_sizeof)

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
