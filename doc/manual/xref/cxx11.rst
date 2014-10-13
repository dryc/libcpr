.. index:: pair: cross-reference; C++11

C++11 Cross Reference
=====================

``<algorithm>``
---------------

.. seealso::

   `C++ Reference: <algorithm> header`__
      Documentation for the ``std::*`` algorithms.

__ http://www.cplusplus.com/reference/algorithm/

``<bitset>``
------------

.. seealso::

   `C++ Reference: <bitset> header`__
      Documentation for the ``std::bitset`` interface.

__ http://www.cplusplus.com/reference/bitset/

``<dequeue>``
-------------

.. seealso::

   `C++ Reference: <dequeue> header`__
      Documentation for the ``std::dequeue`` interface.

__ http://www.cplusplus.com/reference/dequeue/

``<list>``
----------

.. seealso::

   `C++ Reference: <list> header`__
      Documentation for the ``std::list`` interface.

__ http://www.cplusplus.com/reference/list/

``<map>``
---------

.. seealso::

   `C++ Reference: <map> header`__
      Documentation for the ``std::map`` interface.

__ http://www.cplusplus.com/reference/map/

``<set>``
---------

.. seealso::

   `C++ Reference: <set> header`__
      Documentation for the ``std::set`` interface.

__ http://www.cplusplus.com/reference/set/

``<string>``
------------

============================================ ===================================
C++11                                        libcpr
============================================ ===================================
:cpp:class:`std::string`                     :c:type:`cpr_string_t`
:cpp:func:`std::string::string()`            :c:func:`cpr_string()`
:cpp:func:`std::string::~string()`           :c:func:`cpr_string_free()`
:cpp:func:`std::string::append()`            | :c:func:`cpr_string_append_char()`
                                             | :c:func:`cpr_string_append_str()`
                                             | :c:func:`cpr_string_append_string()`
:cpp:func:`std::string::assign()`            | :c:func:`cpr_string_assign_char()`
                                             | :c:func:`cpr_string_assign_str()`
                                             | :c:func:`cpr_string_assign_string()`
