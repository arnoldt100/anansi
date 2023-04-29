//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_controlfile_receivers.h"

namespace ANANSI
{

void setup_controlfile_receivers (const std::string controlfile_name,
                                  std::unique_ptr<COMMUNICATOR::Communicator> my_world_communicator,
                                  std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                                             ReadControlFileTraits::concrete_products>
                                                 > control_file_invoker,
                                  std::shared_ptr<GenericTaskFactory<ReadControlFileTraits::abstract_products,
                                                                     ReadControlFileTraits::concrete_products>
                                                 > my_controlfile_taskfactory )
{
    return;
}   // -----  end of function setup_controlfile_receivers


}; // namespace ANANSI

