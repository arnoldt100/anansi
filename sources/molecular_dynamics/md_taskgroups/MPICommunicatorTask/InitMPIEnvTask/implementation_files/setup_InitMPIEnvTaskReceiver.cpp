//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_InitMPIEnvTaskReceiver.h"
#include "GenericTaskFactory.hpp"
#include "GenericReceiverFactory.hpp"

namespace ANANSI
{

void setup_InitMPIEnvTaskReceiver(std::shared_ptr<ANANSI::GenericTaskInvoker<InitMPIEnvTaskTraits::abstract_products,
        InitMPIEnvTaskTraits::concrete_products>
        > mpi_comm_invoker,
        const COMMANDLINE::CommandLineArguments & command_line_arguments)
{
    // ---------------------------------------------------
    // We define some type aliases to reduce the amount of typing.
    //
    // ---------------------------------------------------
    using my_abstract_tasks = ANANSI::InitMPIEnvTaskTraits::abstract_products; // The abstract task typelist.
    using my_concrete_tasks = ANANSI::InitMPIEnvTaskTraits::concrete_products; // The concrete tasks typelist.
    using base_receiver_t = ANANSI::InitMPIEnvTaskReceiver::MyParentTask; // The base class for the task we are setting up/
    using concrete_receiver_t = ANANSI::InitMPIEnvTaskReceiver; // The concrete reciever we are setting up.

    // ---------------------------------------------------
    // Get the task label for the concrete task
    // GenericMDTask<ANANSI::InitMPIEnvTaskReceiver::MyParentTask,InitMPIEnvTaskReceiver>
    //
    // ---------------------------------------------------
    auto constexpr task_label = concrete_receiver_t::TASKLABEL;

    // ---------------------------------------------------
    // Declare the concrete task factory for the these set of concrete task
    // products.
    //
    // ---------------------------------------------------
    auto conrete_task_factory = std::make_unique<GenericTaskFactory<my_abstract_tasks,
                                                                    my_concrete_tasks>
                                                >();

    // ---------------------------------------------------
    // Create the receiver for the concrete task 
    // GenericMDTask<InterProcessCommEnv,InitMPIEnvTaskReceiver> 
    // ---------------------------------------------------
    auto my_receiver = 
        RECEIVER::GenericReceiverFactory<my_abstract_tasks,my_concrete_tasks>::createSharedReceiver<concrete_receiver_t>();

    // ---------------------------------------------------
    // Now setup the receiver 
    //
    // ---------------------------------------------------
    // Nothing to setup

    // ---------------------------------------------------
    // Create task object and bind the receiver to the task object.
    // 
    // ---------------------------------------------------
    std::shared_ptr<ANANSI::AnansiTask> my_task = 
        conrete_task_factory->create_shared_ptr<base_receiver_t>(my_receiver);

    // ---------------------------------------------------
    // Add the task object/command to the invoker.
    //
    // ---------------------------------------------------
    mpi_comm_invoker->addTask(task_label,my_task);

    return ;
}   // -----  end of function setup_InitMPIEnvTaskReceiver


}; //namespace ANANSI

