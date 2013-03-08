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

.. c:type:: cpr_list_t

.. c:var:: const size_t cpr_list_sizeof

The size of the :c:type:`cpr_list_t` opaque type, i.e., ``sizeof(cpr_list_t)``.

``<cpr/map.h>``
---------------

.. c:type:: cpr_map_t

.. c:var:: const size_t cpr_map_sizeof

The size of the :c:type:`cpr_map_t` opaque type, i.e., ``sizeof(cpr_map_t)``.

``<cpr/module.h>``
------------------

.. c:function:: bool cpr_module_exists(const char* module_name)

Determines whether libcpr includes a given module.

``<cpr/prelude.h>``
-------------------

``<cpr/set.h>``
---------------

.. c:type:: cpr_set_t

.. c:var:: const size_t cpr_set_sizeof

The size of the :c:type:`cpr_set_t` opaque type, i.e., ``sizeof(cpr_set_t)``.

``<cpr/string.h>``
------------------

.. c:type:: cpr_string_t

.. c:var:: const size_t cpr_string_sizeof

The size of the :c:type:`cpr_string_t` opaque type, i.e., ``sizeof(cpr_string_t)``.

``<cpr/unsafe.h>``
------------------

``<cpr/vector.h>``
------------------

.. c:type:: cpr_vector_t

.. c:var:: const size_t cpr_vector_sizeof

The size of the :c:type:`cpr_vector_t` opaque type, i.e., ``sizeof(cpr_vector_t)``.

``<cpr/version.h>``
-------------------

.. c:macro:: CPR_VERSION_STRING

.. c:macro:: CPR_VERSION_MAJOR

.. c:macro:: CPR_VERSION_MINOR

.. c:macro:: CPR_VERSION_PATCH

.. c:var:: const char* const cpr_version_string
