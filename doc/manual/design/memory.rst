.. index:: memory; management
.. _memory-management:

Memory Management
=================

All constructor functions return pointers to opaque structures allocated on
the program heap using the system's standard ``calloc()`` facility. The
library provides corresponding deallocation functions to destruct and free
these pointers.

Given that all object pointers are to opaque structures, no direct access to
any structure fields is permitted or afforded; all access is procedural. This
encapsulation facilitates and ensures ABI stability as the library evolves.

.. index:: initialization, finalization
.. _initialization:

Initialization and Finalization
-------------------------------
