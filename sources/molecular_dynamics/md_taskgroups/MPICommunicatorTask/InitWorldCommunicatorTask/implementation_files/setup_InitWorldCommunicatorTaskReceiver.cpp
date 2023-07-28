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
    using my_abstract_tasks = ANANSI::InitWorldCommunicatorTaskTraits::abstract_products; // The abstract task typelist.
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
    std::unique_ptr<COMMUNICATOR::CommunicatorFactory> a_communicator_factory = std::make_unique<MPICommunicatorFactory>();
    auto tmp_communicator = a_communicator_factory->createWorldCommunicator();
    auto mpi_init_world_commm_receiver =
        RECEIVER::GenericReceiverFactory<InitWorldCommunicatorTaskTraits::abstract_products,
                                         InitWorldCommunicatorTaskTraits::concrete_products>::createSharedReceiver<InitWorldCommunicatorTaskReceiver>();
    mpi_init_world_commm_receiver->modifyReceiver(tmp_communicator);


    return ;
}   // -----  end of function setup_InitWorldCommunicatorTaskReceiver -----


}; /* namespace ANANSI */

