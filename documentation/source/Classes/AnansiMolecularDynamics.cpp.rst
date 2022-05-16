.. _AnansiMolecularDynamics class target:

.. default-domain:: cpp

.. namespace:: ANANSI

#####################################
AnansiMolecularDynamics Documentation
#####################################

This class responsibility is to perform the molecular dynanics simulation.
It a derived class whose base is ANANSI::MolecularDynamics. AnansiMolecularDynamics
is marked as final.


====================
Include Header Files
====================

**C++ Include Files**

* #include <memory>

**External Library Files**

* #include <boost/program_options.hpp>

**Package Include Files**

* #include "SimulationState.h"
* #include "MPIEnvironment.h"
* #include "MolecularDynamics.h"
* #include "CommandLineArguments.h"
* #include "SimulationParameters.h"
* #include "Communicator.h"
* #include "RegistryAnansiMDStatus.h"
  

===========================
Implementation Header Files
===========================

**C++ Include Files**

**External Library Files**
#include "Pointer.hpp"
#include "Pointer2d.hpp"
#include "MPICommunicatorFactory.h"

**Package Include Files**

* #include "MDSimulationStateFactory.h"
* #include "StandardFileParserFactory.h"
* #include "BuilderControlFileParser.h"
* #include "SimulationParametersFactory.h"
* #include "AnansiMolecularDynamics.h"

========================================
AnansiMolecularDynamics Global Variables
========================================

===========================================
AnansiMolecularDynamics Class Documentation
===========================================

.. class:: AnansiMolecularDynamics : public Simulation

--------------
Public Members
--------------

^^^^^^^^^
Lifecycle
^^^^^^^^^

.. function:: AnansiMolecularDynamics::AnansiMolecularDynamics()

   The default constructor.

.. function:: AnansiMolecularDynamics::AnansiMolecularDynamics( AnansiMolecularDynamics const  &other )=delete

    The copy constructor. It is deleted.

.. function:: AnansiMolecularDynamics::AnansiMolecularDynamics(AnansiMolecularDynamics && other)=delete 

    The copy-move constructor is deleted

.. function:: AnansiMolecularDynamics::~AnansiMolecularDynamics()=0

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^

    No public accessors

^^^^^^^^^
Operators
^^^^^^^^^

.. function:: AnansiMolecularDynamics& AnansiMolecularDynamics::operator=(AnansiMolecularDynamics const & other) = delete
    
    The assignment operator. It is deleted.

.. function:: AnansiMolecularDynamics& AnansiMolecularDynamics::operator=( AnansiMolecularDynamics && other)

    The assignment-move operator is deleted.

^^^^^^^^
Mutators
^^^^^^^^

.. function:: void saveCommandLineOptionParameters()

    Stores the prorgram command line arguments and simulation control parameters.

    :rtype: void

.. function:: void enableCommunicationEnvironment()

    Enables the MPI communication environment. No inter-process communication
    can occur until the communication environment is enabled.

    :rtype: void

.. function:: void disableCommunicationEnvironment()

    Disables the MPI communication environment. No inter-process communication
    will occur after the communication environment is disabled, and once disabled
    the communication environment can't be renabled.

    :rtype: void

.. function:: void enableWorldCommunicator()

    Enables the world communicator. This call does nothing if the world communicator
    is already enabled.

    :rtype: void

.. function:: void disableWorldCommunicator()
    
    Disables the world communicator. Frees all resources associated with
    the world communicator.

    :rtype: void

-----------------
Protected Members
-----------------

    No protected members

---------------
Private Members
---------------

^^^^^^^^^
Accessors
^^^^^^^^^

    No private accessors

^^^^^^^^^
Operators
^^^^^^^^^

    No private operators

^^^^^^^^
Mutators
^^^^^^^^

.. function:: void AnansiMolecularDynamics::_initializeSimulationEnvironmnet( int const argc, char const * const * const argv ) override

    Performs the initialization of the simulation execution environment.
   
    The MPI environment is initiated. A duplicate communicator of the MPI_WORLD_COMMUNICATOR
    is made.

    :param argc const int: The size of the array char* argv[].
    :param argv char const * const * const &: Contains the command line options.

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^

    .. member:: COMMANDLINE::CommandLineArguments _commandLineArguments

    .. member:: ANANSI::SimulationParameters _simulationParameters

    .. member:: std::unique_ptr<COMMUNICATOR::Communicator> _MpiWorldCommunicator

    .. member:: std::unique_ptr<ANANSI::AnansiMDState> _mdState

    .. member:: ANANSI::RegistryAnansiMDStatus _mdStatus
    
        Stores the status of the AnansiMolecularDynamics object.

    .. member:: ANANSI::RegistryAnansiMDStatus _mdGlobalStatus
    
        Stores the global status of the AnansiMolecularDynamics object. The global MD status
        is a the global reduction of the status of all MD objects in the communicator group.
