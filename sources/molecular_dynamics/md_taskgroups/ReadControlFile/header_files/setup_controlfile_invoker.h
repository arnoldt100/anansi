#ifndef ANANSI_setup_controlfile_invoker_INC
#define ANANSI_setup_controlfile_invoker_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "GenericTaskInvoker.hpp"
#include "ReadControlFileTraits.h"
#include "Communicator.h"


namespace ANANSI
{

void setup_controlfile_invoker (const std::string controlfile_name,
                                  std::unique_ptr<COMMUNICATOR::Communicator> my_world_communicator,
                                  std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                                             ReadControlFileTraits::concrete_products>
                                                 > & control_file_invoker);


}; /* namespace ANANSI */

#endif // ANANSI_setup_controlfile_invoker_INC
