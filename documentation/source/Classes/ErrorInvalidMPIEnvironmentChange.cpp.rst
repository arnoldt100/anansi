.. _ErrorInvalidMPIEnvironmentChange source target:

.. default-domain:: cpp

.. namespace:: COMMUNICATOR

##############################################
ErrorInvalidMPIEnvironmentChange Documentation
##############################################

This error is to be thrown when the MPIEnvironment attempts
an invalid state change.

======================
Interface Header Files
======================

**C++ Include Files**

* #include <exception>

**External Library Files**

**Project Include Files**

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "ErrorInvalidMPIEnvironmentChange.h"

===================================================
ErrorInvalidMPIEnvironmentChange.h Global Variables
===================================================

====================================================
ErrorInvalidMPIEnvironmentChange Class Documentation
====================================================

.. class:: ErrorInvalidMPIEnvironmentChange : std::exception

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange()

   The default constructor.

.. function:: ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange( const ErrorInvalidMPIEnvironmentChange &other )

    The copy constructor.

.. function:: ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange(ErrorInvalidMPIEnvironmentChange && other) 

    The copy-move constructor.

.. function:: ErrorInvalidMPIEnvironmentChange::~ErrorInvalidMPIEnvironmentChange()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: const char* what() const noexcept override

    :rtype: const char*

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: ErrorInvalidMPIEnvironmentChange& ErrorInvalidMPIEnvironmentChange::operator=( ErrorInvalidMPIEnvironmentChange const & other)

    The assignment operator.

.. function:: ErrorInvalidMPIEnvironmentChange& ErrorInvalidMPIEnvironmentChange::operator=( ErrorInvalidMPIEnvironmentChange && other)

    The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

-----------------
Protected Members
-----------------

No protected members

.. Commented out. 
.. ^^^^^^^^^^
.. Life Cycle
.. ^^^^^^^^^^
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
.. ^^^^^^^^^^
.. Life Cycle
.. ^^^^^^^^^^
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
