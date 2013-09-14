.. index:: single: patches; contributing

Contributing Patches
====================

If you wish to contribute a patch, please open a `pull request`__ at:
https://github.com/dryproject/libcpr/pulls

__ https://help.github.com/articles/using-pull-requests

Contribution Guidelines
-----------------------

* Do your best to adhere to the existing coding conventions and idioms.
* Don't use hard tabs, and don't leave trailing whitespace on any line.
  Before committing, run ``git diff --check`` to make sure of this.
* Do document every function you add using `Doxygen`_ annotations.
  Read the `tutorial`_ or just look at the existing code for examples.
* Don't touch the `VERSION` file. If you need to change it, do so on your
  private branch only.
* Do feel free to add yourself to the `CREDITS` file and the corresponding
  list in the the `README`. Alphabetical order applies.
* Don't touch the `AUTHORS` file. If your contributions are significant
  enough, be assured we will eventually add you in there.

.. _Doxygen:  http://www.doxygen.org/
.. _tutorial: http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html

Project Scope
-------------

Before spending much time writing a large patch set that adds all the
features that the library ostensibly is missing, please take a moment to
consider whether the desired functionality truly fits within the stated
scope of the project.

``libcpr`` has a clear and concise scope defined by the project's tagline
of backporting the core of the C++11 standard library to C.

This means that ``libcpr`` is, and is intended to remain, largely just a C
wrapper for functionality present in the C++ standard library. Other than
basic metadata about the shared library itself (information about
:ref:`features <feature-information>`, :ref:`modules <module-information>`,
and the library :ref:`version <version-information>`), plus hooks for
:ref:`error handling <error-handling>` and :ref:`memory management
<memory-management>`, the bulk of the library is structured so as to
correspond one-to-one to the ported C++ standard library functionality.

The following are some examples of patches that are outside the project
scope and that therefore would *not* ordinarily be considered for inclusion
into ``libcpr``:

* Data structures or algorithms not present in the C++ standard library.
* Operating system-specific functionality beyond the standard library.

Legal Considerations
--------------------

TODO
