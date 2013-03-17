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

============================================ ===================================
GLib 2.x                                     libcpr
============================================ ===================================
:c:type:`GPtrArray`                          :c:type:`cpr_vector_t`
:c:func:`g_ptr_array_add()`                  :c:func:`cpr_vector_push_back()`
:c:func:`g_ptr_array_foreach()`              TODO: :c:func:`cpr_vector_for_each()`
:c:func:`g_ptr_array_free()`                 :c:func:`cpr_vector_free()`
:c:func:`g_ptr_array_index()`                :c:func:`cpr_vector_at()`
:c:func:`g_ptr_array_new()`                  :c:func:`cpr_vector()`
:c:func:`g_ptr_array_new_full()`             :c:func:`cpr_vector_init_with_capacity()`
:c:func:`g_ptr_array_new_with_free_func()`   :c:func:`cpr_vector_init()`
:c:func:`g_ptr_array_ref()`                  N/A
:c:func:`g_ptr_array_remove()`               TODO
:c:func:`g_ptr_array_remove_fast()`          TODO
:c:func:`g_ptr_array_remove_index_fast()`    TODO
:c:func:`g_ptr_array_remove_index()`         TODO
:c:func:`g_ptr_array_remove_range()`         TODO
:c:func:`g_ptr_array_set_free_func()`        TODO: :c:func:`cpr_vector_hook()`
:c:func:`g_ptr_array_set_size()`             TODO: :c:func:`cpr_vector_resize()`
:c:func:`g_ptr_array_sized_new()`            :c:func:`cpr_vector_init_with_capacity()`
:c:func:`g_ptr_array_sort()`                 TODO: :c:func:`cpr_vector_sort()`
:c:func:`g_ptr_array_sort_with_data()`       N/A
:c:func:`g_ptr_array_unref()`                N/A
============================================ ===================================

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

============================================ ===================================
GLib 2.x                                     libcpr
============================================ ===================================
:c:type:`GString`                            :c:type:`cpr_string_t`
:c:data:`GString.str`                        TODO: :c:func:`cpr_string_data()`
:c:data:`GString.len`                        :c:func:`cpr_string_size()`
:c:data:`GString.allocated_len`              :c:func:`cpr_string_capacity()`
:c:func:`g_string_append()`                  TODO: :c:func:`cpr_string_append_str()`
:c:func:`g_string_append_c()`                TODO: :c:func:`cpr_string_append_char()`
:c:func:`g_string_append_len()`              TODO: :c:func:`cpr_string_append_str()`
:c:func:`g_string_append_printf()`           N/A
:c:func:`g_string_append_unichar()`          N/A
:c:func:`g_string_append_uri_escaped()`      N/A
:c:func:`g_string_append_vprintf()`          N/A
:c:func:`g_string_assign()`                  TODO: :c:func:`cpr_string_assign_str()`
:c:func:`g_string_down()`                    N/A
:c:func:`g_string_equal()`                   TODO: :c:func:`cpr_string_equal()`
:c:func:`g_string_erase()`                   TODO: :c:func:`cpr_string_erase()`
:c:func:`g_string_free()`                    TODO: :c:func:`cpr_string_free()`
:c:func:`g_string_free_to_bytes()`           N/A
:c:func:`g_string_hash()`                    TODO: :c:func:`cpr_string_hash()`
:c:func:`g_string_insert()`                  TODO: :c:func:`cpr_string_insert_str()`
:c:func:`g_string_insert_c()`                TODO: :c:func:`cpr_string_insert_char()`
:c:func:`g_string_insert_len()`              TODO: :c:func:`cpr_string_insert_str()`
:c:func:`g_string_insert_unichar()`          N/A
:c:func:`g_string_new()`                     :c:func:`cpr_string()`
:c:func:`g_string_new_len()`                 TODO
:c:func:`g_string_overwrite()`               TODO: :c:func:`cpr_string_replace()`
:c:func:`g_string_overwrite_len()`           TODO: :c:func:`cpr_string_replace()`
:c:func:`g_string_prepend()`                 TODO: :c:func:`cpr_string_prepend_str()`
:c:func:`g_string_prepend_c()`               TODO: :c:func:`cpr_string_prepend_char()`
:c:func:`g_string_prepend_len()`             TODO: :c:func:`cpr_string_prepend_str()`
:c:func:`g_string_prepend_unichar()`         N/A
:c:func:`g_string_printf()`                  TODO
:c:func:`g_string_set_size()`                TODO: :c:func:`cpr_string_resize()`
:c:func:`g_string_sized_new()`               TODO: :c:func:`cpr_string_init_with_capacity()`
:c:func:`g_string_sprintf()`                 TODO
:c:func:`g_string_sprintfa()`                TODO
:c:func:`g_string_truncate()`                TODO: :c:func:`cpr_string_resize()`
:c:func:`g_string_up()`                      N/A
:c:func:`g_string_vprintf()`                 TODO
============================================ ===================================

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

