//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
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
#include "MDSimulationStateFactory.h"
#include "TaskInterfaceUtilities.hpp"

namespace ANANSI {


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMolecularDynamics::AnansiMolecularDynamics() : 
    Simulation(),
    commandLineArguments_(),
    simulationParameters_(),
    MpiWorldCommunicator_(nullptr),
    consoleLogger_(nullptr),
    mpiEnvReceiver_(nullptr),
    mpiEnvironmentCmd_(nullptr),
    mdCommEnvInvk_(nullptr),
    mdState_(nullptr),
    mdNullSimulationState_(nullptr),
    mdInitSimEnv_(nullptr),
    mdProcessCmdLine_(nullptr),
    mdInitInitialConditions_(nullptr),
    mdPerformSimulation_(nullptr),
    mdTerminateSimulation_(nullptr),
    mdAnansiTaskFactory_(nullptr),
    mdStatus_(COMMUNICATOR::RegistryAnansiMDStatus::Undefined),
    mdGlobalStatus_(COMMUNICATOR::RegistryAnansiMDStatus::Undefined)
{
    // Initialize all state objects for this MD simulation.
    std::unique_ptr<ANANSI::MDSimulationStateFactory> md_state_factory = std::make_unique<MDSimulationStateFactory>();
    this->mdNullSimulationState_ = std::move(md_state_factory->create<NullSimulation>());
    this->mdInitSimEnv_ = std::move(md_state_factory->create<InitSimEnv>());
    this->mdProcessCmdLine_ = std::move(md_state_factory->create<ProcessCmdLine>());
    this->mdInitInitialConditions_ = std::move(md_state_factory->create<InitInitialConditions>());
    this->mdPerformSimulation_ = std::move(md_state_factory->create<PerformSimulation>());
    this->mdTerminateSimulation_ = std::move(md_state_factory->create<TerminateSimulation>());

    // Change the state to Null.
    this->mdState_ = this->mdNullSimulationState_;

    return;
}

AnansiMolecularDynamics::AnansiMolecularDynamics(int const & argc, char const *const *const & argv) :
    Simulation(),
    commandLineArguments_(COMMANDLINE::CommandLineArguments(argc,argv)),
    simulationParameters_(),
    MpiWorldCommunicator_(nullptr),
    consoleLogger_(nullptr),
    mpiEnvReceiver_(nullptr),
    mpiEnvironmentCmd_(nullptr),
    mdCommEnvInvk_(nullptr),
    mdState_(nullptr),
    mdNullSimulationState_(nullptr),
    mdInitSimEnv_(nullptr),
    mdProcessCmdLine_(nullptr),
    mdInitInitialConditions_(nullptr),
    mdPerformSimulation_(nullptr),
    mdTerminateSimulation_(nullptr),
    mdAnansiTaskFactory_(nullptr),
    mdStatus_(COMMUNICATOR::RegistryAnansiMDStatus::Undefined),
    mdGlobalStatus_(COMMUNICATOR::RegistryAnansiMDStatus::Undefined)
{
    // Initialize all state objects for this MD simulation.
    std::unique_ptr<ANANSI::MDSimulationStateFactory> md_state_factory = std::make_unique<MDSimulationStateFactory>();
    this->mdNullSimulationState_ = std::move(md_state_factory->create<NullSimulation>());
    this->mdInitSimEnv_ = std::move(md_state_factory->create<InitSimEnv>());
    this->mdProcessCmdLine_ = std::move(md_state_factory->create<ProcessCmdLine>());
    this->mdInitInitialConditions_ = std::move(md_state_factory->create<InitInitialConditions>());
    this->mdPerformSimulation_ = std::move(md_state_factory->create<PerformSimulation>());
    this->mdTerminateSimulation_ = std::move(md_state_factory->create<TerminateSimulation>());

    // Initialize all factories.
    this->mdAnansiTaskFactory_ = std::make_shared<MDAnansiTaskFactory>();

    this->mpiEnvReceiver_ = std::make_shared<ANANSI::MPIEnvReceiver>();

    // :TODO:10/11/2022 01:36:08 PM:: Refactor to use a Invoker.
    //this->consoleLogger_ = this->mdAnansiTaskFactory_->create_shared_ptr<LoggingTask>();

    // Change the state to Null.
    this->mdState_ = this->mdNullSimulationState_;
    this->mdState_->who_am_i();

    return;
}

AnansiMolecularDynamics::~AnansiMolecularDynamics()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void AnansiMolecularDynamics::enableCommunicationEnvironment()
{
    int my_argc=0;
    char** my_argv_ptr=nullptr;


    // :TODO:09/28/2022 10:52:51 AM:: mpiEnvironmentCmd_ enabling in this manner is to be depracated. 
    // Use invoker 

    // ---------------------------------------------------
    //  Create the mpi environment receiver and enable it.
    // 
    // ---------------------------------------------------
    std::shared_ptr<ANANSI::MPIEnvironment> mpi_environment = std::make_shared<ANANSI::MPIEnvironment>();
    mpi_environment->addMember(this->commandLineArguments_);
    this->mpiEnvReceiver_->enable(mpi_environment); 

    // ---------------------------------------------------
    //  Create the mpi environment task object and bind the 
    //  mpi receiver to it.
    // 
    // ---------------------------------------------------
    this->mpiEnvironmentCmd_ = 
         this->mdAnansiTaskFactory_->create_shared_ptr<InterProcessCommEnv>(this->mpiEnvReceiver_);
    
    // ---------------------------------------------------
    //  Create the invoker and add the task object to the invoker.
    // 
    // ---------------------------------------------------

    if (my_argv_ptr != nullptr)
    {
        MEMORY_MANAGEMENT::Pointer2d<char>::destroyPointer2d(my_argc,my_argv_ptr);
    }

    std::cout << "Enabled the MPI environment." << std::endl;
    return;
}

void
AnansiMolecularDynamics::disableCommunicationEnvironment()
{
    // :TODO:10/04/2022 11:05:07 AM:: Use mpiEnvInk_ to
    // end the mpi environment
    std::cout << "Disabled the MPI environment." << std::endl;
    return;
}       /* -----  end of method AnansiMolecularDynamics::disableCommunicationEnvironment  ----- */


void 
AnansiMolecularDynamics::enableWorldCommunicator()
{
    std::unique_ptr<COMMUNICATOR::CommunicatorFactory> my_mpi_factory(new MPICommunicatorFactory);
    this->MpiWorldCommunicator_ = my_mpi_factory->createWorldCommunicator();
    return;
}


void 
AnansiMolecularDynamics::disableWorldCommunicator()
{
    this->MpiWorldCommunicator_->freeCommunicator();
    this->MpiWorldCommunicator_.reset();
    return;
}

void AnansiMolecularDynamics::enableConsoleLogger()
{
	// TODO: Refactor according to new TaskInterface composite pattern.
    return;
}

void
AnansiMolecularDynamics::disableConsoleLogger()
{
	// TODO: Refactor accoding to new TaskInterface composite pattern.
    return;
}

void
AnansiMolecularDynamics::saveCommandLineOptionParameters()
{
    this->simulationParameters_ = SimulationParametersFactory::create(this->commandLineArguments_);
    return;
}      /* -----  end of method AnansiMolecularDynamics::saveCommandLineOptionParameters  ----- */





void
AnansiMolecularDynamics::readSimulationControlFile ()
{
    // The control file option is mandatory. If the option is not present, then we set the MD status
    // as "COMMUNICATOR::RegistryAnansiMDStatus::InitializingSimulationEnvironmentFailed" and we exit this method.
    // Otherwise we process/parse the control file.
    const auto file_name =  this->simulationParameters_.getCommandLineOptionValues("controlfile");

    if (file_name == SimulationParameters::OPTION_NOT_FOUND )
    {
        return;
    }

    // Create the control file parser and process the control file.
    ANANSI::MPICommunicatorFactory a_communicator_factory;
    std::unique_ptr<COMMUNICATOR::Communicator> a_communicator = a_communicator_factory.cloneCommunicator(this->MpiWorldCommunicator_);
    StandardFileParserFactory file_parser_factory;
    std::shared_ptr<BuilderFileParser> control_file_builder = std::make_shared<BuilderControlFileParser>();
    std::shared_ptr<FileParser> control_file = file_parser_factory.create(control_file_builder,
                                                                          file_name,
                                                                          std::move(a_communicator));

    control_file->readFile();

    return;
}   /* -----  end of method AnansiMolecularDynamics::readSimulationControlFile_  ----- */

void AnansiMolecularDynamics::readInitialConfiguration()
{
    std::cout << "Reading initial configuration" << std::endl;
}


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
AnansiMolecularDynamics::initializeSimulationEnvironment_()
{
    // Change the state of "this", a AnansiMolecularDynamics object, to 
    // state MDInitInitialConditions.
    this->mdState_ = this->mdInitSimEnv_;

    this->mdState_->execute(this);

    // Change the state of "this", a AnansiMolecularDynamics object, to 
    // state MDNullSimulationState.
    this->mdState_ = this->mdNullSimulationState_;

    return;
}

void AnansiMolecularDynamics::processCommandLine_()
{
    // Change the state of "this", a AnansiMolecularDynamics object, to 
    // state MDProcessCmmdLine.
    this->mdState_ = this->mdProcessCmdLine_;

    this->mdState_->execute(this);

    // Change the state of "this", a AnansiMolecularDynamics object, to 
    // state MDNullSimulationState.
    this->mdState_ = this->mdNullSimulationState_;
    return;
}

// Functions that call state methods.

void
AnansiMolecularDynamics::initializeInitialConditions_()
{
    // :TODO:09/20/2022 01:21:24 PM:: Enable this function.
    // Change state function, call execute, and change state back to
    // Null state. 

    // Change the state of "this", a AnansiMolecularDynamics object, to 
    // state MDInitInitialConditions.
    this->mdState_ = this->mdInitInitialConditions_;

    this->mdState_->execute(this);
    
    // Change the state of "this", a AnansiMolecularDynamics object, to 
    // state MDNullSimulationState.
    this->mdState_ = this->mdNullSimulationState_;
    return;
}        // -----  end of method AnansiMolecularDynamics::initializeInitialConditions_  -----

void AnansiMolecularDynamics::performSimulation_()
{
    return;
}        // -----  end of method AnansiMolecularDynamics::performSimulation_  -----

void AnansiMolecularDynamics::terminateSimulationEnvironment_()
{
    // Change the state of "this", a AnansiMolecularDynamics object, to 
    // state MDTerminateSimulation.
    this->mdState_ = this->mdTerminateSimulation_;

    this->mdState_->execute(this);

    // Change the state of "this", a AnansiMolecularDynamics object, to 
    // state MDNullSimulationState.
    this->mdState_ = this->mdNullSimulationState_;

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

