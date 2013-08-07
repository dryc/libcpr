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

.. cpr:function:: cpr_set_alloca

Description
-----------

.. cpr:summary::

This is a macro that translates into the following code:

.. code-block:: c

   alloca(cpr_set_sizeof)

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
