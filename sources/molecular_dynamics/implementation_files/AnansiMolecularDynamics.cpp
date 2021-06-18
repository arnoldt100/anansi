//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiMolecularDynamics.h"
#include "AnansiMDStateISE.h"
#include "AnansiMDStatePCL.h"
#include "AnansiMDStateIIC.h"
#include "AnansiMDStatePS.h"
#include "AnansiMDStateTSE.h"
#include "Pointer.hpp"
#include "SimulationParametersFactory.h"
#include "MPICommunicatorFactory.h"
#include "BuilderControlFileParser.h"
#include "StandardFileParserFactory.h"

namespace ANANSI {


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMolecularDynamics::AnansiMolecularDynamics() : 
    MolecularDynamics(),
    _commandLineArguments(),
    _simulationParameters(),
    _MpiWorldCommunicator(),
    _MpiEnvironment(),
    _mdState(),
    _mdStatus(RegistryAnansiMDStatus::Undefined)
{
    this->changeMDStateToISE();
    return;
}

AnansiMolecularDynamics::~AnansiMolecularDynamics()
{
    // Disable the communication.
    this->disableCommunication();
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================
ANANSI::RegistryAnansiMDStatus AnansiMolecularDynamics::_status() const
{
    return this->_mdStatus;
}

bool AnansiMolecularDynamics::_isHelpOnCommandLine() const
{
    const bool help_found = this->_simulationParameters.isCommandLineOptionPresent("help");
    return help_found;
}

//============================= MUTATORS =====================================
void
AnansiMolecularDynamics::_disableCommunication()
{
    this->_MpiWorldCommunicator->freeCommunicator();
    std::cout << "Disabling AnansiMolecularDynamics communication." << std::endl;
    return;
}       /* -----  end of method AnansiMolecularDynamics::_disableCommunication  ----- */

void
AnansiMolecularDynamics::_initializeSimulationEnvironment(int const & argc, char const *const *const & argv )
{
   this->_mdState->initializeSimulationEnvironment(this,argc,argv);
    return;
}

void AnansiMolecularDynamics::_saveCommandLineArguments(int const & argc, char const *const *const & argv)
{
    this->_commandLineArguments = COMMANDLINE::CommandLineArguments(argc,argv);
    std::cout << "Saved the command line arguments." << std::endl;
    return ;
}      /* -----  end of method AnansiMolecularDynamics::_saveCommandLineArguments  ----- */

void AnansiMolecularDynamics::_initializeMpiEnvironment(int const & argc, char const * const * const & argv)
{
    this->_MpiEnvironment = std::make_unique<COMMUNICATOR::MPIEnvironment>(argc,argv);
    std::cout << "Initialized the MPI environment." << std::endl;
    return;
}

void
AnansiMolecularDynamics::_enableCommunication()
{
    COMMUNICATOR::MPICommunicatorFactory a_communicator_factory;

    this->_MpiWorldCommunicator = a_communicator_factory.createWorldCommunicator();
    std::cout << "Enabling AnansiMolecularDynamics communication." << std::endl;
    return;
}       /* -----  end of method AnansiMolecularDynamics::_enableCommunication  ----- */


void
AnansiMolecularDynamics::_inputSimulationControlFile ()
{
    // Initialize the variable "my_status" to failed. The variable will track the status of reading
    // in the simulation control file. At the end of this method, we will set the status of the md
    // simulation to "my_status".
    auto my_status = RegistryAnansiMDStatus::InitializingSimulationEnvironmentFailed;

    // The control file option is mandatory. If the option is not present, then we set the MD status
    // as "RegistryAnansiMDStatus::InitializingSimulationEnvironmentFailed" and we exit this method.
    // Otherwise we process/parse the control file.
    const auto file_name =  this->_simulationParameters.getCommandLineOptionValues("controlfile");
    if (file_name == SimulationParameters::OPTION_NOT_FOUND )
    {
        my_status = RegistryAnansiMDStatus::InitializingSimulationEnvironmentFailed;
        this->setStatus(my_status);
        return;
    }

    // Create the control file parser and process the control file.
    COMMUNICATOR::MPICommunicatorFactory a_communicator_factory;
    std::unique_ptr<COMMUNICATOR::Communicator> a_communicator = a_communicator_factory.cloneCommunicator(this->_MpiWorldCommunicator);
    StandardFileParserFactory file_parser_factory;
    std::shared_ptr<BuilderFileParser> control_file_builder = std::make_shared<BuilderControlFileParser>();
    std::shared_ptr<FileParser> control_file = file_parser_factory.create(control_file_builder,
                                                                          file_name,
                                                                          std::move(a_communicator));

    // Read the control file.
    try 
    {
        control_file->readFile();
        my_status = RegistryAnansiMDStatus::InitializingSimulationEnvironmentSucessful;
    }
    catch ( const std::exception & my_error ) 
    {
        my_status = RegistryAnansiMDStatus::InitializingSimulationEnvironmentFailed;
    }

    this->setStatus(my_status);

    return;
}		/* -----  end of method AnansiMolecularDynamics::_inputSimulationControlFile  ----- */

void AnansiMolecularDynamics::_processCommandLine()
{
    this->_mdState->processCommandLine(this);
    return;
}

void
AnansiMolecularDynamics::_saveCommandLineOptionParameters()
{
    this->_simulationParameters = SimulationParametersFactory::create(this->_commandLineArguments);
    return ;
}      /* -----  end of method AnansiMolecularDynamics::_saveCommandLineOptionParameters  ----- */


// Functions that call state methods.

void
AnansiMolecularDynamics::_initializeInitialConditions()
{
    this->_mdState->initializeInitialConditions(this);
    return;
}        // -----  end of method AnansiMolecularDynamics::_initializeInitialConditions  -----

void AnansiMolecularDynamics::_performSimulation()
{
    this->_mdState->performSimulation(this);
    return;
}        // -----  end of method AnansiMolecularDynamics::_performSimulation  -----

void AnansiMolecularDynamics::_terminateSimulationEnvironment()
{
    this->_mdState->terminateSimulationEnvironment(this);
    return;
}      // -----  end of method AnansiMolecularDynamics::_terminateSimulationEnvironment  -----

void
AnansiMolecularDynamics::_setMDState(std::unique_ptr<AnansiMDState> && a_AnansiMDState)
{
    this->_mdState = std::move(a_AnansiMDState);
    return;
}      // -----  end of method AnansiMolecularDynamics::_setMDState  -----

void
AnansiMolecularDynamics::_changeMDStateToISE()
{
    std::unique_ptr<ANANSI::AnansiMDState> ise_state = std::make_unique<ANANSI::AnansiMDStateISE>(); 
    this->_setMDState(std::move(ise_state));
    return ;
}      // -----  end of method AnansiMolecularDynamics::_changeMDStateToISE  ----- 

void
AnansiMolecularDynamics::_changeMDStateToPCL()
{
   std::unique_ptr<ANANSI::AnansiMDState> pcl_state = std::make_unique<ANANSI::AnansiMDStatePCL>(); 
   this->_setMDState(std::move(pcl_state));
   return;
}       // -----  end of method AnansiMolecularDynamics::_changeMDStateToPCL  ----- 

void
AnansiMolecularDynamics::_changeMDStateToIIC()
{
    std::unique_ptr<ANANSI::AnansiMDState> iic_state = std::make_unique<ANANSI::AnansiMDStateIIC>(); 
    this->_setMDState(std::move(iic_state));
    return;
}       // -----  end of method AnansiMolecularDynamics::_changeMDStateToIIC  ----- 

void
AnansiMolecularDynamics::_changeMDStateToPS()
{
    std::unique_ptr<ANANSI::AnansiMDState> ps_state = std::make_unique<ANANSI::AnansiMDStatePS>(); 
    this->_setMDState(std::move(ps_state));
    return ;
}       // -----  end of method AnansiMolecularDynamics::_changeMDStateToPS  ----- 

void
AnansiMolecularDynamics::_changeMDStateToTSE()
{
   std::unique_ptr<ANANSI::AnansiMDState> tse_state = std::make_unique<ANANSI::AnansiMDStateTSE>(); 
   this->_setMDState(std::move(tse_state));
   return;
}

void 
AnansiMolecularDynamics::_setStatus(const RegistryAnansiMDStatus & aStatus)
{
    this->_mdStatus = aStatus;
    return;
}

//============================= OPERATORS ====================================


}; /* -----  end of namespace ANANSI  ----- */

