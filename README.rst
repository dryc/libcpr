***************************
libcpr: C++11 backport to C
***************************

.. image:: https://api.travis-ci.org/dryproject/libcpr.svg?branch=master
   :target: https://travis-ci.org/dryproject/libcpr
   :alt: Travis CI build status

.. image:: https://scan.coverity.com/projects/3225/badge.svg
   :target: https://scan.coverity.com/projects/3225
   :alt: Coverity Scan build status

``libcpr`` is a public domain backport of the core data structures and
algorithms from the C++11 standard library to C.

Features
========

* Implements a straightforward mapping from C++ to C, with consistent naming.
* No runtime dependencies other than C99 and the system's C++ standard library.
* No build prerequisites beyond the Autotools toolchain and a C++11 compiler.
* Compatible with Clang and GCC, or indeed any standard C++11 implementation.
* Plays nice with others: all exported symbols are prefixed with ``cpr_``.
* 100% free and unencumbered `public domain <http://unlicense.org/>`_ software,
  usable in any context and for any purpose.

Motivation
==========

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
and server system today is guaranteed to already have not merely the C
standard library but also the C++ standard library, ``libcpr`` provides the
until-now missing glue to access that latter library from pure C. The C++
standard library contains the basic data structures and algorithms needed
for most common programming tasks, and adds no bloat since it's already
installed on the system regardless.

.. _bloats: http://en.wikipedia.org/wiki/Wirth%27s_law
.. _GLib:   http://libcpr.org/xref/glib2.html

Target Audience
===============

The target audience for this library is twofold. On the one hand, C
programmers who need a robust, reliable, and stable implementation of the
provided data structures will certainly benefit from ``libcpr``. On the
other, C++ programmers who find themselves, for whatever reason, visiting
plain-C territory will appreciate having their standard data structures at
hand with a trivial learning curve to applying existing STL know-how.

Current Status
==============

This table summarizes the data types that are implemented at present:

=============== ============= ============================== ===================
Header          Interface     Description                    Status
=============== ============= ============================== ===================
<cpr/string.h>  std::string   Dynamic strings                Usable
<cpr/vector.h>  std::vector   Dynamic arrays                 WIP
=============== ============= ============================== ===================

Usage Examples
==============

Dynamic Strings
---------------

The ``<cpr/string.h>`` interface implements dynamic strings.

Creating strings
^^^^^^^^^^^^^^^^

::

   cpr_string_t* string = cpr_string("Hello, world!\n");

Dynamic Arrays
--------------

The ``<cpr/vector.h>`` interface implements `dynamic arrays`_.

.. _dynamic arrays: http://en.wikipedia.org/wiki/Dynamic_array

Creating vectors
^^^^^^^^^^^^^^^^

::

   cpr_vector_t* vector = cpr_vector_of_strings(...);

Library Metadata
----------------

::

   printf("libcpr compile version: %hu.%hu.%hu\n",
     CPR_VERSION_MAJOR, CPR_VERSION_MINOR, CPR_VERSION_PATCH);

   printf("libcpr runtime version: %hu.%hu.%hu\n",
     cpr_version_major, cpr_version_minor, cpr_version_patch);

Design Principles
=================

* Catches all C++ exceptions and translates them into C error codes.
* Carefully differentiates logic errors, runtime errors, and fatal errors.
* Adheres to uniform naming conventions patterned after the C++ standard library.

Naming Conventions
------------------

The naming conventions and indeed symbol the symbol names themselves are
closely patterned after those of the C++ standard library.

Since C does not support function overloading, C++ standard library methods
which provide multiple overloads are differentiated in ``libcpr`` by
suffixing the corresponding function names with a disambiguating string,
usually a type name. For example ``std::string::append()`` provides multiple
overloads; the corresponding ``libcpr`` functions are provided as
``cpr_string_append_char()`` for a character argument,
``cpr_string_append_str()`` for a C string argument, and so on.

Memory Management
-----------------

All constructor functions return pointers to opaque structures allocated on
the program heap using the system's standard ``calloc()`` facility. The
library provides corresponding deallocation functions to destruct and free
these pointers.

Given that all object pointers are to opaque structures, no direct access to
any structure fields is permitted or afforded; all access is procedural. This
encapsulation facilitates and ensures ABI stability as the library evolves.

For advanced users
^^^^^^^^^^^^^^^^^^

