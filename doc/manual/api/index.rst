.. c:header:: cpr.h

Header ``<cpr.h>``
==================

.. note::

   For convenience, ``<cpr.h>`` includes all other ``<cpr/*.h>`` header
   files. This is the case regardless of whether you have disabled building
   a particular module when running ``./configure`` to configure your build.
   If you've disabled particular modules in such a manner, you should not
   include ``<cpr.h>`` in your project's source files; rather, you should
   explicitly include only the header files for the modules that you
   actually use.
