.. _AnansiMolecularDynamics class target:

.. default-domain:: cpp

.. namespace:: ANANSI

#####################################
AnansiMolecularDynamics Documentation
#####################################

This class responsibility is to perform the molecular dynanics simulation.
It a derived class whose base is ANANSI::MolecularDynamics. AnansiMolecularDynamics
is marked as final. 

The class has the following behaviors:

* **Null**

    The behavior does nothing.

* **Initialize Simulation Environment (ISE)**

    This behavior is responsible for initializing the simulation environment. For example,
    one side effect of this call is the MPI environment is initialized. It is not mandatory
    for this behavior to fully initialize simulation environment, but it is highly desirable
    to initialize as much as possible.

* **Process command line (PCL)**

    This behavior is responsible for processing the command line.

* **Initialize Simulation Initial Conditions (ISIC)**

    This behavior is responsible for initializing the simulation initial conditions.  

* **Perform simulation (PS)**

    This behavior is responsible for performing the molecular dynamics simulation. 

* **Terminate simulation (TS)**

    This behavior is responsible for terminating the simulation.


The State design pattern is used to express the changing behaviors. The state or current
behavior is stored in member :member:`AnansiMolecularDynamics::mdState_<AnansiMolecularDynamics::mdState_>`. Depending
upon the desired behavior, this member is assigned one of following values:

* AnansiMolecularDynamics::mdNullSimulationState\_
* AnansiMolecularDynamics::mdInitSimEnv\_
* AnansiMolecularDynamics::mdProcessCmdLine\_
* AnansiMolecularDynamics::mdInitInitialConditions\_
* AnansiMolecularDynamics::mdPerformSimulation\_
* AnansiMolecularDynamics::mdTerminateSimulation\_


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

.. class:: AnansiMolecularDynamics final : public Simulation

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

    The copy-move constructor is deleted.

.. function:: AnansiMolecularDynamics::~AnansiMolecularDynamics()=0

    The destructor.

^^^^^^^^^
Accessors
^^^^^^^^^


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

.. function:: DEFINE_VISITABLE()

    A macro that makes this class visitable. I defines the Accept member function.

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

.. function:: void saveCommandLineOptionParameters()

    Stores the prorgram command line arguments and simulation control parameters.

    :rtype: void

.. function:: void readSimulationControlFile()

    Stores the Simulation control file information. 

    :rtype: void

.. function:: void readInitialConfiguration()

    Stores the initial configuration of the Simulation.

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

.. function:: void AnansiMolecularDynamics::initializeSimulationEnvironment_() final override

    :rtype: void

.. function:: void AnansiMolecularDynamics::processCommandLine_() final override

    :rtype: void

.. function:: void AnansiMolecularDynamics::initializeInitialConditions_ () final override

    :rtype: void

.. function:: void AnansiMolecularDynamics::performSimulation_() final override

    :rtype: void

.. function:: void AnansiMolecularDynamics::terminateSimulationEnvironment_() final override

    :rtype: void

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^

.. member:: COMMANDLINE::CommandLineArguments commandLineArguments_

.. member:: ANANSI::SimulationParameters simulationParameters_

.. member:: std::unique_ptr<COMMUNICATOR::Communicator> MpiWorldCommunicator_

.. member:: std::unique_ptr<ANANSI::AnansiMDState> mdState_

.. member:: std::shared_ptr<ANANSI::SimulationState> mdNullSimulationState_

    Stores the null state behavior for AnansiMolecularDynamics simulations.

.. member:: std::shared_ptr<ANANSI::SimulationState> mdInitSimEnv_

    Stores the initialize simulation environment behavior
    AnansiMolecularDynamics simulations.

.. member:: std::shared_ptr<ANANSI::SimulationState> mdProcessCmdLine_

    Stores the process command line environment behavior
    AnansiMolecularDynamics simulations.

.. member:: std::shared_ptr<ANANSI::SimulationState> mdInitInitialConditions_

    Stores the initialize initial conditions environment behavior
    AnansiMolecularDynamics simulations.

.. member:: std::shared_ptr<ANANSI::SimulationState> mdPerformSimulation_

    Stores the perform simulation environment behavior
    AnansiMolecularDynamics simulations.

.. member:: std::shared_ptr<ANANSI::SimulationState> mdTerminateSimulation_

    Stores the terminate simulation environment behavior
    AnansiMolecularDynamics simulations.



