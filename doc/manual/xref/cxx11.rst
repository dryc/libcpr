.. index:: pair: cross-reference; C++11

C++11 Cross Reference
=====================

``std::list``
-------------

.. seealso::

   `C++ Reference: std::list`__
      Documentation for the ``std::list`` interface.

__ http://www.cplusplus.com/reference/list/list/

``std::map``
------------

.. seealso::

   `C++ Reference: std::map`__
      Documentation for the ``std::map`` interface.

__ http://www.cplusplus.com/reference/map/map/

``std::set``
------------

.. seealso::

   `C++ Reference: std::set`__
      Documentation for the ``std::set`` interface.

__ http://www.cplusplus.com/reference/set/set/

``std::string``
---------------

=========================================== ====================================
C++11                                       libcpr
=========================================== ====================================
:cpp:class:`std::string`                    :c:type:`cpr_string_t`
:cpp:func:`std::string::capacity()`         :c:func:`cpr_string_capacity()`
:cpp:func:`std::string::length()`           :c:func:`cpr_string_size()`
:cpp:func:`std::string::max_size()`         :c:func:`cpr_string_max_size()`
:cpp:func:`std::string::size()`             :c:func:`cpr_string_size()`
:cpp:func:`std::string::string()`           :c:func:`cpr_string()`
=========================================== ====================================

.. seealso::

   `C++ Reference: std::string`__
      Documentation for the ``std::string`` interface.

__ http://www.cplusplus.com/reference/string/string/

``std::vector``
---------------

=========================================== ====================================
C++11                                       libcpr
=========================================== ====================================
:cpp:class:`std::vector`                    :c:type:`cpr_vector_t`
:cpp:func:`std::vector::vector()`           :c:func:`cpr_vector()`
:cpp:func:`std::vector::assign()`           N/A
:cpp:func:`std::vector::at()`               :c:func:`cpr_vector_at()`
:cpp:func:`std::vector::back()`             :c:func:`cpr_vector_back()`
:cpp:func:`std::vector::begin()`            N/A
:cpp:func:`std::vector::capacity()`         :c:func:`cpr_vector_capacity()`
:cpp:func:`std::vector::cbegin()`           N/A
:cpp:func:`std::vector::cend()`             N/A
:cpp:func:`std::vector::clear()`            :c:func:`cpr_vector_clear()`
:cpp:func:`std::vector::crbegin()`          N/A
:cpp:func:`std::vector::crend()`            N/A
:cpp:func:`std::vector::data()`             :c:func:`cpr_vector_data()`
:cpp:func:`std::vector::emplace()`          N/A
:cpp:func:`std::vector::emplace_back()`     N/A
:cpp:func:`std::vector::empty()`            :c:func:`cpr_vector_empty()`
:cpp:func:`std::vector::end()`              N/A
:cpp:func:`std::vector::erase()`            N/A
:cpp:func:`std::vector::front()`            :c:func:`cpr_vector_front()`
:cpp:func:`std::vector::get_allocator()`    N/A
:cpp:func:`std::vector::insert()`           N/A
:cpp:func:`std::vector::max_size()`         N/A
:cpp:func:`std::vector::operator=`          N/A
:cpp:func:`std::vector::operator[]`         :c:func:`cpr_vector_at()`
:cpp:func:`std::vector::pop_back()`         :c:func:`cpr_vector_pop_back()`
:cpp:func:`std::vector::push_back()`        :c:func:`cpr_vector_push_back()`
:cpp:func:`std::vector::rbegin()`           N/A
:cpp:func:`std::vector::rend()`             N/A
:cpp:func:`std::vector::reserve()`          :c:func:`cpr_vector_reserve()`
:cpp:func:`std::vector::resize()`           N/A
:cpp:func:`std::vector::shrink_to_fit()`    N/A
:cpp:func:`std::vector::size()`             :c:func:`cpr_vector_size()`
:cpp:func:`std::vector::swap()`             N/A
=========================================== ====================================

.. seealso::

   `C++ Reference: std::vector`__
      Documentation for the ``std::vector`` interface.

__ http://www.cplusplus.com/reference/vector/vector/
