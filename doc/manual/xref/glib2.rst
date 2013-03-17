.. index:: pair: cross-reference; GLib

GLib 2.x Cross Reference
========================

``GString``
-----------

=========================================== ====================================
GLib 2.x                                    libcpr
=========================================== ====================================
:c:type:`GString`                           :c:type:`cpr_string_t`
:c:data:`GString.str`                       N/A
:c:data:`GString.len`                       :c:func:`cpr_string_size()`
:c:data:`GString.allocated_len`             N/A
:c:func:`g_string_new`                      :c:func:`cpr_string()`
=========================================== ====================================

``GPtrArray``
-------------

=========================================== ====================================
GLib 2.x                                    libcpr
=========================================== ====================================
:c:type:`GPtrArray`                         :c:type:`cpr_vector_t`
:c:func:`g_ptr_array_add`                   :c:func:`cpr_vector_push_back()`
:c:func:`g_ptr_array_foreach`               N/A
:c:func:`g_ptr_array_free`                  :c:func:`cpr_vector_free()`
:c:func:`g_ptr_array_index`                 :c:func:`cpr_vector_at()`
:c:func:`g_ptr_array_new_full`              N/A
:c:func:`g_ptr_array_new_with_free_func`    N/A
:c:func:`g_ptr_array_new`                   :c:func:`cpr_vector()`
:c:func:`g_ptr_array_ref`                   N/A
:c:func:`g_ptr_array_remove_fast`           N/A
:c:func:`g_ptr_array_remove_index_fast`     N/A
:c:func:`g_ptr_array_remove_index`          N/A
:c:func:`g_ptr_array_remove_range`          N/A
:c:func:`g_ptr_array_remove`                N/A
:c:func:`g_ptr_array_set_free_func`         N/A
:c:func:`g_ptr_array_set_size`              N/A
:c:func:`g_ptr_array_sized_new`             N/A
:c:func:`g_ptr_array_sort_with_data`        N/A
:c:func:`g_ptr_array_sort`                  N/A
:c:func:`g_ptr_array_unref`                 N/A
=========================================== ====================================
