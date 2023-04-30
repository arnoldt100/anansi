//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_ControlFileXMLReceiver.h"

namespace ANANSI
{

void setup_ControlFileXMLReceiver (const std::string controlfile_name,
                                   std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                                              ReadControlFileTraits::concrete_products>
                                                  > control_file_invoker)
{
    return;
}   // -----  end of function setup_ControlFileXMLReceiver 


}; // namespace ANANSI

