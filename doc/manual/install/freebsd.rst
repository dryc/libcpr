.. index:: pair: installation; FreeBSD

Installation on FreeBSD
=======================

This section describes how to build and install ``libcpr`` on FreeBSD.

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

From FreeBSD Ports
------------------

``libcpr`` is not yet included in the `FreeBSD Ports`_ collection.

For now, use the tarball instructions (see previous subsection) to install.

.. _FreeBSD Ports: http://en.wikipedia.org/wiki/FreeBSD_Ports