:cpp:func:`std::string::at()`                :c:func:`cpr_string_at()`
:cpp:func:`std::string::back()`              :c:func:`cpr_string_back()`
:cpp:func:`std::string::begin()`             N/A [#string-iterate]_
:cpp:func:`std::string::capacity()`          :c:func:`cpr_string_capacity()`
:cpp:func:`std::string::cbegin()`            N/A [#string-iterate]_
:cpp:func:`std::string::cend()`              N/A [#string-iterate]_
:cpp:func:`std::string::clear()`             :c:func:`cpr_string_clear()`
:cpp:func:`std::string::compare()`           :c:func:`cpr_string_compare()`
:cpp:func:`std::string::copy()`              :c:func:`cpr_string_copy()`
:cpp:func:`std::string::crbegin()`           N/A [#string-iterate]_
:cpp:func:`std::string::crend()`             N/A [#string-iterate]_
:cpp:func:`std::string::c_str()`             :c:func:`cpr_string_data()`
:cpp:func:`std::string::data()`              :c:func:`cpr_string_data()`
:cpp:func:`std::string::empty()`             :c:func:`cpr_string_empty()`
:cpp:func:`std::string::end()`               N/A [#string-iterate]_
:cpp:func:`std::string::erase()`             :c:func:`cpr_string_erase()`
:cpp:func:`std::string::find()`              | :c:func:`cpr_string_find_char()`
                                             | :c:func:`cpr_string_find_str()`
                                             | :c:func:`cpr_string_find_string()`
:cpp:func:`std::string::find_first_not_of()` N/A
:cpp:func:`std::string::find_first_of()`     N/A
:cpp:func:`std::string::find_last_not_of()`  N/A
:cpp:func:`std::string::find_last_of()`      N/A
:cpp:func:`std::string::front()`             :c:func:`cpr_string_front()`
:cpp:func:`std::string::get_allocator()`     N/A
:cpp:func:`std::string::insert()`            | :c:func:`cpr_string_insert_char()`
                                             | :c:func:`cpr_string_insert_str()`
                                             | :c:func:`cpr_string_insert_string()`
:cpp:func:`std::string::length()`            :c:func:`cpr_string_length()`
:cpp:func:`std::string::max_size()`          :c:func:`cpr_string_max_size()`
:cpp:func:`std::string::npos`                :c:func:`cpr_string_npos`
:cpp:func:`std::string::operator+=`          | :c:func:`cpr_string_append_char()`
                                             | :c:func:`cpr_string_append_str()`
                                             | :c:func:`cpr_string_append_string()`
:cpp:func:`std::string::operator=`           | :c:func:`cpr_string_assign_char()`
                                             | :c:func:`cpr_string_assign_str()`
                                             | :c:func:`cpr_string_assign_string()`
:cpp:func:`std::string::operator[]`          :c:func:`cpr_string_at()`
:cpp:func:`std::string::pop_back()`          :c:func:`cpr_string_pop_back()`
:cpp:func:`std::string::push_back()`         :c:func:`cpr_string_push_back()`
:cpp:func:`std::string::rbegin()`            N/A [#string-iterate]_
:cpp:func:`std::string::rend()`              N/A [#string-iterate]_
:cpp:func:`std::string::replace()`           N/A
:cpp:func:`std::string::reserve()`           :c:func:`cpr_string_reserve()`
:cpp:func:`std::string::resize()`            :c:func:`cpr_string_resize()`
:cpp:func:`std::string::rfind()`             | :c:func:`cpr_string_rfind_char()`
                                             | :c:func:`cpr_string_rfind_str()`
                                             | :c:func:`cpr_string_rfind_string()`
:cpp:func:`std::string::shrink_to_fit()`     :c:func:`cpr_string_shrink_to_fit()`
:cpp:func:`std::string::size()`              :c:func:`cpr_string_size()`
:cpp:func:`std::string::substr()`            :c:func:`cpr_string_substr()`
:cpp:func:`std::string::swap()`              :c:func:`cpr_string_swap()`
============================================ ===================================

.. rubric:: Footnotes

.. [#string-iterate] :ref:`Iterator operations <iterator>` are not supported.

.. seealso::

   `C++ Reference: <string> header`__
      Documentation for the ``std::string`` interface.

__ http://www.cplusplus.com/reference/string/

``<vector>``
------------

============================================ ===================================
C++11                                        libcpr
============================================ ===================================
:cpp:class:`std::vector`                     :c:type:`cpr_vector_t`
:cpp:func:`std::vector::vector()`            :c:func:`cpr_vector()`
:cpp:func:`std::vector::~vector()`           :c:func:`cpr_vector_free()`
:cpp:func:`std::vector::assign()`            N/A
:cpp:func:`std::vector::at()`                :c:func:`cpr_vector_at()`
:cpp:func:`std::vector::back()`              :c:func:`cpr_vector_back()`
:cpp:func:`std::vector::begin()`             N/A [#vector-iterate]_
:cpp:func:`std::vector::capacity()`          :c:func:`cpr_vector_capacity()`
:cpp:func:`std::vector::cbegin()`            N/A [#vector-iterate]_
:cpp:func:`std::vector::cend()`              N/A [#vector-iterate]_
:cpp:func:`std::vector::clear()`             :c:func:`cpr_vector_clear()`
:cpp:func:`std::vector::crbegin()`           N/A [#vector-iterate]_
:cpp:func:`std::vector::crend()`             N/A [#vector-iterate]_
:cpp:func:`std::vector::data()`              :c:func:`cpr_vector_data()`
:cpp:func:`std::vector::emplace()`           N/A [#vector-emplace]_
:cpp:func:`std::vector::emplace_back()`      N/A [#vector-emplace]_
:cpp:func:`std::vector::empty()`             :c:func:`cpr_vector_empty()`
:cpp:func:`std::vector::end()`               N/A [#vector-iterate]_
:cpp:func:`std::vector::erase()`             N/A
:cpp:func:`std::vector::front()`             :c:func:`cpr_vector_front()`
:cpp:func:`std::vector::get_allocator()`     N/A
:cpp:func:`std::vector::insert()`            N/A
:cpp:func:`std::vector::max_size()`          N/A
:cpp:func:`std::vector::operator=`           N/A
:cpp:func:`std::vector::operator[]`          :c:func:`cpr_vector_at()`
:cpp:func:`std::vector::pop_back()`          :c:func:`cpr_vector_pop_back()`
:cpp:func:`std::vector::push_back()`         :c:func:`cpr_vector_push_back()`
:cpp:func:`std::vector::rbegin()`            N/A [#vector-iterate]_
:cpp:func:`std::vector::rend()`              N/A [#vector-iterate]_
:cpp:func:`std::vector::reserve()`           :c:func:`cpr_vector_reserve()`
:cpp:func:`std::vector::resize()`            N/A
:cpp:func:`std::vector::shrink_to_fit()`     N/A
:cpp:func:`std::vector::size()`              :c:func:`cpr_vector_size()`
:cpp:func:`std::vector::swap()`              N/A
============================================ ===================================

.. rubric:: Footnotes

.. [#vector-iterate] :ref:`Iterator operations <iterator>` are not supported.
   Access the vector elements with :c:func:`cpr_vector_at()`, bounded by
   :c:func:`cpr_vector_size()`; or, alternatively, directly through the
   pointer returned by :c:func:`cpr_vector_data()`.

.. [#vector-emplace] :ref:`Emplacement operations <emplacement>` are not supported.
   Use :c:func:`cpr_vector_insert()` or :c:func:`cpr_vector_push_back()`.

.. seealso::

   `C++ Reference: <vector> header`__
      Documentation for the ``std::vector`` interface.

__ http://www.cplusplus.com/reference/vector/
