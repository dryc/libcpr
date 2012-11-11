.. highlightlang:: c

Regular-Expression Matching
===========================

.. c:function:: regoff_t regmatch_length(const regmatch_t match)

.. c:function:: bool regmatch_is_empty(const regmatch_t match)

.. c:function:: regoff_t regmatch_copy(const regmatch_t match, const char* restrict string, char* restrict buffer)

.. c:function:: int regmatch_to_int(const regmatch_t match, const char* string)

.. c:function:: long regmatch_to_long(const regmatch_t match, const char* string)
