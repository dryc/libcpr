*****
Usage
*****

.. index:: ! macros

Macros
======

This chapter describes the C/C++ preprocessor macros that enable the
customization of your use of ``libcpr``.

.. c:macro:: CPR_ABBREV

If defined, enables abbreviated type and function names without the ``cpr_``
prefix. To use these names, ``CPR_ABBREV`` must be defined before including
any of the ``cpr/*.h`` header files, as follows:

.. code-block:: c

   #define CPR_ABBREV
   #include <cpr.h>

.. c:macro:: CPR_UNSAFE

If defined, enables the use of stack allocation for ``libcpr`` data
structures. This is more efficient than heap allocation, but "unsafe" since
it will break the :term:`ABI` should the structure sizes change in a
future ``libcpr`` release.

.. code-block:: c

   #define CPR_UNSAFE
   #include <cpr.h>

Alternatively and equivalently, just include the ``<cpr/unsafe.h>`` header
directly if you prefer the following style:

.. code-block:: c

   #include <cpr.h>
   #include <cpr/unsafe.h>

.. note::

   When the ``<cpr/unsafe.h>`` header is included, the header defines
   ``CPR_UNSAFE`` if it has not yet been defined. This ensures reliable
   conditionalization of code based on ``#ifdef CPR_UNSAFE``, regardless of
   whether the user or the header originally defined this preprocessor
   symbol.
