FAQ: Technical Questions
========================

This section collects answers to frequently-asked miscellaneous technical
questions regarding the ``libcpr`` library.

.. index:: naming

**Q:** Why are all exported symbols prefixed with ``cpr_``?
-----------------------------------------------------------

**A:** TODO

.. index:: threads; safety

**Q:** Is the library thread-safe?
----------------------------------

**A:** TODO

.. index:: Autotools, Autoconf, pkg-config

**Q:** How can I detect the library using ``autoconf`` or ``pkg-config``?
-------------------------------------------------------------------------

**A:** TODO

**Q:** Why are preconditions enforced using assertions?
-------------------------------------------------------

**A:** TODO

**Q:** Why does the build fail with the error ``‘std::string’ has no member named ‘pop_back’``?
-----------------------------------------------------------------------------------------------

**A:** This indicates that your C++ standard library does not support the
C++11 standard. This is the case for example with the version of
``libstdc++`` shipped with GCC 4.6. To build ``libcpr`` successfully, you
will need to upgrade your C++ compiler and/or standard library.