In addition, for expert users, a so-called "unsafe" mode is provided wherein
``libcpr`` structures can be allocated directly on the stack using the
system's ``alloca()`` facility. This is more efficient than heap allocation,
but not generally safe since it will certainly break the ABI should the
structure sizes change in a future ``libcpr`` release. *Caveat utilitor*.

Error Handling
--------------

This library makes a careful distinction between three different classes of
error conditions:

* **Logic errors**, triggered using ``cpr_logic_error()``. Errors of this
  class are thrown due to programming errors where the function interfaces
  are used in violation of documented preconditions. A common strategy for
  handling this class of error conditions is to abort the program with a
  core dump, facilitating introspection to locate and remedy the bug.
* **Fatal errors**, triggered using ``cpr_fatal_error()``. Errors of this
  class are thrown due to the exhaustion of critical system resources, in
  particular available memory (``ENOMEM``), or due to attempts to exceed
  applicable system resource limits. A typical strategy for handling this
  class of error conditions is to terminate the program with a descriptive
  error message. More robust programs and shared libraries may wish to
  implement another strategy, such as retrying the operation after first
  letting most of the call stack unwind in order to free up scarce
  resources.
* **Runtime errors**, triggered using ``cpr_runtime_error()``. Errors of
  this class are thrown as a matter of course to indicate various
  exceptional conditions. These conditions are generally recoverable, and
  robust programs will take care to correctly handle them.

.. note::

   The distinction between logic errors and runtime errors mirrors that
   found in the C++11 standard library, where the ``<stdexcept>`` header
   defines the standard exception base classes ``std::logic_error`` and
   ``std::runtime_error``. The standard exception class ``std::bad_alloc``,
   on the other hand, is a representative example of a fatal error.

Build Prerequisites
===================

* Clang_ (>= 3.2) or GCC_ (>= 4.8)
* Autoconf_ (>= 2.68)
* Automake_ (>= 1.11)
* Libtool_ (>= 2.2)

.. note::

   Older releases may work, but are not actively tested for.

.. _Clang:    http://clang.llvm.org/
.. _GCC:      http://gcc.gnu.org/
.. _Autoconf: http://www.gnu.org/software/autoconf/
.. _Automake: http://www.gnu.org/software/automake/
.. _Libtool:  http://www.gnu.org/software/libtool/

Installation
============

Installation on Unix
--------------------

::

   $ ./autogen.sh
   $ ./configure                        # on Linux
   $ ./configure --with-stdlib=libc++   # on FreeBSD / Mac OS X
   $ make
   $ sudo make install
   $ sudo ldconfig                      # on Linux

Elsewhere
=========

Find this project at: GitHub_, Bitbucket_, `Open Hub`_, Freecode_,
SourceForge_, `Travis CI`_, Wercker_, `Coverity Scan`_, Twitter_, Tumblr_,
and COD5_.

.. _GitHub:        http://github.com/dryproject/libcpr
.. _Bitbucket:     http://bitbucket.org/dryproject/libcpr
.. _Open Hub:      http://www.openhub.net/p/libcpr
.. _Freecode:      http://freecode.com/projects/libcpr
.. _SourceForge:   http://sourceforge.net/projects/libcpr/
.. _Travis CI:     http://travis-ci.org/dryproject/libcpr
.. _Wercker:       https://app.wercker.com/#applications/544ad754ea87f6374f0003ff
.. _Coverity Scan: http://scan.coverity.com/projects/3225
.. _Twitter:       http://twitter.com/libcpr
.. _Tumblr:        http://libcpr.tumblr.com/
.. _COD5:          http://www.cod5.org/archive/l/libcpr.html

Author
======

This project is part of the `DRY <http://dryproject.org/>`_ initiative.

* `Arto Bendiken <https://github.com/bendiken>`_ - http://ar.to/

Donations
=========

If you found this software useful and would like to encourage its
maintenance and further development, please consider making a $5 donation
to the author(s) via Gratipay_ or Bitcoin_.

.. _Gratipay: https://gratipay.com/bendiken/
.. _Bitcoin:  bitcoin:18jD8vi8RsYsTX8NxRARaTiD53AW5n4Exb?label=libcpr.org&message=Donation

License
=======

This is free and unencumbered public domain software. For more information,
see http://unlicense.org/ or the accompanying ``UNLICENSE`` file.
