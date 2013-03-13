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
