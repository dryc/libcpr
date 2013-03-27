.. index:: emplacement; operations
.. _emplacement:

Emplacement Operations
======================

Since the elements stored by ``libcpr`` containers are ``void*`` pointers,
the library does not provide any analogues of the `emplacement operations`__
from the C++11 standard library.

__ http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2345.pdf

That said, ``libcpr`` containers *can* also be (ab)used to directly store
machine-word-sized value types, such as integers or floating-point numbers;
in such a case, the ordinary insertion operations work equivalently to
emplacement operations with the help of a little type casting:

.. code-block:: c

   /* Store the integer 42 in a vector directly: */
   cpr_vector_push_back(vector, (void*)(long)42);
