.. index:: configuration; options

Configuration Options
=====================

This section documents ``libcpr``-specific command-line options that may be
passed to the ``./configure`` script to customize the build of the library.

C++ Standard Library
--------------------

The following options can be used to specify the C++ standard library
implementation to use for the build. By default, when this option is not
given, the system C++ standard library is used. On Unix platforms based on
the GNU toolchain, the system library is ``libstdc++``.

.. index:: libc++, libstdc++

``--with-stdlib=libstdc++``
   Use the `libstdc++`_ standard library from the GCC project.
   This is the default with both the GCC and Clang compilers.

``--with-stdlib=libc++``
   Use the `libc++`_ standard library from the LLVM project.
   You almost certainly want to specify this on recent versions of FreeBSD
   and Mac OS X, and you may wish to use it on Linux if it is available.

.. note::

   When both are available, the choice between ``libstdc++`` and ``libc++``
   is easy: use ``libc++`` due to its comprehensive C++11 support, its
   favorable performance and memory footprint characteristics, and its
   permissive licensing.

.. _libc++:    http://libcxx.llvm.org/
.. _libstdc++: http://gcc.gnu.org/libstdc++/

Debugging Support
-----------------

The following options are meant primarily for ``libcpr`` developers:

``--enable-debug``
   Build with debugging support.
   Debugging is disabled by default.

``--disable-assert``
   Turn off assertions specifically.
   Assertions are disabled by default.

Advanced Customization
----------------------

You should not ordinarily need to use the following options. They are
provided for special situations such as e.g. compiling a minimal static
library version of ``libcpr`` for an embedded platform.

``--disable-list``
   Do not include the :doc:`list <../api/list>` module.
   The module is included by default.

``--disable-map``
   Do not include the :doc:`map <../api/map>` module.
   The module is included by default.

``--disable-set``
   Do not include the :doc:`set <../api/set>` module.
   The module is included by default.

``--disable-string``
   Do not include the :doc:`string <../api/string>` module.
   The module is included by default.

``--disable-vector``
   Do not include the :doc:`vector <../api/vector>` module.
   The module is included by default.

.. note::

   An alternative to building a reduced-functionality version of ``libcpr``
   is to just copy over into your project those ``libcpr`` header and
   implementation files you require. They are all in the public domain.
