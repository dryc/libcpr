Headers
=======

``<cpr.h>``
-----------

.. note::

   For convenience, ``<cpr.h>`` includes all other ``<cpr/*.h>`` header
   files. This is the case regardless of whether you have disabled building
   a particular module when running ``./configure`` to configure your build.
   If you've disabled particular modules in such a manner, you should not
   include ``<cpr.h>`` in your project's source files; rather, you should
   explicitly include only the header files for the modules that you
   actually use.

``<cpr/feature.h>``
-------------------

.. c:function:: bool cpr_feature_exists(const char* feature_name)

Determines whether libcpr supports a given feature.

``<cpr/list.h>``
----------------

``<cpr/map.h>``
---------------

``<cpr/module.h>``
------------------

.. c:function:: bool cpr_module_exists(const char* module_name)

Determines whether libcpr includes a given module.

``<cpr/prelude.h>``
-------------------

``<cpr/set.h>``
---------------

``<cpr/string.h>``
------------------

``<cpr/unsafe.h>``
------------------

``<cpr/vector.h>``
------------------

``<cpr/version.h>``
-------------------
