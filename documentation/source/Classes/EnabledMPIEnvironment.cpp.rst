.. _EnabledMPIEnvironment source target:

.. default-domain:: cpp

.. namespace:: COMMUNICATOR

###################################
EnabledMPIEnvironment Documentation
###################################

The reponsibility of this class is to provide the logic when enabling of
disabling an EnabledMPIEnvironment state. The behavior is as follows:

* Disabling an enabled MPI environment results in a diabled MPIEnvironmentState, 
  DisabledMPIEnvironment.

* Enabling an enabled MPI environment results does nothing and the MPIEnvironmentState 
  remains in state EnabledMPIEnvironment.

======================
Interface Header Files
======================

**C++ Include Files**

* #include <memory>

**External Library Files**

**Project Include Files**

* include "MPIEnvironmentState.h"

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "DisabledMPIEnvironment.h"
* #include "EnabledMPIEnvironment.h"
* #include "MPIEnvironment.h"

========================================
EnabledMPIEnvironment.h Global Variables
========================================

=========================================
EnabledMPIEnvironment Class Documentation
=========================================

.. class:: EnabledMPIEnvironment : public COMMUNICATOR::MPIEnvironmentState

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: EnabledMPIEnvironment::EnabledMPIEnvironment()

   The default constructor.

.. function:: EnabledMPIEnvironment::EnabledMPIEnvironment( const EnabledMPIEnvironment &other )

    The copy constructor.

.. function:: EnabledMPIEnvironment::EnabledMPIEnvironment(EnabledMPIEnvironment && other) 

    The copy-move constructor.

.. function:: EnabledMPIEnvironment::~EnabledMPIEnvironment()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: EnabledMPIEnvironment& EnabledMPIEnvironment::operator=( EnabledMPIEnvironment const & other)

    The assignment operator.

.. function:: EnabledMPIEnvironment& EnabledMPIEnvironment::operator=( EnabledMPIEnvironment && other)

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

^^^^^^^^^
Operators
^^^^^^^^^

^^^^^^^^^
Mutators
^^^^^^^^^

.. function:: void EnabledMPIEnvironment::disable_(MPIEnvironment* const mpi_environment) override

    Invokes the appropriate MPIEnvironment member functions to  disable the MPIEnvironment.

    :rtype: void

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^
