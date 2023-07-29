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

namespace ANANSI
{

void setup_core_logging_invoker (std::shared_ptr<ANANSI::GenericTaskInvoker<WriteTextToConsoleTaskTraits::abstract_products,
                                                                            WriteTextToConsoleTaskTraits::concrete_products>
                                                > core_logging_invoker)
{
    core_logging_invoker = 
        GenericTaskInvokerFactory<WriteTextToConsoleTaskTraits::abstract_products,WriteTextToConsoleTaskTraits::concrete_products>::initializeInvoker();
    return ;
}   // -----  end of function setup_core_logging_invoker  -----


}; // namespace ANANSI

