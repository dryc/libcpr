Introduction
============

``libcpr`` is a public domain backport of the core data structures and
algorithms from the C++11 standard library to C11.

Features
--------

* Implements a straightforward mapping from C++ to C, with consistent naming.
* No runtime dependencies other than the system's C++ standard library.
* No build prerequisites beyond the Autotools toolchain and a C++11 compiler.
* Compatible with Clang and GCC, and any standard C++11 implementation.
* Plays nice with others: all exported symbols are prefixed with ``cpr_``.
* 100% free and unencumbered `public domain <http://unlicense.org/>`_ software,
  usable in any context and for any purpose.

Current Status
--------------

At present, :doc:`vectors <../api/vector>` and :doc:`strings <../api/string>`
are partially implemented. Other sequence containers (list, deque) and
associative containers (set, multiset, map, multimap) are planned but not
yet implemented.
