#ifndef ANANSI_setup_controlfile_receivers_INC
#define ANANSI_setup_controlfile_receivers_INC

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
#include "GenericTaskFactory.hpp"
#include "ReadControlFileTraits.h"
#include "Communicator.h"


namespace ANANSI
{

void setup_controlfile_receivers (const std::string controlfile_name,
                                  std::unique_ptr<COMMUNICATOR::Communicator> my_world_communicator,
                                  std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                                             ReadControlFileTraits::concrete_products>
                                                 > control_file_invoker,
                                  std::shared_ptr<GenericTaskFactory<ReadControlFileTraits::abstract_products,
                                                                     ReadControlFileTraits::concrete_products>
                                                 > my_controlfile_taskfactory );


}; /* namespace ANANSI */

#endif // ANANSI_setup_controlfile_receivers_INC
