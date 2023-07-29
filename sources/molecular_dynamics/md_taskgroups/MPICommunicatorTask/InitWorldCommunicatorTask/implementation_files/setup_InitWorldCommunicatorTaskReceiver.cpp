//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_InitWorldCommunicatorTaskReceiver.h"
#include "GenericTaskFactory.hpp"
#include "GenericReceiverFactory.hpp"
#include "MPICommunicatorFactory.h"

namespace ANANSI
{

void setup_InitWorldCommunicatorTaskReceiver (std::shared_ptr<ANANSI::GenericTaskInvoker<InitWorldCommunicatorTaskTraits::abstract_products,
                                                                                         InitWorldCommunicatorTaskTraits::concrete_products>
                                                             > initworldcomm_invoker)
{


    // ---------------------------------------------------
    // We define some type aliases to reduce the amount of typing.
    //
    // ---------------------------------------------------
    using my_abstract_tasks = ANANSI::InitWorldCommunicatorTaskTraits::abstract_products; // The abstract tasks typelist.
    using my_concrete_tasks = ANANSI::InitWorldCommunicatorTaskTraits::concrete_products; // The concrete tasks typelist.
    using base_receiver_t = ANANSI::InitWorldCommunicatorTaskReceiver::MyParentTask; // The base class for the task we are setting up/
    using concrete_receiver_t = ANANSI::InitWorldCommunicatorTaskReceiver; // The concrete reciever we are setting up.

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
    // GenericMDTask<CommunicatorTask,InitWorldCommunicatorTaskReceiver> 
    //
    // ---------------------------------------------------
    auto my_receiver =
        RECEIVER::GenericReceiverFactory<my_abstract_tasks,
                                         my_concrete_tasks>::createSharedReceiver<concrete_receiver_t>();
    std::unique_ptr<COMMUNICATOR::CommunicatorFactory> a_communicator_factory = std::make_unique<MPICommunicatorFactory>();
    auto tmp_communicator = a_communicator_factory->createWorldCommunicator();
    my_receiver->modifyReceiver(tmp_communicator);

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
    initworldcomm_invoker->addTask(task_label,my_task);

    return ;
}   // -----  end of function setup_InitWorldCommunicatorTaskReceiver -----


}; /* namespace ANANSI */

