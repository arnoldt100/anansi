#ifndef ANANSI_setup_ControlFileMacroReceiver_INC
#define ANANSI_setup_ControlFileMacroReceiver_INC

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
#include "ReadControlFileTraits.h"


namespace ANANSI
{

void setup_ControlFileMacroReceiver (std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                                                ReadControlFileTraits::concrete_products>
                                                    > control_file_invoker);


}; /* namespace ANANSI */

#endif /* ANANSI_setup_ControlFileMacroReceiver_INC */
