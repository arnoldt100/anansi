//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_mpi_world_communicator.h"
#include "GenericReceiverFactory.hpp"
#include "GenericTaskInvokerFactory.hpp"
namespace ANANSI
{

void setup_mpi_world_communicator (std::shared_ptr<ANANSI::GenericTaskInvoker<InitWorldCommunicatorTaskTraits::abstract_products,
                                                                              InitWorldCommunicatorTaskTraits::concrete_products>
                                                   > initworldcomm_invoker)
{
    initworldcomm_invoker = 
      GenericTaskInvokerFactory<InitWorldCommunicatorTaskTraits::abstract_products,InitWorldCommunicatorTaskTraits::concrete_products>::initializeInvoker();


    // Setup the concrete products of typelist InitWorldCommunicatorTaskTraits::concrete_products:
    //    - InitWorldCommunicatorTaskReceiver 
    // std::unique_ptr<COMMUNICATOR::CommunicatorFactory> a_communicator_factory = std::make_unique<MPICommunicatorFactory>();
    // auto tmp_communicator = a_communicator_factory->createWorldCommunicator();
    // 
    // auto mpi_init_world_commm_receiver =
    //     RECEIVER::GenericReceiverFactory<InitWorldCommunicatorTaskTraits::abstract_products,
    //     InitWorldCommunicatorTaskTraits::concrete_products>::createSharedReceiver<InitWorldCommunicatorTaskReceiver>();

    // mpi_init_world_commm_receiver->modifyReceiver(tmp_communicator);
    return;
}   // -----  end of function setup_mpi_world_communicator  ----- 


}; // namespace ANANSI

