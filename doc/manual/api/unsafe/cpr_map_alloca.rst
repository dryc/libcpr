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

.. cpr:function:: cpr_map_alloca

Description
-----------

.. cpr:summary::

This is a macro that translates into the following code:

.. code-block:: c

   alloca(cpr_map_sizeof)

.. cpr:warning::

Parameters
----------

.. cpr:params::

Return Value
------------

.. cpr:return::

Errors
------

.. cpr:errors::

Complexity
----------

Constant.

Example
-------

TODO
