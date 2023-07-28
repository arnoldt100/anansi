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
#include "setup_InitWorldCommunicatorTaskReceiver.h"
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
    setup_InitWorldCommunicatorTaskReceiver(initworldcomm_invoker);

    return;
}   // -----  end of function setup_mpi_world_communicator  ----- 


}; // namespace ANANSI

