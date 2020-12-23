.. default-domain:: cpp

.. namespace:: MEMORY_MANAGEMENT

#######################
Pointer2d Documentation
#######################

This template class is a factory function for 2d pointer arrays. The 2 main
responsibilities are the creation and destruction of 2d pointer arrays. 

====================
Include Header Files
====================

**C++ Include Files**

No C++ include files.

**External Library Files**

No external library files.

**Project Include Files**

* #include "Array1d.hpp"

==============================
Pointer2d.hpp Global Variables
==============================

=============================
Pointer2d Class Documentation
=============================

.. class::template<T, > Pointer2d()

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: Pointer2d()

       The default constructor.

    .. function:: Pointer2d( const Pointer2d &other )

        The copy constructor.

    .. function:: Pointer2d(Pointer2d && other) 

        The copy-move constructor.

    .. function:: ~Pointer2d()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: Pointer2d& operator=( Pointer2d const & other)

        The assignment operator.

    .. function:: Pointer2d& operator=( Pointer2d && other)

        The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

^^^^^^^^^^^^^^
Static Methods
^^^^^^^^^^^^^^

    .. function:: static void destroyPointer2d(std::size_t const & argc, T** & in_ptr)

        Deletes a 2d pointer array.

        :param (std::size_t const &) argc:  The size of the first dimension of the 2d pointer.
        :param (T** &) in_ptr: The 2d pointer (of type T) to be deleted.

-----------------
Protected Members
-----------------

    No protected members

.. Commented out.
.. ^^^^^^^^^
.. Lifecycle
.. ^^^^^^^^^
..
.. ^^^^^^^^^
.. Accessors
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^
.. Operators
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^
.. Mutators
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^

---------------
Private Members
---------------

    No private members

.. Commented out. 
.. ^^^^^^^^^
.. Lifecycle
.. ^^^^^^^^^
..
.. ^^^^^^^^^
.. Accessors
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^
.. Operators
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^
.. Mutators
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^
