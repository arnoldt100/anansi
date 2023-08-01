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
#include "MDSimulationStateFactory.h"
#include "GenericTaskInvokerFactory.hpp"
#include "InterProcessCommEnv.h"
#include "GenericReceiverFactory.hpp"
#include "InitMPIEnvTaskReceiver.h"
#include "ConsoleMessageContainer.h"

#include "setup_core_logging_invoker.h"
#include "setup_controlfile_receivers.h"
#include "setup_mpi_communication_environment_receivers.h"
#include "setup_mpi_world_communicator.h"

namespace ANANSI
{

// ====================  Sumulation Interface Implementations  ===============

// These methods implement the interface for the parent class Simulation
// private virtual methods.

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= ACCESSORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMolecularDynamics::AnansiMolecularDynamics() :
    Simulation(),
    commandLineArguments_(),
    simulationParameters_(),
    MpiWorldCommunicator_(nullptr),
    mdCommEnvInvk_(nullptr),
    mdControlFileInvk_(nullptr),
    mdWorldCommunicatorInvk_(nullptr),
    mdCoreLoggingInvk_(nullptr),
    mdState_(nullptr),
    mdNullSimulationState_(nullptr),
    mdInitSimEnv_(nullptr),
    mdProcessCmdLine_(nullptr),
    mdInitInitialConditions_(nullptr),
    mdPerformSimulation_(nullptr),
    mdTerminateSimulation_(nullptr),
    mdAnansiControlFileTaskFactory_(nullptr)
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
    mdCommEnvInvk_(nullptr),
    mdControlFileInvk_(nullptr),
    mdWorldCommunicatorInvk_(nullptr),
    mdCoreLoggingInvk_(nullptr),
    mdState_(nullptr),
    mdNullSimulationState_(nullptr),
    mdInitSimEnv_(nullptr),
    mdProcessCmdLine_(nullptr),
    mdInitInitialConditions_(nullptr),
    mdPerformSimulation_(nullptr),
    mdTerminateSimulation_(nullptr),
    mdAnansiControlFileTaskFactory_(nullptr)
{
    // Initialize all state objects for this MD simulation.
    std::unique_ptr<ANANSI::MDSimulationStateFactory> md_state_factory = std::make_unique<MDSimulationStateFactory>();
    this->mdNullSimulationState_ = std::move(md_state_factory->create<NullSimulation>());
    this->mdInitSimEnv_ = std::move(md_state_factory->create<InitSimEnv>());
    this->mdProcessCmdLine_ = std::move(md_state_factory->create<ProcessCmdLine>());
    this->mdInitInitialConditions_ = std::move(md_state_factory->create<InitInitialConditions>());
    this->mdPerformSimulation_ = std::move(md_state_factory->create<PerformSimulation>());
    this->mdTerminateSimulation_ = std::move(md_state_factory->create<TerminateSimulation>());

    // Change the state of the MD simulation to Null.
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
void
AnansiMolecularDynamics::enableCommunicationEnvironment()
{

    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // Setup all receivers for the communication environment invoker.
    //
    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    setup_mpi_communication_environment_receivers(this->mdCommEnvInvk_,
                                                  this->commandLineArguments_);

    // ---------------------------------------------------
    // Enable all tasks.
    //
    // ---------------------------------------------------
    const std::vector<ANANSI::TaskLabel> command_labels = 
        {ANANSI::InitMPIEnvTaskReceiver::TASKLABEL};
    this->mdCommEnvInvk_->enableTask(command_labels);

    // ---------------------------------------------------
    // Do task that will set up communication runtime environment.
    //
    // ---------------------------------------------------
    this->mdCommEnvInvk_->doTask(command_labels);

    return;
}

void
AnansiMolecularDynamics::disableCommunicationEnvironment()
{
    // ---------------------------------------------------
    // Use the invoker to disable the communication environment.
    //
    // ---------------------------------------------------
    constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] =
    {
        'm','p', 'i', '_','e','n','v','i','r','o','n','m','e','n','t'
    };

    const std::vector<ANANSI::TaskLabel> command_labels = {ANANSI::TaskLabel(tmpstr)};

    this->mdCommEnvInvk_->disableTask(command_labels);
    return;

}       /* -----  end of method AnansiMolecularDynamics::disableCommunicationEnvironment  ----- */


void
AnansiMolecularDynamics::enableWorldCommunicator()
{

    std::unique_ptr<COMMUNICATOR::CommunicatorFactory> a_communicator_factory = std::make_unique<MPICommunicatorFactory>();
    this->MpiWorldCommunicator_ = a_communicator_factory->createWorldCommunicator();

    setup_mpi_world_communicator(mdWorldCommunicatorInvk_);

    // ---------------------------------------------------
    // Enable all tasks.
    //
    // ---------------------------------------------------
    const std::vector<ANANSI::TaskLabel> command_labels =
        {ANANSI::InitWorldCommunicatorTaskReceiver::TASKLABEL};
    this->mdWorldCommunicatorInvk_->enableTask(command_labels);
    
    // ---------------------------------------------------
    // Do task that will set up world communicator.
    //
    // ---------------------------------------------------
    this->mdWorldCommunicatorInvk_->doTask(command_labels);

    return;
}

void
AnansiMolecularDynamics::disableWorldCommunicator()
{
    if (this->mdWorldCommunicatorInvk_)
    {
        constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] =
        {'m','p','i','_','w','o','r','l','d','_','c','o','m','m','u','n','i','c','a','t','o','r'};
        const std::vector<ANANSI::TaskLabel> command_labels = {ANANSI::TaskLabel(tmpstr)};
        this->mdWorldCommunicatorInvk_->disableTask(command_labels);
    }

