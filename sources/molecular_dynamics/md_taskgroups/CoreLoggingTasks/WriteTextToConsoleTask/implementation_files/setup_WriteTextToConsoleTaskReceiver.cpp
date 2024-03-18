//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_WriteTextToConsoleTaskReceiver.h"
#include "GenericTaskFactory.hpp"
#include "GenericReceiverFactory.hpp"

namespace ANANSI
{

void setup_WriteTextToConsoleTaskReceiver (std::shared_ptr<ANANSI::GenericTaskInvoker<WriteTextToConsoleTaskTraits::abstract_products,
        WriteTextToConsoleTaskTraits::concrete_products>
        > core_logging_invoker,
        std::unique_ptr<COMMUNICATOR::Communicator> world_communicator)
{
    // ---------------------------------------------------
    // We define some type aliases to reduce the amount of typing.
    //
    // ---------------------------------------------------
    using my_abstract_tasks = ANANSI::WriteTextToConsoleTaskTraits::abstract_products; // The abstract tasks typelist.
    using my_concrete_tasks = ANANSI::WriteTextToConsoleTaskTraits::concrete_products; // The concrete tasks typelist.
    using base_receiver_t = ANANSI::WriteTextToConsoleTaskReceiver::MyParentTask; // The base class for the task we are setting up/
    using concrete_receiver_t = ANANSI::WriteTextToConsoleTaskReceiver; // The concrete reciever we are setting up.

    // ---------------------------------------------------
    // Get the task label for the concrete task
    // GenericMDTask<InitMPIEnvTaskReceiver>
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
    // GenericMDTask<InitWorldCommunicatorTaskReceiver>
    //
    // ---------------------------------------------------


    // ---------------------------------------------------
    // Create the receiver and add the communicator.
    //
    // ---------------------------------------------------
    auto my_receiver =
        RECEIVER::GenericReceiverFactory<my_abstract_tasks,
        my_concrete_tasks>::createSharedReceiver<concrete_receiver_t>();
    my_receiver->modifyReceiver(world_communicator);

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
    core_logging_invoker->addTask(task_label,my_task);

    // ---------------------------------------------------
    // Now enable the task.
    //
    // ---------------------------------------------------
    const std::vector<
    std::remove_const<decltype(task_label)>::type
    > command_labels = {task_label};
    core_logging_invoker->enableTask(command_labels);

    // ---------------------------------------------------
    // Log to console that the Console Logger is enabled.
    //
    // ---------------------------------------------------
    std::string sender{"A processor."};
    std::string message{"The console logger is enabled."};
    auto message_packet = std::make_unique<ConsoleMessageContainer>(message,sender);
 
    core_logging_invoker->modifyTask<task_label>(message_packet);
 
    core_logging_invoker->doTask(command_labels);
 
    return ;
}   // -----  end of function setup_WriteTextToConsoleTaskReceiver  -----


}; // namespace ANANSI

