libcpr
======

.. image:: https://travis-ci.org/bendiken/libcpr.png?branch=master
   :target: https://travis-ci.org/bendiken/libcpr
   :align: right
   :alt: Travis CI build status

``libcpr`` is a public domain backport of the core data structures and
algorithms from the C++11 standard library to C.

Features
--------

* Implements a straightforward mapping from C++ to C, with consistent naming.
* No runtime dependencies other than the system's C++ standard library.
* No build prerequisites beyond the Autotools toolchain and a C++11 compiler.
* Compatible with Clang and GCC, and any standard C++11 implementation.
* Plays nice with others: all exported symbols are prefixed with ``cpr_``.
* 100% free and unencumbered `public domain <http://unlicense.org/>`_ software,
  usable in any context and for any purpose.

Build Dependencies
------------------

* Clang (>= 3.0) or GCC (>= 4.6)
* Autoconf (>= 2.68)
* Automake (>= 1.11)
* Libtool (>= 2.2)

Installation on Unix
--------------------

::

   $ ./autogen.sh
   $ ./configure
   $ make
   $ sudo make install
   $ sudo ldconfig             # on Linux

Elsewhere
---------

* http://libcpr.org/
* http://ohloh.net/p/libcpr
* http://freecode.com/projects/libcpr
* http://sourceforge.net/p/libcpr/
* http://travis-ci.org/bendiken/libcpr

License
-------

This is free and unencumbered public domain software. For more information,
see http://unlicense.org/ or the accompanying ``UNLICENSE`` file.