    if (this->MpiWorldCommunicator_)
    {
        this->MpiWorldCommunicator_->freeCommunicator();
    }
    return;
}

void
AnansiMolecularDynamics::disableCoreLoggingTasks()
{
    // ---------------------------------------------------
    // Disable the Console logger.
    //
    // ---------------------------------------------------
    constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] =
    {
        'w','r','i','t','e','_','t','e','x','t','_','t','o','_','c','o','n','s','o','l','e'
    };

    const std::vector<ANANSI::TaskLabel> command_labels = {ANANSI::TaskLabel(tmpstr)};

    this->mdCoreLoggingInvk_->disableTask(command_labels);
    return;
}

void
AnansiMolecularDynamics::saveCommandLineOptionParameters()
{
    this->simulationParameters_ = SimulationParametersFactory::create(this->commandLineArguments_);
    return;
}      // -----  end of method AnansiMolecularDynamics::saveCommandLineOptionParameters  -----

void
AnansiMolecularDynamics::enableControlFileTasks ()
{
    const auto controlfile_name =  this->simulationParameters_.getCommandLineOptionValues("controlfile");
    if (controlfile_name == SimulationParameters::OPTION_NOT_FOUND )
    {
        return;
    }

    constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] =
    {'m','p','i','_','w','o','r','l','d','_','c','o','m','m','u','n','i','c','a','t','o','r'};
    auto mpi_world_communicator = this->mdWorldCommunicatorInvk_->getCopyOfTaskResults<tmpstr>();

    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // Setup all receivers for the control file invoker.
    //
    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    setup_controlfile_receivers(controlfile_name,
                                std::move(mpi_world_communicator),
                                mdControlFileInvk_);

    // ---------------------------------------------------
    // Run macro receiver.
    //
    // ---------------------------------------------------
    const std::vector<ANANSI::TaskLabel> command_labels = {ANANSI::ControlFileMacroReceiver::TASKLABEL};
    this->mdControlFileInvk_->doTask(command_labels);

    return;
}   // -----  end of method AnansiMolecularDynamics::enableControlFileTasks -----

void
AnansiMolecularDynamics::disableControlFileTasks ()
{
    return;
}

void
AnansiMolecularDynamics::enableCoreLoggingTasks()
{

    // To setup the mdCoreLoggingInvk_ we need the world communicator object.
    constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] =
        {'m','p','i','_','w','o','r','l','d','_','c','o','m','m','u','n','i','c','a','t','o','r'};
    auto world_communicator = this->mdWorldCommunicatorInvk_->getCopyOfTaskResults<tmpstr>();

    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // Setup all tasks and receivers for the console logging invoker
    //
    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    setup_core_logging_invoker(this->mdCoreLoggingInvk_,std::move(world_communicator));

    return;
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

bool
AnansiMolecularDynamics::isHelpOnCommandLine_() const
{
    const bool help_found = this->simulationParameters_.isCommandLineOptionPresent("help");
    return help_found;
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

void
AnansiMolecularDynamics::processCommandLine_()
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

    // Change the state of "this", a AnansiMolecularDynamics object, to
    // state MDInitInitialConditions.
    this->mdState_ = this->mdInitInitialConditions_;

    this->mdState_->execute(this);

    // Change the state of "this", a AnansiMolecularDynamics object, to
    // state MDNullSimulationState.
    this->mdState_ = this->mdNullSimulationState_;
    return;
}        // -----  end of method AnansiMolecularDynamics::initializeInitialConditions_  -----

void
AnansiMolecularDynamics::performSimulation_()
{
    return;
}        // -----  end of method AnansiMolecularDynamics::performSimulation_  -----

void
AnansiMolecularDynamics::terminateSimulationEnvironment_()
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

//============================= OPERATORS ====================================


}; /* -----  end of namespace ANANSI  ----- */

