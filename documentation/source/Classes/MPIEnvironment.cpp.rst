################################
**MPIEnvironment Documentation**
################################

.. default-domain:: cpp

.. namespace:: COMMUNICATOR 

====================
Include Header Files
====================

**C++ Include Files**

* #include <iostream>
* #include <cstdlib>

**External Library Files**

* #include "mpi.h"

**Anansi Include Files**

* #include "MPIInitException.h"
* #include "MPIInitializedException.h"
* #include "MPIFinalizedException.h"
* #include "ClassInstanceLimiter.hpp"

=================================
MPIEnvironment.h Global Variables
=================================

.. var:: constexpr auto MAX_MPIENVIRONMENT_INSTANCES = 1

    This variable set the maximum number of instances of class
    MPIEnvironment to 1.

==================================
MPIEnvironment Class Documentation
==================================

.. class:: MPIEnvironment : private COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>

This MPIEnvironment class abstracts the initialization of the MPI environment. 
The instantiation of the class calls MPI_Init, and the class destruction calls
MPI_Finalize.

This class can only be instantiated once. The class inherits *privately* from template <T,
int MAX_INSTANCES> ClassInstanceLimiter() to achieve this constraint. 

Furthermore, the copy constructor, move copy, copy assignment, and move assignment functions
are deleted to enforce only 1 single instantiation.

If more than 1 MPIEnvironment class is instantiated, then the error
COUNTERCLASS::TooManyInstances is raised by means of the private base class
COUNTERCLASS::ClassInstanceLimiter.


--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: MPIEnvironment(int argc, char** argv)

        The constructor.

        :param int argc: The number of command line arguments.
        :param char** argv: The command line arguments.
        :throws COUNTERCLASS::TooManyInstances: Raised when more than 1 MPIEnvironment classs is instantiated.

    .. function:: MPIEnvironment(const MPIEnvironment &other)=delete

        The copy constructor is deleted.

    .. function:: MPIEnvironment (MPIEnvironment && other)=delete

        The copy move constructor is deleted.

    .. function:: ~MPIEnvironment()=0

        The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: MPIEnvironment& operator=(const MPIEnvironment &other)=delete

        The copy assignment operator is deleted.

    .. function:: MPIEnvironment& operator=(MPIEnvironment &&other)=delete;

        The assignment move operator is deleted.

^^^^^^^^
Mutators
^^^^^^^^

    No public mutators

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
