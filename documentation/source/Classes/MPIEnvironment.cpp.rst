############################
MPIEnvironment Documentation
############################

.. default-domain:: cpp

.. namespace:: COMMUNICATOR 

====================
Include Header Files
====================

**C++ Include Files**

* #include <memory>

**External Library Files**

**Package Include Files**

* #include "MPIEnvironmentState.h"
* #include "ClassInstanceLimiter.hpp"

======================
Interface Header Files
======================

**C++ Include Files**

* #include <iostream>
* #include <cstdlib>

**External Library Files**

* #include "mpi.h"


**Package Include Files**

* #include "MPIInitException.h"
* #include "MPIInitializedException.h"
* #include "MPIFinalizedException.h"
* #include "MPIEnvironment.h"
* #include "NullMPIEnvironment.h"
* #include "EnabledMPIEnvironment.h"
* #include "DisabledMPIEnvironment.h"
* #include "Pointer2d.hpp"
* #include "copy_2d_char_array.h"

=================================
MPIEnvironment.h Global Variables
=================================

.. var:: constexpr auto MAX_MPIENVIRONMENT_INSTANCES = 1

    This variable set the maximum number of instances of class
    MPIEnvironment to 1.

==================================
MPIEnvironment Class Documentation
==================================

.. class:: MPIEnvironment final : private COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>

This MPIEnvironment class abstracts the state of the MPI environment. 
The MPI environment has 3 states:

* NullMPIEnvironment

    The NullMPIEnvironment is where no invokcation of MPI_Init. This
    is the state of MPIEnvironment uopn instantiation. One then
    can enabled the MPIEnvironment. Disabling an NullMPIEnvironment 
    throws and error ErrorInvalidMPIEnvironmentChange. 

* EnabledMPIEnvironment

    The EnabledMPIEnvironment state is where there has been a successful
    MPI_Init invokcation. Once the MPIEnvironment is enabled it can be
    disabled, and reenabling a MPIEnvironment does nothing.

* DisabledMPIEnvironment

    The DisabledMPIEnvironment state is where there has been a successful
    MPI_Finalize invokcation. Once the MPIEnvironment is in the disabled it
    stays disabled. The error ErrorInvalidMPIEnvironmentChange is
    thrown if one attempts to change from disabled to an enabled state.

This class can only be instantiated once, and it inherits *privately* from template <T,
int MAX_INSTANCES> ClassInstanceLimiter() to achieve this constraint. 

The class is designated as final, and furthermore, the copy constructor, 
move-copy, copy assignment, and move-assignment functions are deleted to enforce
only 1 single instantiation.

If more than 1 MPIEnvironment class is instantiated, then the error
COUNTERCLASS::TooManyInstances is raised by means of the private base class
COUNTERCLASS::ClassInstanceLimiter.


--------------
Public Members
--------------

^^^^^^^
Friends
^^^^^^^

* COMMUNICATOR::NullMPIEnvironment

* COMMUNICATOR::EnabledMPIEnvironment

* COMMUNICATOR::DisbledMPIEnvironment

^^^^^^^^^
Lifecycle
^^^^^^^^^

.. function:: MPIEnvironment::MPIEnvironment()

    The default constructor.

.. function:: MPIEnvironment::MPIEnvironmentMPIEnvironment(const MPIEnvironment &other)=delete

    The copy constructor is deleted.

.. function:: MPIEnvironment::MPIEnvironmentMPIEnvironment (MPIEnvironment && other)=delete

    The copy-move constructor is deleted.

.. function:: MPIEnvironment::MPIEnvironment~MPIEnvironment()

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: MPIEnvironment& MPIEnvironment::operator=(const MPIEnvironment &other)=delete

    The copy assignment operator is deleted.

.. function:: MPIEnvironment& MPIEnvironment::operator=(MPIEnvironment &&other)=delete

    The assignment-move operator is deleted.

^^^^^^^^
Mutators
^^^^^^^^

.. function:: void MPIEnvironment::enableEnvironment(int const & argc, char const * const * const & argv)

    Attempts to change the MPIEnvironment state to enable. This call invokes
    the MPIEnvironment state member to change MPIEnvironment to enable.

    :rtype: void

.. function:: void MPIEnvironment::enableEnvironment()

    Attempts to change the MPIEnvironment state to enable. This call invokes
    the MPIEnvironment state member to change MPIEnvironment to enable.
 

    :rtype: void

.. function:: void disableEnvironment()

    Attempts to change the MPIEnvironment state to disable. This call invokes
    the MPIEnvironment state member to change MPIEnvironment to disable.

    :rtype: void

-----------------
Protected Members
-----------------

No protected members

---------------
Private Members
---------------

---------
Accessors
---------

---------
Operators
---------

--------
Mutators
--------

.. function:: void MPIEnvironment::enable_(int const & argc, char const * const * const & argv)

    Calls MPI_Init with non-NULL arguments. 

    :param int argc: The number of command line arguments.
    :param char** argv: The command line arguments.

    :throws COUNTERCLASS::TooManyInstances: Raised when more than 1 MPIEnvironment classs is instantiated.
    :throws COMMUNICATOR::MPIInitializedException: Raised when MPI_Init has already been called.
    :throws COMMUNICATOR::MPIInitException: Raised when MPI_Init fails.

    :rtype: void


.. function:: void MPIEnvironment::enable_() 

    Calls MPI_Init with NULL arguments. 

    :throws COUNTERCLASS::TooManyInstances: Raised when more than 1 MPIEnvironment classs is instantiated.
    :throws COMMUNICATOR::MPIInitializedException: Raised when MPI_Init has already been called.
    :throws COMMUNICATOR::MPIInitException: Raised when MPI_Init fails.

    :rtype: void

.. function:: void disable_()

    This function invokes MPI_Finalize to disable the MPI environment.

    :throws COMMUNICATOR::MPIFinalizedException : Raised when MPI_Finalize fails.

    :rtype: void

.. function:: template<class T> void changeMPIState_()

    This function modifies the class member mpistate\_ to T.

    :rtype: void

------------
Data Members
------------

.. member:: std::shared_ptr<COMMUNICATOR::MPIEnvironmentState> mpistate_

    Stores the state of the MPI environment.

