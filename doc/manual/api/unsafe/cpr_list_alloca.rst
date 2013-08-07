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

.. cpr:function:: cpr_list_alloca

Description
-----------

.. cpr:summary::

This is a macro that translates into the following code:

.. code-block:: c

   alloca(cpr_list_sizeof)

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
