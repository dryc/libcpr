libcpr
======

.. image:: https://travis-ci.org/bendiken/libcpr.png?branch=master
   :target: https://travis-ci.org/bendiken/libcpr
   :align: right
   :alt: Travis CI build status

Public domain backport of the core C++11 standard library to C11.

Build Dependencies
------------------

* Clang (>= 3.0) or GCC (>= 4.6)
* Autoconf (>= 2.60)
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

License
-------

This is free and unencumbered public domain software. For more information,
see <http://unlicense.org/> or the accompanying ``UNLICENSE`` file.
