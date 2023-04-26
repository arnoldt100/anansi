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
#include "GenericTaskInvokerFactory.hpp"
#include "InterProcessCommEnv.h"
#include "GenericReceiverFactory.hpp"
#include "InitMPIEnvTaskReceiver.h"
#include "ConsoleMessageContainer.h"

#include "initialize_controlfile_invoker_and_taskfactory.h"
#include "setup_controlfile_receivers.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= ACCESSORS ====================================
template<>
void AnansiMolecularDynamics::enableConsoleLoggingTask_<WriteTextToConsoleTaskTraits::abstract_products,
                                                        WriteTextToConsoleTaskTraits::concrete_products
                                                       >(
    std::shared_ptr<ANANSI::GenericTaskInvoker<WriteTextToConsoleTaskTraits::abstract_products,
                                               WriteTextToConsoleTaskTraits::concrete_products>
                   > & core_logging_invoker,
    std::unique_ptr<COMMUNICATOR::Communicator> & a_communicator )
{
    // ---------------------------------------------------
    // Create the receiver and add the communicator.
    // 
    // ---------------------------------------------------
    auto console_logger_receiver =
        RECEIVER::GenericReceiverFactory<WriteTextToConsoleTaskTraits::abstract_products,
                                         WriteTextToConsoleTaskTraits::concrete_products>::createSharedReceiver<ANANSI::WriteTextToConsoleTaskReceiver>();

    // The console receiver contains the a communicator.
    console_logger_receiver->modifyReceiver(a_communicator);
    
    // ---------------------------------------------------
    // Create task object and bind to receiver.
    // 
    // ---------------------------------------------------
    std::shared_ptr<ANANSI::AnansiTask> console_logger_cmd = 
        this->mdAnansiCoreLoggingTaskFactory_->create_shared_ptr<ConsoleLoggingTask>(console_logger_receiver);

    // ---------------------------------------------------
    // Add the task object/command to the invoker.
    // 
    // ---------------------------------------------------
    constexpr auto my_label = ANANSI::WriteTextToConsoleTaskReceiver::TASKLABEL;
    core_logging_invoker->addTask(my_label,console_logger_cmd);

    // ---------------------------------------------------
    // Log to console that the Console Logger is enabled.
    // 
    // ---------------------------------------------------
    std::string sender{"A processor."};
    std::string message{"The console logger is enabled."};
    auto message_packet = std::make_unique<ConsoleMessageContainer>(message,sender);  

    // core_logging_invoker->modifyTask(my_label,message_packet);
    core_logging_invoker->modifyTask<my_label>(message_packet);

    const std::vector<
                       std::remove_const<decltype(my_label)>::type
                     > command_labels = {my_label};
    core_logging_invoker->doTask(command_labels);

    auto tmp_value = core_logging_invoker->getCopyOfTaskResults<my_label>();

    return;
}

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
    mdAnansiMPIEnvTaskFactory_(nullptr),
    mdAnansiInitWorldCommunicatorTaskFactory_(nullptr),
    mdAnansiCoreLoggingTaskFactory_(nullptr),
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
    mdAnansiMPIEnvTaskFactory_(nullptr),
    mdAnansiInitWorldCommunicatorTaskFactory_(nullptr),
    mdAnansiCoreLoggingTaskFactory_(nullptr),
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

    // Initialiing the InitMPIEnvTask
    this->mdAnansiMPIEnvTaskFactory_ = std::make_shared<GenericTaskFactory<InitMPIEnvTaskTraits::abstract_products,
                                                                           InitMPIEnvTaskTraits::concrete_products>
                                                       >();


    // Initialiing the InitWorldCommunicator 
    std::shared_ptr<GenericTaskInvokerFactory<InitWorldCommunicatorTaskTraits::abstract_products,
                                              InitWorldCommunicatorTaskTraits::concrete_products>
                   > mdWorldCommunicatorInvkFactory = 
        std::make_shared<GenericTaskInvokerFactory<InitWorldCommunicatorTaskTraits::abstract_products,
                                                   InitWorldCommunicatorTaskTraits::concrete_products>
                        >();

    this->mdWorldCommunicatorInvk_ = mdWorldCommunicatorInvkFactory->create_shared_ptr();


    this->mdAnansiInitWorldCommunicatorTaskFactory_ = std::make_shared<GenericTaskFactory<InitWorldCommunicatorTaskTraits::abstract_products,
                                                                                          InitWorldCommunicatorTaskTraits::concrete_products>
                                                                      >();
    //-

    this->mdAnansiCoreLoggingTaskFactory_ = std::make_shared<GenericTaskFactory<WriteTextToConsoleTaskTraits::abstract_products,
                                                                                WriteTextToConsoleTaskTraits::concrete_products>
                                                            >();

    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // Initialzing the ControlFile invoker and task factory.
    //
    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    auto [x,y] = initialize_controlfileinvoker_and_taskfactory();
    this->mdControlFileInvk_ = x;
    this->mdAnansiControlFileTaskFactory_ = y; 

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
void AnansiMolecularDynamics::enableCommunicationEnvironment()
{

    // ---------------------------------------------------
    //  Create the invoker for 'InitMPIEnvTask'. 
    // 
    // ---------------------------------------------------
    std::shared_ptr<GenericTaskInvokerFactory<InitMPIEnvTaskTraits::abstract_products,
                                              InitMPIEnvTaskTraits::concrete_products>
                   > mdCommEnvInvkFactory = 
        std::make_shared<GenericTaskInvokerFactory<InitMPIEnvTaskTraits::abstract_products,
                                                   InitMPIEnvTaskTraits::concrete_products>
                        >();
    this->mdCommEnvInvk_ = mdCommEnvInvkFactory->create_shared_ptr();

    // ---------------------------------------------------
    //  Create the mpi environment receiver and enable it.
    // 
    // ---------------------------------------------------
    std::shared_ptr<ANANSI::MPIEnvironment> mpi_environment = std::make_shared<ANANSI::MPIEnvironment>();
    mpi_environment->addMember(this->commandLineArguments_);
    auto mpi_environment_receiver = 
        RECEIVER::GenericReceiverFactory<InitMPIEnvTaskTraits::abstract_products,
                                         InitMPIEnvTaskTraits::concrete_products>::createSharedReceiver<ANANSI::InitMPIEnvTaskReceiver>();
    mpi_environment_receiver->modifyReceiver(mpi_environment); 
    
    // ---------------------------------------------------
    //  Create the mpi environment task object and bind the 
    //  mpi receiver to it.
    // 
    // ---------------------------------------------------
    std::shared_ptr<ANANSI::AnansiTask> mpi_environment_cmd = 
        this->mdAnansiMPIEnvTaskFactory_->create_shared_ptr<InterProcessCommEnv>(mpi_environment_receiver);
    
    // ---------------------------------------------------
    // Add the task object/command to the invoker.
    // 
    // ---------------------------------------------------
    constexpr auto my_label = ANANSI::InitMPIEnvTaskReceiver::TASKLABEL;
    this->mdCommEnvInvk_->addTask(my_label,mpi_environment_cmd);

    // ---------------------------------------------------
    // Use the invoker to initialize the communication environment.
    // 
    // ---------------------------------------------------
    const std::vector< 
                       std::remove_const<decltype(my_label)>::type
                     > command_labels = {my_label};

    // ---------------------------------------------------
    // Enable all tasks.
    //
    // ---------------------------------------------------
    this->mdCommEnvInvk_->enableTask(command_labels);

    this->mdCommEnvInvk_->doTask(command_labels);

    return;
}

