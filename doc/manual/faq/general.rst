FAQ: General Questions
======================

This section collects answers to frequently-asked general questions
regarding the ``libcpr`` project.

**Q:** What is ``libcpr``?
--------------------------

**A:** ``libcpr`` is a public domain backport of the core data structures
and algorithms from the C++11 standard library to C.

The library is implemented as a C wrapper around C++11 functionality. It
therefore requires a C++11 compiler to build, but the resulting library
binaries can be used from any C program without any C++ dependencies.

For more particulars, take a look at the :doc:`../intro` chapter.

**Q:** Why is it named ``libcpr`` instead of something else?
------------------------------------------------------------

**A:** The name ``libcpr`` has two parallel and congruent origins:

1. The project originally started out being called C′ (as in, C-`prime`_),
   with a rather larger scope than at present, before being rebooted back to
   basics.

2. The library could be considered an effort to administer CPR_ to the
   venerable C language.

.. _prime: http://en.wikipedia.org/wiki/Prime_(symbol)
.. _CPR:   http://en.wikipedia.org/wiki/Cardiopulmonary_resuscitation

**Q:** Which version of the C standard does the library require?
----------------------------------------------------------------

**A:** The project currently targets C99_, loosely defined. For example,
some of the ``libcpr`` function prototypes require the ``<stdbool.h>``
standard header introduced in C99.

That said, it is perfectly feasible to use ``libcpr`` in pre-C99 projects by
explicitly providing for the handful of C99 facilities that the library
requires.

.. _C99: http://en.wikipedia.org/wiki/C99

.. index:: portability

**Q:** How portable is the library?
-----------------------------------

**A:** The code base is written in standard, clean, and modern C++11, and
should be highly portable to conforming C++ compilers and standard
libraries.

.. index:: GCC, Clang

**Q:** Which C++ compilers does the library build with?
-------------------------------------------------------

**A:** At present, the library has been successfully built and tested with
the following compilers and platforms:

======================= =============================== ========================
Platform                Compiler                        Standard Library
======================= =============================== ========================
Fedora 18               | Clang 3.2                     | libc++
                        | GCC 4.7.x                     | libstdc++
Gentoo Linux            | Clang 3.2                     | libc++
                        | Clang 3.2                     | libstdc++
                        | GCC 4.6.3                     | libstdc++
Mac OS X 10.7.5         | Xcode 4.6.1 Clang 425.0.27    | libc++
Ubuntu 12.10            | Clang 3.2 PPA                 | libc++
                        | Clang 3.2 PPA                 | libstdc++
                        | GCC 4.7.2                     | libstdc++
Ubuntu 12.04            | Clang 3.2 SVN                 | libstdc++
                        | GCC 4.6.3                     | libstdc++
======================= =============================== ========================

.. note::

   GCC releases older than 4.5.x will not suffice to build ``libcpr``, nor
   will Clang releases older than 3.0.

**Q:** Is this in any way related to the SGI IRIX ``libcpr`` facility?
----------------------------------------------------------------------

**A:** No.
