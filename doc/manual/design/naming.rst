.. index:: conventions; naming

Naming Conventions
==================

The naming conventions and indeed symbol the symbol names themselves are
closely patterned after those of the C++ standard library. This is most
evident when perusing the :doc:`cross-reference <../xref/cxx11>`.

Since C does not support function overloading, C++ standard library methods
which provide multiple overloads are differentiated in ``libcpr`` by
suffixing the corresponding function names with a disambiguating string,
usually a type name. For example ``std::string::append()`` provides multiple
overloads; the corresponding ``libcpr`` functions are provided as
``cpr_string_append_char()`` for a character argument,
``cpr_string_append_str()`` for a C string argument, and so on.
