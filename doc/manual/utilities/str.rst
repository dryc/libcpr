.. highlightlang:: c

String Utilities
================

.. c:function:: char* str_dup(const char* str)

.. c:function:: char* str_ndup(const char* str, size_t size)

.. c:function:: char* str_format(const char* fmt, ...)

.. c:function:: long str_size(const char* str)

.. c:function:: long str_length(const char* str)

.. c:function:: hash_t str_hash(const char* str)

.. c:function:: int str_compare(const char* str1, const char* str2)

.. c:function:: bool str_equal(const char* str1, const char* str2)

.. c:function:: bool str_is_empty(const char* str)

.. c:function:: bool str_is_ascii(const char* str)

.. c:function:: bool str_is_utf8(const char* str)

.. c:function:: bool str_has_prefix(const char* restrict str, const char* restrict prefix)

.. c:function:: bool str_has_suffix(const char* restrict str, const char* restrict suffix)

.. c:function:: bool str_contains(const char* restrict str, const char* restrict substr)

.. c:function:: bool str_matches(const char* restrict str, const char* restrict pattern)
