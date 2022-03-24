//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <type_traits>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "copy_2d_char_array.h"
#include "Pointer.hpp"
#include "Pointer2d.hpp"
#include "MPICommunicatorFactory.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiMolecularDynamics.h"
#include "SimulationParametersFactory.h"
#include "BuilderControlFileParser.h"
#include "StandardFileParserFactory.h"

namespace ANANSI {


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMolecularDynamics::AnansiMolecularDynamics() : 
    Simulation(),
    commandLineArguments_(),
    simulationParameters_(),
    MpiWorldCommunicator_(),
    MpiEnvironment_(),
    mdStateFactory_(),
    mdStatus_(COMMUNICATOR::RegistryAnansiMDStatus::Undefined),
    mdGlobalStatus_(COMMUNICATOR::RegistryAnansiMDStatus::Undefined)
{
    // Change the state to Null.
    this->changeMDState();
    this->mdState_ = std::move(this->mdStateFactory_->create<NullSimulationState>());

    return;
}

AnansiMolecularDynamics::AnansiMolecularDynamics(int const & argc, char const *const *const & argv) :
    Simulation(),
    commandLineArguments_(COMMANDLINE::CommandLineArguments(argc,argv)),
    simulationParameters_(),
    MpiWorldCommunicator_(),
    MpiEnvironment_(),
    mdStateFactory_(std::make_unique<MDSimulationStateFactory>()),
    mdStatus_(COMMUNICATOR::RegistryAnansiMDStatus::Undefined),
    mdGlobalStatus_(COMMUNICATOR::RegistryAnansiMDStatus::Undefined)
{
    // Change the state to AnansiMDStateISE.
    this->changeMDState();
    this->mdState_ = std::move(this->mdStateFactory_->create<NullSimulationState>());
    this->mdState_->who_am_i();

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
COMMUNICATOR::RegistryAnansiMDStatus AnansiMolecularDynamics::_status() const
{
    return this->mdStatus_;
}

bool AnansiMolecularDynamics::_isHelpOnCommandLine() const
{
    const bool help_found = this->simulationParameters_.isCommandLineOptionPresent("help");
    return help_found;
}

bool AnansiMolecularDynamics::_isISEStatusOkay() const
{
	bool ret_value=false;
	if (this->status() == COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentInProgess)
	{
		ret_value = true;
	}
    else if ( this->status() == COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentSucessful)
    {
		ret_value = true;
	}
	return ret_value;
}

bool AnansiMolecularDynamics::_isISEGlobalStatusOkay() const
{
	bool ret_value=false;
    if (this->mdGlobalStatus_ == COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentInProgess)
	{
		ret_value = true;
	}
    else if ( this->mdGlobalStatus_ == COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentSucessful)
    {
		ret_value = true;
	}
	return ret_value;
}

bool AnansiMolecularDynamics::_isIICStatusOkay() const
{
	bool ret_value=false;
	if ( this->status() == COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentSucessful )
    {
		ret_value = true;
	}
	else if (this->status() == COMMUNICATOR::RegistryAnansiMDStatus::InitializingInitialConditionInProgress )
	{
		ret_value = true;
	}
    else if (this->status() == COMMUNICATOR::RegistryAnansiMDStatus::InitializingInitialConditionSuccessful)
    {
		ret_value = true;
    }
	return ret_value;
}

//============================= MUTATORS =====================================
void
AnansiMolecularDynamics::_disableCommunication()
{
    this->MpiWorldCommunicator_->freeCommunicator();
    std::cout << "Disabling AnansiMolecularDynamics communication." << std::endl;
    return;
}       /* -----  end of method AnansiMolecularDynamics::_disableCommunication  ----- */

void
AnansiMolecularDynamics::_initializeSimulationEnvironment()
{
    return;
}

void AnansiMolecularDynamics::_initializeMpiEnvironment()
{
    int my_argc=0;
    char** my_argv_ptr=nullptr;

    this->commandLineArguments_.reformCommandLineArguments(my_argc,my_argv_ptr);

	this->MpiEnvironment_ = std::make_unique<COMMUNICATOR::MPIEnvironment>(my_argc,my_argv_ptr);

    if (my_argv_ptr != nullptr)
    {
        MEMORY_MANAGEMENT::Pointer2d<char>::destroyPointer2d(my_argc,my_argv_ptr);
    }

    std::cout << "Initialized the MPI environment." << std::endl;
    return;
}

void
AnansiMolecularDynamics::_enableCommunication()
{
    COMMUNICATOR::MPICommunicatorFactory a_communicator_factory;

    this->MpiWorldCommunicator_ = a_communicator_factory.createWorldCommunicator();
    std::cout << "Enabling AnansiMolecularDynamics communication." << std::endl;
    return;
}       /* -----  end of method AnansiMolecularDynamics::_enableCommunication  ----- */


void
AnansiMolecularDynamics::_inputSimulationControlFile ()
{
    // Initialize the variable "my_status" to failed. The variable will track the status of reading
    // in the simulation control file. At the end of this method, we will set the status of the md
    // simulation to "my_status".
    auto my_status = COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentFailed;

    // The control file option is mandatory. If the option is not present, then we set the MD status
    // as "COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentFailed" and we exit this method.
    // Otherwise we process/parse the control file.
    const auto file_name =  this->simulationParameters_.getCommandLineOptionValues("controlfile");
    if (file_name == SimulationParameters::OPTION_NOT_FOUND )
    {
        my_status = COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentFailed;
        this->setStatus(my_status);
        return;
    }

    // Create the control file parser and process the control file.
    COMMUNICATOR::MPICommunicatorFactory a_communicator_factory;
    std::unique_ptr<COMMUNICATOR::Communicator> a_communicator = a_communicator_factory.cloneCommunicator(this->MpiWorldCommunicator_);
    StandardFileParserFactory file_parser_factory;
    std::shared_ptr<BuilderFileParser> control_file_builder = std::make_shared<BuilderControlFileParser>();
    std::shared_ptr<FileParser> control_file = file_parser_factory.create(control_file_builder,
                                                                          file_name,
                                                                          std::move(a_communicator));

    // Read the control file.
    try 
    {
        control_file->readFile();
        my_status = COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentSucessful;
    }
    catch ( const std::exception & my_error ) 
    {
        my_status = COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentFailed;
    }

    this->setStatus(my_status);

    return;
}		/* -----  end of method AnansiMolecularDynamics::_inputSimulationControlFile  ----- */

void AnansiMolecularDynamics::_readInitialConfiguration()
{
	std::cout << "Reading initial configuration" << std::endl;
}

void AnansiMolecularDynamics::_processCommandLine()
{
    return;
}

void
AnansiMolecularDynamics::_saveCommandLineOptionParameters()
{
    this->simulationParameters_ = SimulationParametersFactory::create(this->commandLineArguments_);
    return ;
}      /* -----  end of method AnansiMolecularDynamics::_saveCommandLineOptionParameters  ----- */


// Functions that call state methods.

void
AnansiMolecularDynamics::_initializeInitialConditions()
{
    return;
}        // -----  end of method AnansiMolecularDynamics::_initializeInitialConditions  -----

void AnansiMolecularDynamics::_performSimulation()
{
    return;
}        // -----  end of method AnansiMolecularDynamics::_performSimulation  -----

void AnansiMolecularDynamics::_terminateSimulationEnvironment()
{
    return;
}      // -----  end of method AnansiMolecularDynamics::_terminateSimulationEnvironment  -----

void
AnansiMolecularDynamics::_changeMDStateToPCL()
{
   return;
}       // -----  end of method AnansiMolecularDynamics::_changeMDStateToPCL  ----- 

void
AnansiMolecularDynamics::_changeMDStateToIIC()
{
    return;
}       // -----  end of method AnansiMolecularDynamics::_changeMDStateToIIC  ----- 

void
AnansiMolecularDynamics::_changeMDStateToPS()
{
    return ;
}       // -----  end of method AnansiMolecularDynamics::_changeMDStateToPS  ----- 

void
AnansiMolecularDynamics::_changeMDStateToTSE()
{
   return;
}

void AnansiMolecularDynamics::_changeMDState()
{
   /* :TODO:03/21/2022 11:52:54 AM:: Refactor with respect to new States. */
   return;
}

void 
AnansiMolecularDynamics::_setStatus(const COMMUNICATOR::RegistryAnansiMDStatus aStatus)
{
    this->mdStatus_ = aStatus;
    return;
}

void 
AnansiMolecularDynamics::_setGlobalISEStatus()
{
    // We do a custom all reduction of the ISE status to get the
    // global ISE status. 
    const auto my_status = this->mdStatus_;
    COMMUNICATOR::ISEReductionFunctor my_reduction_functor;

    this->mdGlobalStatus_ = 
        COMMUNICATOR::getGlobalStatusCustomReduction<COMMUNICATOR::RegistryAnansiMDStatus>(my_status,
                                                     *(this->MpiWorldCommunicator_));
    return;
}


//============================= OPERATORS ====================================


}; /* -----  end of namespace ANANSI  ----- */

