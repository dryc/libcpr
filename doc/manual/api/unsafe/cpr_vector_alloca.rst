.. currentmodule:: cpr_vector

``cpr_vector_alloca()``
=======================

.. only:: man

   Library
   -------

   libcpr, -lcpr

Synopsis
--------

.. describe:: #include <cpr/unsafe.h>
.. describe:: #include <cpr/vector.h>

.. c:function:: cpr_vector_t* cpr_vector_alloca(void)

.. cpr:function:: cpr_vector_alloca

Description
-----------

.. cpr:summary::

This is a macro that translates into the following code:

.. code-block:: c

   alloca(cpr_vector_sizeof)

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
