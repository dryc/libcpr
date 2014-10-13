.. index:: C++ interoperability

Object Layout
=============

While all ``libcpr`` structure types are opaque to the user (meaning that no
direct access to their internals is afforded), a design guarantee that can
be relied on is that any pointer to a ``libcpr`` object in fact also
corresponds to a pointer to the underlying C++ object that the type is
implemented with.

For example, the opaque ``cpr_vector_t`` type is defined as follows
internally to the library:

.. code-block:: c++

   typedef struct cpr_vector {
     std::vector<void*> data;
     void (*erase_hook)(void*);
   } cpr_vector_t;

Thus, a ``cpr_vector_t*`` pointer in user C code is equivalent to a
``std::vector<void*>*`` pointer or a ``std::vector<void*>&`` reference in
C++ code.

This facilitates C++ interoperability by ensuring that ``libcpr`` objects
can be passed as arguments to C++ functions that expect native C++ standard
library types. In particular, this is helpful for working with functions
that expect an ``std::string`` argument.

The following table explains the relationship between ``libcpr`` object
types and their corresponding internal C++ implementations:

================== =============================================================
C type             C++ type
================== =============================================================
``cpr_list_t*``    ``std::list<void*>&``
``cpr_map_t*``     ``std::map<void*, void*>&``
``cpr_set_t*``     ``std::set<void*>&``
``cpr_string_t*``  ``std::string&`` (aka ``std::basic_string<char>&``)
``cpr_vector_t*``  ``std::vector<void*>&``
================== =============================================================

.. warning::

   You must not let foreign code deallocate any ``libcpr`` object, as that
   might not correctly destruct other fields of the object for types that
   contain additional fields past the first field that holds the internal
   C++ implementation. Similarly, doing so would not invoke the erase hook
   on the pointer of each element in a container object. Destruction and
   deallocation must be done using the ``libcpr`` API only.
