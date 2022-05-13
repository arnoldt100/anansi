############################
MPIEnvironment Documentation
############################

.. default-domain:: cpp

.. namespace:: COMMUNICATOR 

====================
Include Header Files
====================

**C++ Include Files**

**External Library Files**

**Package Include Files**

* #include "ClassInstanceLimiter.hpp"

======================
Interface Header Files
======================

**C++ Include Files**

* #include <iostream>
* #include <cstdlib>

**External Library Files**


**Package Include Files**

* #include "MPIInitException.h"
* #include "MPIInitializedException.h"
* #include "MPIFinalizedException.h"
* #include "MPIEnvironment.h"
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

This MPIEnvironment class abstracts the initialization of the MPI environment. 
The instantiation of the class calls MPI_Init, and the class destruction calls
MPI_Finalize.

This class can only be instantiated once, and it inherits *privately* from template <T,
int MAX_INSTANCES> ClassInstanceLimiter() to achieve this constraint. 

The class is designated as final, and furthermore the copy constructor, 
move-copy, copy assignment, and move-assignment functions are deleted to enforce
only 1 single instantiation.

If more than 1 MPIEnvironment class is instantiated, then the error
COUNTERCLASS::TooManyInstances is raised by means of the private base class
COUNTERCLASS::ClassInstanceLimiter.


--------------
Public Members
--------------

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

.. function:: void MPIEnvironment::enable(int const & argc, char const * const * const & argv) const

    Calls MPI_Init with non-NULL arguments. 

    :param int argc: The number of command line arguments.
    :param char** argv: The command line arguments.

    :throws COUNTERCLASS::TooManyInstances: Raised when more than 1 MPIEnvironment classs is instantiated.
    :throws COMMUNICATOR::MPIInitializedException: Raised when MPI_Init has already been called.
    :throws COMMUNICATOR::MPIInitException: Raised when MPI_Init fails.

    :rtype: void


.. function:: void MPIEnvironment::enable() const

    Calls MPI_Init with NULL arguments. 

    :throws COUNTERCLASS::TooManyInstances: Raised when more than 1 MPIEnvironment classs is instantiated.
    :throws COMMUNICATOR::MPIInitializedException: Raised when MPI_Init has already been called.
    :throws COMMUNICATOR::MPIInitException: Raised when MPI_Init fails.

    :rtype: void

-----------------
Protected Members
-----------------

No protected members

---------------
Private Members
---------------

No private members

.. Commented out. 
.. ---------
.. Accessors
.. ---------
.. 
.. ---------
.. Operators
.. ---------
.. 
.. --------
.. Mutators
.. --------
.. 
.. ------------
.. Data Members
.. ------------
