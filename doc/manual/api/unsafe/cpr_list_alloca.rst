.. currentmodule:: cpr_list

``cpr_list_alloca()``
=======================

.. only:: man

   Library
   -------

   libcpr, -lcpr

Synopsis
--------

.. describe:: #include <cpr/unsafe.h>
.. describe:: #include <cpr/list.h>

.. c:function:: cpr_list_t* cpr_list_alloca(void)

Description
-----------

Returns a pointer to a new stack-allocated ``cpr_list_t`` structure.

This is a macro that translates into the following code:

.. code-block:: c

   alloca(cpr_list_sizeof)

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
