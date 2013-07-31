libcpr: C++11 backport to C
===========================

.. image:: https://travis-ci.org/unlicensed/libcpr.png?branch=master
   :target: https://travis-ci.org/unlicensed/libcpr
   :align: right
   :alt: Travis CI build status

``libcpr`` is a public domain backport of the core data structures and
algorithms from the C++11 standard library to C.

Features
--------

* Implements a straightforward mapping from C++ to C, with consistent naming.
* No runtime dependencies other than the system's C++ standard library.
* No build prerequisites beyond the Autotools toolchain and a C++11 compiler.
* Compatible with Clang and GCC, or any standard C++11 implementation.
* Plays nice with others: all exported symbols are prefixed with ``cpr_``.
* 100% free and unencumbered `public domain <http://unlicense.org/>`_ software,
  usable in any context and for any purpose.

Motivation
----------

The C standard library is severely deficient in useful data structures
essential to modern programming practice. Consequently, most non-trivial C
programs and shared libraries include one-off implementations of even the
most elementary data structures such as dynamic arrays and hash tables.
This harms programmer productivity, bloats_ the sizes of binaries, wastes
machine resources, and inevitably introduces unnecessary bugs--including
security vulnerabilities.

The alternative to rolling your own data structures has thus far been to
pull in a large, all-purpose library dependency such as GLib_.
The problem with this approach is that you just wanted a hash table, but you
got the kitchen sink with an XML parser thrown in for good measure. These
all-purpose libraries have a huge footprint and can be difficult to install,
ensuring that your potential user base will prefer competing projects who do
roll their own data structures.

``libcpr`` is a new take on an old problem. Given that every modern desktop
and server system today is practically guaranteed to already have not merely
the C standard library but also the C++ standard library, ``libcpr``
provides the until-now missing glue to access that library from pure C.
The C++ standard library contains the basic data structures and algorithms
needed for most common programming tasks, and adds no bloat since it's
already installed on the system regardless.

.. _bloats: http://en.wikipedia.org/wiki/Wirth%27s_law
.. _GLib:   http://libcpr.org/xref/glib2.html

Build Prerequisites
-------------------

* Clang_ (>= 3.0) or GCC_ (>= 4.6)
* Autoconf_ (>= 2.68)
* Automake_ (>= 1.11)
* Libtool_ (>= 2.2)

.. _Clang:    http://clang.llvm.org/
.. _GCC:      http://gcc.gnu.org/
.. _Autoconf: http://www.gnu.org/software/autoconf/
.. _Automake: http://www.gnu.org/software/automake/
.. _Libtool:  http://www.gnu.org/software/libtool/

Installation
------------

Installation on Unix
^^^^^^^^^^^^^^^^^^^^

::

   $ ./autogen.sh
   $ ./configure                        # on Linux
   $ ./configure --with-stdlib=libc++   # on FreeBSD / Mac OS X
   $ make
   $ sudo make install
   $ sudo ldconfig                      # on Linux

Elsewhere
---------

Find this project at: GitHub_, Bitbucket_, Ohloh_, Freecode_, SourceForge_,
and `Travis CI`_.

.. _GitHub:      http://github.com/unlicensed/libcpr
.. _Bitbucket:   http://bitbucket.org/unlicensed/libcpr
.. _Ohloh:       http://www.ohloh.net/p/libcpr
.. _Freecode:    http://freecode.com/projects/libcpr
.. _SourceForge: http://sourceforge.net/projects/libcpr/
.. _Travis CI:   http://travis-ci.org/unlicensed/libcpr

Author
------

* `Arto Bendiken <https://github.com/bendiken>`_ - http://ar.to/

Donations
---------

If you found this software useful and would like to encourage its
maintenance and further development, please consider making a donation to
the `Bitcoin`_ wallet address `1FxcaWrxZ1sVCdbw6ZC8eM6BhwPVnKy5fZ`__.

.. _Bitcoin: http://en.wikipedia.org/wiki/Bitcoin
.. __: bitcoin:1FxcaWrxZ1sVCdbw6ZC8eM6BhwPVnKy5fZ?label=libcpr.org&message=Donation

License
-------

This is free and unencumbered public domain software. For more information,
see http://unlicense.org/ or the accompanying ``UNLICENSE`` file.
