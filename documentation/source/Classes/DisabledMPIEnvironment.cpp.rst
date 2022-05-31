.. _DisabledMPIEnvironment class target:

.. default-domain:: cpp

.. namespace:: COMMUNICATOR

####################################
DisabledMPIEnvironment Documentation
####################################

The responsibility of this class is to provide the logic when enabling of
disabling a DisabledMPIEnvironment state. The behavior is as follows:

* Disabling an disabled MPI environment does nothing and the state remains in a
  disabled state.
  DisabledMPIEnvironment.

* Enabling a disabled MPI environment results in the error ErrorInvalidMPIEnvironmentChange
  being thrown.

======================
Interface Header Files
======================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "MPIEnvironmentState.h"

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "DisabledMPIEnvironment.h"
* #include "MPIEnvironment.h"
* #include "ErrorInvalidMPIEnvironmentChange.h"

=========================================
DisabledMPIEnvironment.h Global Variables
=========================================

==========================================
DisabledMPIEnvironment Class Documentation
==========================================

.. class:: DisabledMPIEnvironment : COMMUNICATOR::MPIEnvironmentState

--------------
Public Members
--------------

^^^^^^^^^^
Life Cycle
^^^^^^^^^^

.. function:: DisabledMPIEnvironment::DisabledMPIEnvironment()

   The default constructor.

.. function:: DisabledMPIEnvironment::DisabledMPIEnvironment( const DisabledMPIEnvironment &other )

    The copy constructor.

.. function:: DisabledMPIEnvironment::DisabledMPIEnvironment(DisabledMPIEnvironment && other) 

    The copy-move constructor.

.. function:: DisabledMPIEnvironment::~DisabledMPIEnvironment()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: DisabledMPIEnvironment& DisabledMPIEnvironment::operator=( DisabledMPIEnvironment const & other)

    The assignment operator.

.. function:: DisabledMPIEnvironment& DisabledMPIEnvironment::operator=( DisabledMPIEnvironment && other)

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

.. function:: void DisabledMPIEnvironment::enable_(MPIEnvironment* const mpi_environment)

    :param mpi_environment: The MPIEnvironment that will be diabled. This call will throw the error
                            because it is not allowed to enable a disabled MPIEnvironment.

    :rtype: void

.. function:: void DisabledMPIEnvironment::enable_(MPIEnvironment* const mpi_environment, int const & argc, char const * const * const & argv)

    :param mpi_environment: The MPIEnvironment that will be diabled. This call will throw the error
                            because it is not allowed to enable a disabled MPIEnvironment.

    :param mpi_environment: The MPIEnvironment that will be diabled.

    :rtype: void

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^
