.. _AnansiMolecularDynamics class target:

.. default-domain:: cpp

.. namespace:: ANANSI

#####################################
AnansiMolecularDynamics Documentation
#####################################

===========
UML Diagram
===========

.. image:: ../Diagrams/AnansiMolecularDynamics.png

==============
Class Overview
==============

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
* #include "TaskGroup.h"
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

* #include "AnansiMolecularDynamics.h"
* #include "SimulationParametersFactory.h"
* #include "BuilderControlFileParser.h"
* #include "StandardFileParserFactory.h"
* #include "MDSimulationStateFactory.h"
* #include "TaskGroupFactory.h"

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

.. function:: void AnansiMolecularDynamics::enableCommunicationEnvironment()

    Enables the MPI communication environment. No inter-process communication
    can occur until the communication environment is enabled.

    :rtype: void

.. function:: void AnansiMolecularDynamics::disableCommunicationEnvironment()

    Disables the MPI communication environment. No inter-process communication
    will occur after the communication environment is disabled, and once disabled
    the communication environment can't be renabled.

    :rtype: void

.. function:: void AnansiMolecularDynamics::enableWorldCommunicator()

    Enables the world communicator. This call does nothing if the world communicator
    is already enabled.

    :rtype: void

.. function:: void AnansiMolecularDynamics::disableWorldCommunicator()
    
    Disables the world communicator. Frees all resources associated with
    the world communicator.

    :rtype: void

.. function:: void AnansiMolecularDynamics::enableWorldTaskGroup()

    :rtype: void

.. function:: void AnansiMolecularDynamics::disableWorldTaskGroup()

    :rtype: void

.. function:: void AnansiMolecularDynamics::saveCommandLineOptionParameters()

    Stores the prorgram command line arguments and simulation control parameters.

    :rtype: void

.. function:: void AnansiMolecularDynamics::readSimulationControlFile()

    Stores the Simulation control file information. 

    :rtype: void

.. function:: void AnansiMolecularDynamics::readInitialConfiguration()

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

    This function changes the class instance to ISE, inkokes the execute method
    of the mdState\_ attribute, and returns class instance back to a Null
    state. 

    :rtype: void

.. function:: void AnansiMolecularDynamics::processCommandLine_() final override

    This function changes the class instance to PCL, inkokes the execute method
    of the mdState\_ attribute, and returns class instance back to a Null
    state. 

    :rtype: void

.. function:: void AnansiMolecularDynamics::initializeInitialConditions_ () final override

    This function changes the class instance to ISIC, inkokes the execute method
    of the mdState\_ attribute, and returns class instance back to a Null
    state. 

    :rtype: void

.. function:: void AnansiMolecularDynamics::performSimulation_() final override

    This function changes the class instance to PS, inkokes the execute method
    of the mdState\_ attribute, and returns class instance back to a Null
    state. 

    :rtype: void

.. function:: void AnansiMolecularDynamics::terminateSimulationEnvironment_() final override

    This function changes the class instance to TS, inkokes the execute method
    of the mdState\_ attribute, and returns class instance back to a Null
    state. 

    :rtype: void

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^

.. member:: COMMANDLINE::CommandLineArguments AnansiMolecularDynamics::commandLineArguments_

    Stores the command line arguments.

.. member:: ANANSI::SimulationParameters AnansiMolecularDynamics::simulationParameters_

    Store the simulation control parameters of the control file.

.. member:: std::unique_ptr<COMMUNICATOR::Communicator> AnansiMolecularDynamics::MpiWorldCommunicator_

    The default world mpi communicator. This is the first communicator that is initialized 
    in the sumlation. All other commnicators are created from this communicator.

.. member:: std::unique_ptr<ANANSI::MPIEnvironment> AnansiMolecularDynamics::MpiEnvironment_

    Represents the MPI runtime enviroment.

.. member:: std::unique_ptr<ANANSI::TaskGroup> AnansiMolecularDynamics::worldTaskGroup_

    This task group is the first task group that is instantiated.

.. member:: std::unique_ptr<ANANSI::AnansiMDState> AnansiMolecularDynamics::mdState_

    Stores the current internal state of the object.

.. member:: std::shared_ptr<ANANSI::SimulationState> AnansiMolecularDynamics::mdNullSimulationState_

    Stores the null state behavior for AnansiMolecularDynamics simulations.

.. member:: std::shared_ptr<ANANSI::SimulationState> AnansiMolecularDynamics::mdInitSimEnv_

    Stores the initialize simulation environment behavior
    AnansiMolecularDynamics simulations.

.. member:: std::shared_ptr<ANANSI::SimulationState> AnansiMolecularDynamics::mdProcessCmdLine_

    Stores the process command line environment behavior
    AnansiMolecularDynamics simulations.

.. member:: std::shared_ptr<ANANSI::SimulationState> AnansiMolecularDynamics::mdInitInitialConditions_

    Stores the initialize initial conditions environment behavior
    AnansiMolecularDynamics simulations.

.. member:: std::shared_ptr<ANANSI::SimulationState> AnansiMolecularDynamics::mdPerformSimulation_

    Stores the perform simulation environment behavior
    AnansiMolecularDynamics simulations.

.. member:: std::shared_ptr<ANANSI::SimulationState> AnansiMolecularDynamics::mdTerminateSimulation_

    Stores the terminate simulation environment behavior
    AnansiMolecularDynamics simulations.



