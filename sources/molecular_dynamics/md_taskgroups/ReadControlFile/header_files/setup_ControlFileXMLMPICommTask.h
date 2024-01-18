#ifndef ANANSI_setup_ControlFileXMLMPICommTask_INC
#define ANANSI_setup_ControlFileXMLMPICommTask_INC

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
#include "Communicator.h"

namespace ANANSI {

void setup_ControlFileXMLMPICommTask (std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                                                 ReadControlFileTraits::concrete_products>
                                                     > control_file_invoker,
                                      std::unique_ptr<COMMUNICATOR::Communicator> my_world_communicator);


}; /* namespace ANANSI */
#endif /* ANANSI_setup_ControlFileXMLMPICommTask_INC */
