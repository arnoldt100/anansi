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

**Interface Include Files**

* #include "MPIEnvironment.h"
* #include "MolecularDynamics.h"
* #include "CommandLineArguments.h"
* #include "SimulationParameters.h"
* #include "Communicator.h"
  
**Implementation Include Files**

* #include "AnansiMDStateISE.h"
* #include "AnansiMDStatePCL.h"
* #include "AnansiMDStateIIC.h"
* #include "AnansiMDStatePS.h"
* #include "AnansiMDStateTSE.h"
* #include "SimulationParametersFactory.h"
* #include "MPICommunicatorFactory.h"
* #include "Pointer.hpp"

========================================
AnansiMolecularDynamics Global Variables
========================================

===========================================
AnansiMolecularDynamics Class Documentation
===========================================

.. class:: AnansiMolecularDynamics : public MolecularDynamics

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

    No public mutators

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

    .. function:: void AnansiMolecularDynamics::_doSimulation() override

    .. function:: void AnansiMolecularDynamics::_initializeSimulationEnvironmnet( int const argc, char const * const * const argv ) override

        Performs the initialization of the simulation execution environment.
       
        The MPI environment is initiated. A duplicate communicator of the MPI_WORLD_COMMUNICATOR
        is made.

        :param argc const int: The size of the array char* argv[].
        :param argv char const * const * const &: Contains the command line options.

    .. function:: void AnansiMolecularDynamics::_enableCommunication() final override
        
    .. function:: void AnansiMolecularDynamics::_setMDState(std::unique_ptr && a_AnansiMDState) final override;

        Changes the state of the MD simulation. 

        :param std::unique_ptr && a_AnansiMDState: The state to change the simulation to.

^^^^^^^^^^^^
Data Members
^^^^^^^^^^^^

    .. member:: COMMANDLINE::CommandLineArguments _commandLineArguments

    .. member:: ANANSI::SimulationParameters _simulationParameters

    .. member:: std::unique_ptr<COMMUNICATOR::Communicator> _MpiWorldCommunicator;

    .. member:: std::unique_ptr<AnansiMDState> _mdState;
