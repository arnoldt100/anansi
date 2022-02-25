.. _Communicator source target:

.. default-domain:: cpp

.. namespace:: COMMUNICATOR

##########################
Communicator Documentation
##########################

The base class for the communicator classes. This
class is an abstract base class. 

======================
Interface Header Files
======================

**C++ Include Files**

* #include <string>
* #include <vector>
* #include <memory>
* #include <map>
* #include <cstring>
* #include <iostream>

**External Library Files**

**Project Include Files**

==========================
Implementaion Header Files
==========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "Communicator.h"
* #include "Array1d.hpp"
* #include "Array1dChar.hpp"
* #include "convert_sequence_of_chars_to_vector_string.h"

===============================
Communicator.h Global Variables
===============================

================================
Communicator Class Documentation
================================

.. class:: Communicator

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: Communicator::Communicator()

       The default constructor.

    .. function:: Communicator::Communicator( const Communicator &other )

        The copy constructor.

    .. function:: Communicator::Communicator(Communicator && other) 

        The copy-move constructor.

    .. function:: virtual Communicator::~Communicator()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    .. function:: Communicator::broadcastStdString(const std::string & data_to_broadcast, const std::size_t bcast_rank) const

        Broadcasts the string data_to_broadcast to all communicator ranks.

        :param std::string data_to_broadcast: The data to be broadcasted.
        :param std::size_t bcast_rank: The rank of communicator doing the broadcasting.
        :return: The broadcasted data.
        :rtype: std::string

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: Communicator& Communicator::operator=( Communicator const & other)

        The assignment operator.

    .. function:: Communicator& Communicator::operator=( Communicator && other)

        The assignment-move operator.

^^^^^^^^
Mutators
^^^^^^^^

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

==============================
EXPORTED FUNCTION DECLARATIONS
==============================

.. function:: template<typename T> \
              T broadcast(T const & data_to_broadcast, Communicator const & aCommunicator,const std::size_t bcast_rank)

    Broadcasts data from the communicator with rank *bcast_rank* to other ranks with respect to the communicator aCommunicator.

    This template is not defined and requires the implementation of specialized templates for each
    data type to be broadcasted.

    :param T data_to_broadcast: The data to be broadcasted.
    :param  Communicator aCommunicator: The communicator broadcasting the data.
    :param std::size_t bcast_rank: The rank of communicator doing the broadcasting.
    :return: The broadcasted data.
    :rtype: T

.. function:: template<> \
              std::string broadcast(std::string const & data_to_broadcast, Communicator const & aCommunicator,const std::size_t bcast_rank)

    Broadcasts a std:string from the communicator with rank *bcast_rank* to other ranks with respect to the communicator aCommunicator.

    :param std::string data_to_broadcast: The data to be broadcasted.
    :param Communicator aCommunicator: The communicator broadcasting the data.
    :param std::size_t bcast_rank: The rank of communicator doing the broadcasting.
    :return: The broadcasted data.
    :rtype: std::string

