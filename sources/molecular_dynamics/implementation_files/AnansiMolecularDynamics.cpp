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
    // Initialize all state objects for this MD simulation.
    this->mdNullSimulationState_ = std::move(this->mdStateFactory_->create<NullSimulationState>());
    this->mdInitSimEnv_ = std::move(this->mdStateFactory_->create<InitSimEnv>());
    this->mdProcessCmdLine_ = std::move(this->mdStateFactory_->create<ProcessCmdLine>());
    this->mdInitInitialConditions_ = std::move(this->mdStateFactory_->create<InitInitialConditions>());
    this->mdPerformSimulation_ = std::move(this->mdStateFactory_->create<PerformSimulation>());
    this->mdTerminateSimulation_ = std::move(this->mdStateFactory_->create<TerminateSimulation>());

    // Set all commands for state objects
    //
    this->mdInitSimEnv_->addCommand(); // Add command to initialize the MPI environment.

    // Change the state to Null.
    this->mdState_ = this->mdNullSimulationState_;

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
    this->mdState_ = this->mdNullSimulationState_;
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
COMMUNICATOR::RegistryAnansiMDStatus AnansiMolecularDynamics::status_() const
{
    return this->mdStatus_;
}

bool AnansiMolecularDynamics::isHelpOnCommandLine_() const
{
    const bool help_found = this->simulationParameters_.isCommandLineOptionPresent("help");
    return help_found;
}

bool AnansiMolecularDynamics::isISEStatusOkay_() const
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

bool AnansiMolecularDynamics::isISEGlobalStatusOkay_() const
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

bool AnansiMolecularDynamics::isIICStatusOkay_() const
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
AnansiMolecularDynamics::disableCommunication_()
{
    this->MpiWorldCommunicator_->freeCommunicator();
    std::cout << "Disabling AnansiMolecularDynamics communication." << std::endl;
    return;
}       /* -----  end of method AnansiMolecularDynamics::disableCommunication_  ----- */

void
AnansiMolecularDynamics::initializeSimulationEnvironment_()
{
    // Change the state of "this", a AnansiMolecularDynamics object, to 
    // state MDInitInitialConditions.
    this->mdState_ = this->mdInitSimEnv_;

    // Make request to mdState_ to initialize the simulation environment by
    // doing the execute method. 
    this->mdState_->execute(this);

    // Change the state of "this", a AnansiMolecularDynamics object, to 
    // state MDNullSimulationState.
    this->mdState_ = std::move(this->mdStateFactory_->create<NullSimulationState>());

    return;
}

void AnansiMolecularDynamics::initializeMpiEnvironment_()
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
AnansiMolecularDynamics::enableCommunication_()
{
    COMMUNICATOR::MPICommunicatorFactory a_communicator_factory;

    this->MpiWorldCommunicator_ = a_communicator_factory.createWorldCommunicator();
    std::cout << "Enabling AnansiMolecularDynamics communication." << std::endl;
    return;
}       /* -----  end of method AnansiMolecularDynamics::enableCommunication_  ----- */


void
AnansiMolecularDynamics::inputSimulationControlFile_ ()
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
}		/* -----  end of method AnansiMolecularDynamics::inputSimulationControlFile_  ----- */

void AnansiMolecularDynamics::readInitialConfiguration_()
{
	std::cout << "Reading initial configuration" << std::endl;
}

void AnansiMolecularDynamics::processCommandLine_()
{
    return;
}

void
AnansiMolecularDynamics::saveCommandLineOptionParameters_()
{
    this->simulationParameters_ = SimulationParametersFactory::create(this->commandLineArguments_);
    return ;
}      /* -----  end of method AnansiMolecularDynamics::saveCommandLineOptionParameters_  ----- */


// Functions that call state methods.

void
AnansiMolecularDynamics::initializeInitialConditions_()
{
    return;
}        // -----  end of method AnansiMolecularDynamics::initializeInitialConditions_  -----

void AnansiMolecularDynamics::performSimulation_()
{
    return;
}        // -----  end of method AnansiMolecularDynamics::performSimulation_  -----

void AnansiMolecularDynamics::terminateSimulationEnvironment_()
{
    return;
}      // -----  end of method AnansiMolecularDynamics::terminateSimulationEnvironment_  -----

void 
AnansiMolecularDynamics::setStatus_(const COMMUNICATOR::RegistryAnansiMDStatus aStatus)
{
    this->mdStatus_ = aStatus;
    return;
}

void 
AnansiMolecularDynamics::setGlobalISEStatus_()
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