void
AnansiMolecularDynamics::disableCommunicationEnvironment()
{
    // ---------------------------------------------------
    // Use the invoker to initialize the communication environment.
    // 
    // ---------------------------------------------------
    constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = {
        'm','p', 'i', '_','e','n','v','i','r','o','n','m','e','n','t'
    };

    const std::vector<ANANSI::TaskLabel> command_labels = {ANANSI::TaskLabel(tmpstr)};

    this->mdCommEnvInvk_->disableTask(command_labels);
    return;

}       /* -----  end of method AnansiMolecularDynamics::disableCommunicationEnvironment  ----- */


void AnansiMolecularDynamics::enableWorldCommunicator()
{
    // ---------------------------------------------------
    //  Create the receiver and enable it.
    // 
    // ---------------------------------------------------
    std::unique_ptr<COMMUNICATOR::CommunicatorFactory> a_communicator_factory = std::make_unique<MPICommunicatorFactory>(); 
    this->MpiWorldCommunicator_ = a_communicator_factory->createWorldCommunicator();
    auto tmp_communicator = a_communicator_factory->cloneCommunicator(this->MpiWorldCommunicator_);

    auto mpi_init_world_commm_receiver = 
        RECEIVER::GenericReceiverFactory<InitWorldCommunicatorTaskTraits::abstract_products,
                                         InitWorldCommunicatorTaskTraits::concrete_products>::createSharedReceiver<InitWorldCommunicatorTaskReceiver>();

    mpi_init_world_commm_receiver->modifyReceiver(tmp_communicator);

    // ---------------------------------------------------
    //  Get the label for this receiver.   
    // 
    // ---------------------------------------------------
    const auto tmp_label = mpi_init_world_commm_receiver->getTaskLabel();

    // ---------------------------------------------------
    //  Create the task object and bind the 
    //  receiver to it.
    // 
    // ---------------------------------------------------
    std::shared_ptr<ANANSI::AnansiTask> mpi_init_world_communicator_cmd = 
            this->mdAnansiInitWorldCommunicatorTaskFactory_->create_shared_ptr<CommunicatorTask>(mpi_init_world_commm_receiver);

    // ---------------------------------------------------
    // Add the task object/command to the invoker.
    // 
    // ---------------------------------------------------
    this->mdWorldCommunicatorInvk_->addTask(tmp_label,mpi_init_world_communicator_cmd);
   
    // ---------------------------------------------------
    // Use the invoker to initialize the world communicator.
    // 
    // ---------------------------------------------------
    constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
    {'m','p','i','_','w','o','r','l','d','_','c','o','m','m','u','n','i','c','a','t','o','r'};

    const std::vector<ANANSI::TaskLabel> command_labels = {ANANSI::TaskLabel(tmpstr)};

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
    constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = {
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
    const auto mpi_communicator = this->mdWorldCommunicatorInvk_->getCopyOfTaskResults<tmpstr>();

    // // Create the control file parser and process the control file.
    // ANANSI::MPICommunicatorFactory a_communicator_factory;
    // std::shared_ptr<COMMUNICATOR::Communicator> a_communicator = a_communicator_factory.cloneCommunicator(this->MpiWorldCommunicator_);




    // StandardFileParserFactory file_parser_factory;
    // std::shared_ptr<BuilderFileParser> control_file_builder = std::make_shared<BuilderControlFileParser>();
    // std::shared_ptr<FileParser> control_file = file_parser_factory.create(control_file_builder,
    //                                                                       file_name,
    //                                                                       std::move(a_communicator));

    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    // Setup all receivers for the control file invoker.
    //
    // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    setup_controlfile_receivers(controlfile_name); 

    // ---------------------------------------------------
    // 
    //
    // ---------------------------------------------------



    // control_file->readFile();

    return;
}   /* -----  end of method AnansiMolecularDynamics::enableControlFileTasks ----- */

void
AnansiMolecularDynamics::disableControlFileTasks ()
{
    return;
}

void AnansiMolecularDynamics::enableCoreLoggingTasks()
{
    // ---------------------------------------------------
    // Create the invoker for the task WriteTextToConsoleTaskTraits 
    // 
    // All receivers for this invoker will have labels that are of type
    // std::string. 
    // ---------------------------------------------------
    std::shared_ptr<GenericTaskInvokerFactory<WriteTextToConsoleTaskTraits::abstract_products,
                                              WriteTextToConsoleTaskTraits::concrete_products>
                   > mdAnansiCoreLoggingTaskFactory = 
        std::make_shared<GenericTaskInvokerFactory<WriteTextToConsoleTaskTraits::abstract_products,
                                                   WriteTextToConsoleTaskTraits::concrete_products>
                        >();

     this->mdCoreLoggingInvk_ = mdAnansiCoreLoggingTaskFactory->create_shared_ptr();


    // ---------------------------------------------------
    // Enable the Console logger.
    // 
    // ---------------------------------------------------
    std::unique_ptr<COMMUNICATOR::CommunicatorFactory> a_communicator_factory = std::make_unique<MPICommunicatorFactory>(); 
    auto tmp_communicator = a_communicator_factory->cloneCommunicator(this->MpiWorldCommunicator_);
    this->enableConsoleLoggingTask_<WriteTextToConsoleTaskTraits::abstract_products,
                                    WriteTextToConsoleTaskTraits::concrete_products
                                   >(this->mdCoreLoggingInvk_,
                                     tmp_communicator);

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

bool AnansiMolecularDynamics::isHelpOnCommandLine_() const
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

//============================= OPERATORS ====================================


}; /* -----  end of namespace ANANSI  ----- */

