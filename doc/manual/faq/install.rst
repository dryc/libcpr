FAQ: Installation Questions
===========================

This section provides answers and solutions to common installation-related
questions and problems.

.. index:: libc++, libstdc++

**Q:** How do I build the library using ``libc++`` instead of ``libstdc++``?
----------------------------------------------------------------------------

**A:** TODO

.. code-block:: bash

   $ ./configure --with-stdlib=libc++   # sets CXXFLAGS and LDFLAGS

.. index:: GCC, Clang

**Q:** How do I fix ``error: A compiler with support for C++11 language features is required.``?
------------------------------------------------------------------------------------------------

**A:** This error means that your autodetected C++ compiler does not support
the C++11 standard; most likely, the ``./configure`` found an older version
of GCC, such as GCC 4.2 on Mac OS X systems.

If you have a newer compiler available on your system, set the ``CC`` and
``CXX`` environment variables accordingly. For example, to use Clang, you
would configure the ``libcpr`` build as follows:

.. code-block:: bash

   $ CC=clang CXX=clang++ ./configure

If you don't have a C++11 compiler, you will need to obtain one to build
``libcpr``. Please refer to the :doc:`../install` chapter for directions.

.. index:: libc++, libstdc++
.. index:: Mac OS X

**Q:** How do I fix ``fatal error: 'system_error' file not found``?
-------------------------------------------------------------------

**A:** This error means that your C++ compiler is using a pre-C++11 standard
library, most likely an old version of the `libstdc++`_ standard library
that ships with GCC.

The problem here is that for reasons of backwards compatibility, Clang (the
C/C++ compiler on Mac OS X) by default always uses the GCC 4.2-era
``libstdc++`` standard library implementation, which predates the C++11
standard and does not support most C++11 features. This is the case
regardless of whether you specify the ``-std=c++11`` flag when compiling.

If you're on Mac OS X 10.8 (Mountain Lion) or 10.7 (Lion), the fix is
simple: just make sure that the ``CXXFLAGS`` and ``LDFLAGS`` environment
variables also include the flag ``-stdlib=libc++``. This will make Clang use
the C++11-conformant `libc++`_ standard library implementation instead of
the ancient ``libstdc++`` still shipped by Apple. The best way to ensure
this is to configure the ``libcpr`` build as follows:

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
