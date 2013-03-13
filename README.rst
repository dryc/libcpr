libcpr
======

.. image:: https://travis-ci.org/bendiken/libcpr.png?branch=master
   :target: https://travis-ci.org/bendiken/libcpr
   :align: right
   :alt: Travis CI build status

A modern, sane, and minimalistic standard library supplement for the
venerable C programming language.

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
