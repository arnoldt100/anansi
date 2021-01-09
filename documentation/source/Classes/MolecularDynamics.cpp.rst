.. _MolecularDynamics class target:

.. default-domain:: cpp

.. namespace:: ANANSI

###############################
MolecularDynamics Documentation
###############################

The base class for the MolecularDynamics classes. This
class is an abstract base class, and it is not copyable
assignable, copy movebale, or assignment moveable. 

==============================
Interface Header File Includes
==============================

**C++ Include Files**

* #include <iostream>
* #include <memory>

**External Library Files**

* #include <boost/program_options.hpp>

**Project Include Files**

* #include "AnansiMDState.h"

==================================
Implementaion Header File Includes
==================================

**C++ Include Files**

**External Library Files**

**Project Include Files**

* #include "MolecularDynamics.h"


====================================
MolecularDynamics.h Global Variables
====================================

=====================================
MolecularDynamics Class Documentation
=====================================

.. class:: MolecularDynamics

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

    .. function:: MolecularDynamics::MolecularDynamics()

       The default constructor.

    .. function:: MolecularDynamics::MolecularDynamics( MolecularDynamics const &other ) = delete

        The copy constructor. This function is deleted.

        :param MolecularDynamics const & other: The other object to be copied.

    .. function:: MolecularDynamics::MolecularDynamics( MolecularDynamics &&other )=delete

        The copy move constructor. This function is deleted.

        :param MolecularDynamics const & other: The other object to be copied.

    .. function:: virtual MolecularDynamics::~MolecularDynamics()=0

        The destructor. This is a pure virtual destructor.

.. ^^^^^^^^^
.. Accessors
.. ^^^^^^^^^
.. 
..     No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

    .. function:: MolecularDynamics& MolecularDynamics::operator=(MolecularDynamics const & other) = delete 

        The assingment operator. This function is deleted.

    .. function:: MolecularDynamics& MolecularDynamics::operator=(MolecularDynamics && other) = delete 

        The assingment move operator. This function is deleted.

^^^^^^^^
Mutators
^^^^^^^^

    .. function:: void MolecularDynamics::doSimulation() 

        Performs the simulation. The function is final and serves as the public
        interface of the template design pattern. The derived class is to provide 
        its implementation for performaing the simulation.

    .. function:: void MolecularDynamics::enableCommunication()

        Enables MPI execution environment. This function is the public
        interface of the template design pattern for enabling the MPI  environment. The
        derived class is to provide the implementation.

    .. function:: void MolecularDynamics::disableCommunication()

        Disables MPI execution environment. This function is the public
        interface of the template design pattern for enabling the MPI  environment. The
        derived class is to provide the implementation.

    .. function:: void MolecularDynamics::initializeSimulationEnvironmnet( int const argc, char const * const * const & argv ) final

        Initializes the simulation execution environmnet. This function is the public
        interface of the template design pattern for performing the simulation. The
        derived class is to provide the implementation.

    .. function:: void MolecularDynamics::initializeSimulation( int const argc, char const * const * const & argv ) final

        Initializes the simulation. This function is the public
        interface of the template design pattern for performing the simulation. The
        derived class is to provide the implementation for initializing the simulation.

        :param int const argc: The size of the array argv.
        :param char const * const * const &argv: Contains the command line options.

    .. function:: void MolecularDynamics::setMDState(std::unique_ptr && a_AnansiMDState)

        Changes the state of the MD simulation. The derived class is to provide the implementation
        for initializing the simulation.

        :param std::unique_ptr && a_AnansiMDState: The new state to set the simulation to.

.. -----------------
.. Protected Members
.. -----------------
.. 
..     No protected members
.. 
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

.. ^^^^^^^^^
.. Accessors
.. ^^^^^^^^^
.. 
.. ^^^^^^^^^
.. Operators
.. ^^^^^^^^^

^^^^^^^^
Mutators
^^^^^^^^

    .. function:: virtual void MolecularDynamics::_doSimulation()=0

        Performs the MD simulation. This function must be overriden in the derived class
        or a compile time error will occur.

    .. function:: virtual void MolecularDynamics::_enableCommunication()=0

        Enables the MPI communication. This function must be overriden in the derived class or a
        compile time error will occur.

    .. function:: virtual void MolecularDynamics::_disableCommunication()=0

        Disables the MPI communication. This function must be overriden in the derived class or a
        compile time error will occur.

    .. function:: virtual void MolecularDynamics::_initializeSimulationEnvironment( int const argc, char const * const * const & argv )=0

        Initializes the simulation execution environment. This function must be overriden in the
        derived class or a compile time error will occur.

    .. function:: virtual void MolecularDynamics::_initializeSimulation( int const argc, char const * const * const & argv )=0

        Initializes the simulation to its initial conditions. This function must be overriden in the
        derived class or a compile time error will occur.

    .. function:: virtual void MolecularDynamics::MolecularDynamics::_setMDState(std::unique_ptr && a_AnansiMDState)=0

        Changes the state of the MD simulation. This function must be overriden in the derived class
        or a compile time error will occur.

        :param std::unique_ptr && a_AnansiMDState: The state to change the simulation to.

.. ^^^^^^^^^^^^
.. Data Members
.. ^^^^^^^^^^^^
