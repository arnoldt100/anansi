.. _CommunicatorFactory class target:

.. default-domain:: cpp

.. namespace:: COMMUNICATOR

#################################
CommunicatorFactory Documentation
#################################

The CommunicatorFactory class provides the interface for all 
communicator factories. Accordingly, to prevent an proliferation
of derived methods, please consider using a visitor design pattern
to extend the concrete derived classes.

======================
Interface Header Files
======================

**C++ Include Files**

* #include <memory>

**External Library Files**

**Project Include Files**

* #include "Communicator.h"

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "Communicator.h"

======================================
CommunicatorFactory.h Global Variables
======================================

=======================================
CommunicatorFactory Class Documentation
=======================================

.. class:: CommunicatorFactory

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: CommunicatorFactory::CommunicatorFactory()

   The default constructor.

.. function:: CommunicatorFactory::CommunicatorFactory( const CommunicatorFactory &other )

    The copy constructor.

.. function:: CommunicatorFactory::CommunicatorFactory(CommunicatorFactory && other) 

    The copy-move constructor.

.. function:: CommunicatorFactory::~CommunicatorFactory()=0

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: std::unique_ptr<COMMUNICATOR::Communicator> CommunicatorFactory::createWorldCommunicator() const

    Provides the the interface for creating a world communicator.

    :rtype: std::unique_ptr<COMMUNICATOR::Communicator>

.. function:: std::unique_ptr<COMMUNICATOR::Communicator> CommunicatorFactory::cloneCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> const & other) const

    Provides the the interface for cloning a communicator.

    :rtype: std::unique_ptr<COMMUNICATOR::Communicator>

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: CommunicatorFactory& CommunicatorFactory::operator=( CommunicatorFactory const & other)

    The assignment operator.

.. function:: CommunicatorFactory& CommunicatorFactory::operator=( CommunicatorFactory && other)

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

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: virtual std::unique_ptr<COMMUNICATOR::Communicator> CommunicatorFactory::createWorldCommunicator_() const=0

    :rtype: std::unique_ptr<COMMUNICATOR::Communicator> 


.. function:: virtual std::unique_ptr<COMMUNICATOR::Communicator> CommunicatorFactory::cloneCommunicator_(std::unique_ptr<COMMUNICATOR::Communicator> const & other) const=0

    :rtype: std::unique_ptr<COMMUNICATOR::Communicator> 
