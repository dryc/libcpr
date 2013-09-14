.. index:: pair: installation; Mac OS X

Installation on Mac OS X
========================

This section describes how to build and install ``libcpr`` on Mac OS X.

Prerequisites
-------------

To build and install ``libcpr`` from source on Mac OS X, you need an
up-to-date toolchain that supports the C++11 standard; that is, you need a
recent enough C++ compiler and a C++11-conformant standard library. This
means either `Clang`_ 3.0+ with `libc++`_, or `GCC`_ 4.7+ with
`libstdc++`_.

Apple's free `Xcode`_ 4.6+ developer tools for Mac OS X 10.8 (Mountain
Lion) and 10.7 (Lion) include recent enough Clang and libc++ releases that
will work. You don't need the full Xcode installation, only the Command Line
Tools for Xcode.

On Mac OS X 10.6 (Snow Leopard), 10.5 (Leopard), or 10.4 (Tiger), you will
need to first manually upgrade your toolchain to support the C++11 standard
before you can compile ``libcpr``. That means installing either GCC 4.7 or
Clang 3.2 and ``libc++`` from source, a topic beyond the scope of this
manual.

.. _Clang:     http://clang.llvm.org/
.. _libc++:    http://libcxx.llvm.org/
.. _GCC:       http://gcc.gnu.org/
.. _libstdc++: http://gcc.gnu.org/libstdc++/
.. _Xcode:     http://developer.apple.com/downloads

From the source repository
--------------------------

.. code-block:: bash

   $ git clone https://github.com/dryproject/libcpr.git
   $ cd libcpr
   $ ./autogen.sh
   $ ./configure
   $ make
   $ sudo make install

From a source tarball
---------------------

.. code-block:: bash

   $ ./configure
   $ make
   $ sudo make install

Using Homebrew
--------------

``libcpr`` is not yet officially included in the `Homebrew`_ packaging system.

However, the ``etc/homebrew`` directory in the ``libcpr`` source code
repository includes a Homebrew formula, and you can therefore use Homebrew
to quickly and easily install ``libcpr``, as follows:

.. code-block:: bash

   $ brew install --HEAD \
     https://raw.github.com/dryproject/libcpr/master/etc/homebrew/libcpr.rb

.. _Homebrew: http://mxcl.github.com/homebrew/

Using MacPorts
--------------

``libcpr`` is not yet officially included in the `MacPorts`_ packaging system.

However, the ``etc/macports`` directory in the ``libcpr`` source code
repository includes a MacPorts portfile. If you have a `local portfile
repository`__ set up, you can copy over the portfile, re-run ``portindex``,
and then install as follows:

.. code-block:: bash

   $ sudo port install libcpr

Otherwise, use the tarball instructions (see previous subsection) to install.

.. _MacPorts: http://www.macports.org/
.. __: http://guide.macports.org/chunked/development.local-repositories.html

Using Fink
----------

``libcpr`` is not yet included in the `Fink`_ packaging system.

For now, use the tarball instructions (see previous subsection) to install.

.. _Fink: http://www.finkproject.org/
