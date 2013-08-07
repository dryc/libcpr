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

.. cpr:function:: cpr_string_alloca

Description
-----------

.. cpr:summary::

This is a macro that translates into the following code:

.. code-block:: c

   alloca(cpr_string_sizeof)

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
