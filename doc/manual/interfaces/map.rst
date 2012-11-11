.. highlightlang:: c

Key-Value Maps (``map_t``)
==========================

.. c:type:: map_t

   Represents a key-value map.

.. c:function:: map_t* map_alloc()

   Allocates heap memory for a new map.

.. c:function:: void map_free(map_t* map)

   Releases the heap memory used by a map.

.. c:function:: int map_init(map_t* map, const class_t* klass, const hash_func_t hash_func, const compare_func_t compare_func, const free_func_t free_key_func, const free_func_t free_value_func, ...)

   Initializes a map.

.. c:function:: int map_dispose(map_t* map)

   Resets a map back to an uninitialized state.

.. c:function:: int map_clear(map_t* map)

   Removes all key-value pairs from a map.

.. c:function:: map_is_empty(const map_t* map)

   Checks whether a map contains any key-value pairs.

.. c:function:: long map_count(map_t* map, const void* key)

   Returns the number of key-value pairs in a map.

.. c:function:: bool map_lookup(map_t* map, const void* key, void** value)

   Looks up a key-value pair in a map.

.. c:function:: int map_insert(map_t* map, const void* key, const void* value)

   Inserts a given key-value pair into a map.

.. c:function:: int map_remove(map_t* map, const void* key)

   Removes a given key-value pair from a map.
