.. currentmodule:: cpr_map

``cpr_map_alloca()``
=======================

.. only:: man

   Library
   -------

   libcpr, -lcpr

Synopsis
--------

.. describe:: #include <cpr/unsafe.h>
.. describe:: #include <cpr/map.h>

.. c:function:: cpr_map_t* cpr_map_alloca(void)

Description
-----------

Returns a pointer to a new stack-allocated ``cpr_map_t`` structure.

This is a macro that translates into the following code:

.. code-block:: c

   alloca(cpr_map_sizeof)

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
