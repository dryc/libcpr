FAQ: Technical Questions
========================

.. index:: libc++, libstdc++

**Q:** How can I build the library using ``libc++`` instead of ``libstdc++``?
-----------------------------------------------------------------------------

**A:** TODO

.. index:: threads; safety

**Q:** Is the library thread-safe?
----------------------------------

**A:** TODO

.. index:: Autotools, Autoconf, pkg-config

**Q:** How can I detect the library using ``autoconf`` or ``pkg-config``?
-------------------------------------------------------------------------

**A:** TODO

**Q:** Why do I get ``fatal error: 'system_error' file not found`` when building?
---------------------------------------------------------------------------------

**A:** Your C++ compiler is using a pre-C++11 standard library, most likely
an old version of the `libstdc++`_ standard library that ships with GCC.

The problem here is that for reasons of backwards compatibility, Clang (the
C/C++ compiler on Mac OS X) by default always uses the GCC 4.2-era
``libstdc++`` standard library implementation, which predates the C++11
standard and does not support most C++11 features. This is the case
regardless of whether you specify the ``-std=c++11`` flag when compiling.

If you're on Mac OS X 10.8 (Mountain Lion) or 10.7 (Lion), the fix is
simple: just make sure that ``CXXFLAGS`` and ``LDFLAGS`` also include the
flag ``-stdlib=libc++``. This will make Clang use the C++11-conformant
`libc++`_ standard library implementation instead of the ancient
``libstdc++`` still shipped by Apple. The best way to ensure this is to
configure the ``libcpr`` build as follows:

.. code-block:: bash

   $ ./configure --with-stdlib=libc++   # sets CXXFLAGS and LDFLAGS

For more information, refer to the :doc:`../install/config` section.

However, if you're on Mac OS X 10.6 (Snow Leopard), 10.5 (Leopard), or 10.4
(Tiger), the aforementioned in and of itself will not help you since Apple
did not yet ship ``libc++`` with these earlier operating system releases.
You will therefore need to manually upgrade your toolchain for C++11 support.
Please refer to the :doc:`../install/darwin` section for particulars.

.. _libc++:    http://libcxx.llvm.org/
.. _libstdc++: http://gcc.gnu.org/libstdc++/
