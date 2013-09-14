.. index:: pair: installation; MinGW
.. index:: pair: installation; Windows

Installation on MinGW
=====================

This section describes how to build and install ``libcpr`` on MSYS/MinGW.

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
