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

.. c:function:: cpr_list_t* cpr_list_alloc(void)

.. c:function:: void cpr_list_free(cpr_list_t* list)

``<cpr/map.h>``
---------------

.. c:type:: cpr_map_t

.. c:var:: const size_t cpr_map_sizeof

The size of the :c:type:`cpr_map_t` opaque type, i.e., ``sizeof(cpr_map_t)``.

.. c:function:: cpr_map_t* cpr_map_alloc(void)

.. c:function:: void cpr_map_free(cpr_map_t* map)

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

.. c:function:: cpr_set_t* cpr_set_alloc(void)

.. c:function:: void cpr_set_free(cpr_set_t* set)

``<cpr/string.h>``
------------------

.. c:type:: cpr_string_t

.. c:var:: const size_t cpr_string_sizeof

The size of the :c:type:`cpr_string_t` opaque type, i.e., ``sizeof(cpr_string_t)``.

.. c:function:: cpr_string_t* cpr_string_alloc(void)

.. c:function:: void cpr_string_free(cpr_string_t* string)

``<cpr/unsafe.h>``
------------------

``<cpr/vector.h>``
------------------

.. c:type:: cpr_vector_t

.. c:var:: const size_t cpr_vector_sizeof

The size of the :c:type:`cpr_vector_t` opaque type, i.e., ``sizeof(cpr_vector_t)``.

.. c:function:: cpr_vector_t* cpr_vector_alloc(void)

.. c:function:: void cpr_vector_free(cpr_vector_t* vector)

.. c:function:: void cpr_vector_init(cpr_vector_t* vector)

.. c:function:: void cpr_vector_dispose(cpr_vector_t* vector)

.. c:function:: bool cpr_vector_empty(const cpr_vector_t* vector)

Tests whether a vector is empty, i.e., whether its size is 0.

.. c:function:: size_t cpr_vector_size(const cpr_vector_t* vector)

Returns the number of elements in a vector.

.. c:function:: void cpr_vector_clear(cpr_vector_t* vector)

Removes all elements from a vector, leaving its size 0.

``<cpr/version.h>``
-------------------

.. c:macro:: CPR_VERSION_STRING

.. c:macro:: CPR_VERSION_MAJOR

.. c:macro:: CPR_VERSION_MINOR

.. c:macro:: CPR_VERSION_PATCH

.. c:var:: const char* const cpr_version_string
