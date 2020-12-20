.. default-domain:: cpp

###################################
TooManyInstancesError Documentation
###################################

An error class that is to be thrown when too many instances of a class
is instantiated. 

.. namespace:: COUNTERCLASS

.. class::  template <typename T, int MAX_INSTANCES> TooManyInstancesError

==============
Public Members
==============

---------
Lifecycle
---------

.. function:: TooManyInstancesError()

   The default constructor.

.. function:: ~TooManyInstancesError()=0

    The default destructor.

.. function:: TooManyInstancesError( TooManyInstancesError const & other )

    The copy constructor.

    :param const TooManyInstancesError &other: The object to copy. 

.. function:: TooManyInstancesError( TooManyInstancesError && other )

    The move constructor.

    :param TooManyInstancesError && other: The object to move copy. 

.. function:: TooManyInstancesError& operator=( TooManyInstancesError const & other)

    The copy assignment operator.

    :param const TooManyInstancesError& other: The object to copy and assign. 
    :return: A copy of the other object.
    :rtype:  TooManyInstancesError

.. function:: TooManyInstancesError& operator=( TooManyInstancesError && other)

    The move assignment operator.

    :param TooManyInstancesError&& other: The object to move assign.
    :return: A move assignment copy of the other object.
    :rtype:  TooManyInstancesError



---------
Accessors
---------

.. function:: const char* what() const noexcept override

    Returns a char array that contains the warning message of
    instantiating too many objects of type T.

    :return: A warning message.

    :rtype:  const char*

---------
Operators
---------

--------
Mutators
--------

=================
Protected Members
=================

===============
Private Members
===============

---------
Accessors
---------

---------
Operators
---------

--------
Mutators
--------

------------
Data Members
------------
