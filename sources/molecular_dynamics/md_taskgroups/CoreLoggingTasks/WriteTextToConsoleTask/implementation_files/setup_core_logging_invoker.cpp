//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_core_logging_invoker.h"
#include "GenericTaskInvokerFactory.hpp"
#include "setup_WriteTextToConsoleTaskReceiver.h"

namespace ANANSI
{

void setup_core_logging_invoker (std::shared_ptr<ANANSI::GenericTaskInvoker<WriteTextToConsoleTaskTraits::abstract_products,
                                                                            WriteTextToConsoleTaskTraits::concrete_products>
                                                > core_logging_invoker,
                                 std::unique_ptr<COMMUNICATOR::Communicator> world_communicator)
{
    core_logging_invoker = 
        GenericTaskInvokerFactory<WriteTextToConsoleTaskTraits::abstract_products,WriteTextToConsoleTaskTraits::concrete_products>::initializeInvoker();

    setup_WriteTextToConsoleTaskReceiver(core_logging_invoker);

    return ;
}   // -----  end of function setup_core_logging_invoker  -----


}; // namespace ANANSI

