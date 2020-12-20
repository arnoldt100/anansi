.. default-domain:: cpp

###################################
TooManyInstancesError Documentation
###################################

An error class that is to be thrown when too many instances of a class
is instantiated. 

.. namespace:: COUNTERCLASS

.. class:: TooManyInstancesError

==============
Public Members
==============

---------
Lifecycle
---------

.. function:: TooManyInstancesError()

   The default constructor.

.. function:: TooManyInstancesError( const TooManyInstancesError &other )

    The copy constructor.

    :param const TooManyInstancesError &other: The object to copy. 

.. function:: TooManyInstancesError& TooManyInstancesError( const TooManyInstancesError &other)

    The copy assignment operator.

    :param const TooManyInstancesError &other: The object to copy and assign. 
    :return: A copy of the other object.
    :rtype:  TooManyInstancesError

.. function:: ~TooManyInstancesError()=0

    The destructor.

---------
Accessors
---------

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
