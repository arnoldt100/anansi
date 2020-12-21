################################
**MPIEnvironment Documentation**
################################

.. default-domain:: cpp

.. namespace:: COMMUNICATOR 

=================================
MPIEnvironment.h Global Variables
=================================

.. var:: constexpr auto MAX_MPIENVIRONMENT_INSTANCES = 1

    This variable set the maximum number of instances of class
    MPIEnvironment to 1.

==================================
MPIEnvironment Class Documentation
==================================

This MPIEnvironment class abstracts the initialization of the MPI environment. 
The instantiation of the class calls MPI_Init, and the class destruction calls
MPI_Finalize.

This class can only be instantiated once. The class inherits *privately* from template <T,
int MAX_INSTANCES> ClassInstanceLimiter() to achieve this constraint.  

.. class:: MPIEnvironment : private COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: MPIEnvironment(int argc, char** argv)

        The constructor.

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

        The move assignment operator is deleted.

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
