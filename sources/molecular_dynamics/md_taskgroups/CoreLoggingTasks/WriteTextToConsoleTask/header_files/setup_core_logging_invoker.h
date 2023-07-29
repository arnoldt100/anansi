#ifndef ANANSI_setup_core_logging_invoker_INC
#define ANANSI_setup_core_logging_invoker_INC

//! \file setup_core_logging_invoker.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "GenericTaskInvoker.hpp"
#include "WriteTextToConsoleTaskTraits.h"


namespace ANANSI
{

//! \brief Stud text for brief description
void setup_core_logging_invoker (std::shared_ptr<ANANSI::GenericTaskInvoker<WriteTextToConsoleTaskTraits::abstract_products,
        WriteTextToConsoleTaskTraits::concrete_products>
        > core_logging_invoker);


}; // namespace ANANSI

#endif // ANANSI_setup_core_logging_invoker_INC
