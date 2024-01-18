#ifndef ANANSI_setup_ControlFileXMLTask_INC
#define ANANSI_setup_ControlFileXMLTask_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

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

void setup_ControlFileXMLTask (const std::string controlfile_name,
                                   const bool master_process,  
                                   std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                                              ReadControlFileTraits::concrete_products>
                                                  > control_file_invoker);
}; /* namespace ANANSI */

#endif // ANANSI_setup_ControlFileXMLTask_INC