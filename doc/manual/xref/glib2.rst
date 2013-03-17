.. index:: pair: cross-reference; GLib

GLib 2.x Cross Reference
========================

``GHashTable``
--------------

.. seealso::

   `GLib Reference Manual: Hash Tables`__
      Documentation for the ``GHashTable`` interface.

__ https://developer.gnome.org/glib/unstable/glib-Hash-Tables.html

``GList``
---------

.. seealso::

   `GLib Reference Manual: Doubly-Linked Lists`__
      Documentation for the ``GList`` interface.

__ https://developer.gnome.org/glib/unstable/glib-Doubly-Linked-Lists.html

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

.. seealso::

   `GLib Reference Manual: Pointer Arrays`__
      Documentation for the ``GPtrArray`` interface.

__ https://developer.gnome.org/glib/unstable/glib-Pointer-Arrays.html

``GQueue``
----------

.. seealso::

   `GLib Reference Manual: Double-ended Queues`__
      Documentation for the ``GQueue`` interface.

__ https://developer.gnome.org/glib/unstable/glib-Double-ended-Queues.html

``GString``
-----------

=========================================== ====================================
GLib 2.x                                    libcpr
=========================================== ====================================
:c:type:`GString`                           :c:type:`cpr_string_t`
:c:data:`GString.str`                       N/A
:c:data:`GString.len`                       :c:func:`cpr_string_size()`
:c:data:`GString.allocated_len`             :c:func:`cpr_string_capacity()`
:c:func:`g_string_new`                      :c:func:`cpr_string()`
=========================================== ====================================

.. seealso::

   `GLib Reference Manual: Strings`__
      Documentation for the ``GString`` interface.

__ https://developer.gnome.org/glib/unstable/glib-Strings.html

``GTree``
---------

.. seealso::

   `GLib Reference Manual: Balanced Binary Trees`__
      Documentation for the ``GTree`` interface.

__ https://developer.gnome.org/glib/unstable/glib-Balanced-Binary-Trees.html
