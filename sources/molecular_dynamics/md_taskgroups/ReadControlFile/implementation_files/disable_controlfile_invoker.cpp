//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "disable_controlfile_invoker.h"

namespace ANANSI
{

void disable_controlfile_invoker (  std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                    ReadControlFileTraits::concrete_products>
                                                   > & control_file_invoker)
{
    // this->mdControlFileInvk_->disableTask(command_labels);
    return ;
}   // -----  end of function disable_controlfile_invoker  -----


}; // namespace ANANSI

