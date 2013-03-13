``cpr_error_trigger()``
=======================

.. only:: man

   Library
   -------

   libcpr, -lcpr

Synopsis
--------

.. describe:: #include <cpr/error.h>

.. c:function:: void cpr_error_trigger(const char* caller_name, int error_code, const char* error_message, ...)

Description
-----------

Sets ``errno`` and invokes the error callback function.

Parameters
----------

``caller_name``
   TODO

``error_code``
   TODO

``error_message``
   TODO

Return Value
------------

None.

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
