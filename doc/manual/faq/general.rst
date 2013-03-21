FAQ: General Questions
======================

**Q:** What is ``libcpr``?
--------------------------

**A:** ``libcpr`` is a public domain backport of the core C++ standard
library to C.

.. index:: portability

**Q:** Why is it named ``libcpr`` instead of something else?
------------------------------------------------------------

**A:** TODO

**Q:** How portable is the library?
-----------------------------------

**A:** The code base is written in standard, clean, and modern C++11, and
should be highly portable to conforming compilers.

.. index:: GCC, Clang

**Q:** Which C/C++ compilers does the library build with?
---------------------------------------------------------

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
