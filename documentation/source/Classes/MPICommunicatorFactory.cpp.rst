.. _MPICommunicatorFactory class target:

.. default-domain:: cpp

.. namespace:: ANANSI

####################################
MPICommunicatorFactory Documentation
####################################

The factory for creating MPICommunicators. This class is final.


======================
Interface Header Files
======================

**C++ Include Files**


**External Library Files**


**Project Include Files**

* #include "MPICommunicator.h"
* #include "CommunicatorFactory.h"


===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "MPICommunicatorFactory.h"

=========================================
MPICommunicatorFactory.h Global Variables
=========================================

==========================================
MPICommunicatorFactory Class Documentation
==========================================

.. class:: MPICommunicatorFactory final : public COMMUNICATOR::CommunicatorFactory

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: MPICommunicatorFactory::MPICommunicatorFactory()

   The default constructor.

.. function:: MPICommunicatorFactory::MPICommunicatorFactory( const MPICommunicatorFactory &other )

    The copy constructor.

.. function:: MPICommunicatorFactory::MPICommunicatorFactory(MPICommunicatorFactory && other) 

    The copy-move constructor.

.. function:: MPICommunicatorFactory::~MPICommunicatorFactory()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MPICommunicatorFactory& MPICommunicatorFactory::operator=( MPICommunicatorFactory const & other)

    The assignment operator.

.. function:: MPICommunicatorFactory& MPICommunicatorFactory::operator=( MPICommunicatorFactory && other)

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

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

^^^^^^^^^
Accessors
^^^^^^^^^

.. function:: std::unique_ptr<COMMUNICATOR::Communicator> MPICommunicatorFactory::createWorldCommunicator_() const override

    Provides an implementation to create a MPICommunicator that references a MPI world communicator. The 

    :rtype: std::unique_ptr<COMMUNICATOR::Communicator>

.. function:: std::unique_ptr<COMMUNICATOR::Communicator> MPICommunicatorFactory::cloneCommunicator_(std::unique_ptr<COMMUNICATOR::Communicator> const & a_communicator) const override

    Provides an implementation to that clones the communicator a_communicator.

    :rtype: std::unique_ptr<COMMUNICATOR::Communicator>

^^^^^^^^^
Operators
^^^^^^^^^

^^^^^^^^^
Mutators
^^^^^^^^^

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^
