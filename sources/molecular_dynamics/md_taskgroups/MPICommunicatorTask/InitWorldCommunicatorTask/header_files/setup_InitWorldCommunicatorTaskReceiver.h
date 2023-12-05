#ifndef ANANSI_setup_InitWorldCommunicatorTaskReceiver_INC
#define ANANSI_setup_InitWorldCommunicatorTaskReceiver_INC

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
#include "InitWorldCommunicatorTaskTraits.h"

namespace ANANSI
{

void setup_InitWorldCommunicatorTaskReceiver (std::shared_ptr<ANANSI::GenericTaskInvoker<InitWorldCommunicatorTaskTraits::abstract_products,
                                                                                         InitWorldCommunicatorTaskTraits::concrete_products>
                                                             > initworldcomm_invoker);

}; /* namespace ANANSI */

#endif // ANANSI_setup_InitWorldCommunicatorTaskReceiver_INC 
