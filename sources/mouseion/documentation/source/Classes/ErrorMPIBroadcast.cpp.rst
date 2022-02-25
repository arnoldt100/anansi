.. _ErrorMPIBroadcast source target:

.. default-domain:: cpp

.. namespace:: COMMUNICATOR

###############################
ErrorMPIBroadcast Documentation
###############################

    Provides for handling errors in MPIBroadcast class.

======================
Interface Header Files
======================

**C++ Include Files**

* #include <exception>
* #include <iostream>
* #include <string>
* #include <string.h>

**External Library Files**


**Project Include Files**


==========================
Implementaion Header Files
==========================

**C++ Include Files**

* #include "ErrorMPIBroadcast.h"

**External Library Files**

**Project Include Files**


====================================
ErrorMPIBroadcast.h Global Variables
====================================

No global variables

=====================================
ErrorMPIBroadcast Class Documentation
=====================================

.. class:: ErrorMPIBroadcast : public std::exception

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: ErrorMPIBroadcast::ErrorMPIBroadcast()

       The default constructor.

    .. function:: ErrorMPIBroadcast::ErrorMPIBroadcast( const ErrorMPIBroadcast &other )

        The copy constructor.

    .. function:: ErrorMPIBroadcast::ErrorMPIBroadcast(ErrorMPIBroadcast && other)=delete 

        The copy-move constructor is deleted.

    .. function:: ErrorMPIBroadcast::~ErrorMPIBroadcast()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    ..  function:: char const * ErrorMPIBroadcast::what() const noexcept override

        Returns the error message.

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: ErrorMPIBroadcast& ErrorMPIBroadcast::operator=( ErrorMPIBroadcast const & other)

        The assignment operator.

    .. function:: ErrorMPIBroadcast& ErrorMPIBroadcast::operator=( ErrorMPIBroadcast && other)=delete

        The assignment-move operator is deleted.

-----------------
Protected Members
-----------------

No protected members

---------------
Private Members
---------------
    
No protected members

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^

    .. member::  std::string ErrorMPIBroadcast::_errorMessage

        The error message.
