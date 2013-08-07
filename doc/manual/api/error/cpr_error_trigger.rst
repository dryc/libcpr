.. currentmodule:: cpr_error

``cpr_error_trigger()``
=======================

.. only:: man

   Library
   -------

   libcpr, -lcpr

Synopsis
--------

.. describe:: #include <cpr/error.h>

.. cpr:function:: cpr_error_trigger

Description
-----------

.. cpr:summary::

Parameters
----------

.. cpr:params::

Return Value
------------

.. cpr:return::

Errors
------

This function sets ``errno`` to the value given in the ``error_code``
argument.

Complexity
----------

Constant.

Example
-------

.. code-block:: c

   cpr_error_trigger(__func__, ENOMEM, "out of memory");
