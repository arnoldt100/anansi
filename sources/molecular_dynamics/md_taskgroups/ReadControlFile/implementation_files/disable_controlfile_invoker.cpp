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
  // Disable the concrete products of typelist
  // ReadControlFileTraits::concrete_products in the following order:
  //      - ControlFileMacroReceiver
  //      - ControlFileXMLMPICommReceiver
  //      - ControlFileXMLReceiver
  const std::vector<ANANSI::TaskLabel> command_labels = {
      ControlFileXMLReceiver::TASKLABEL,
      ControlFileXMLMPICommReceiver::TASKLABEL,
      ControlFileXMLReceiver::TASKLABEL};
  control_file_invoker->disableTask(command_labels);

  return;
}   // -----  end of function disable_controlfile_invoker  -----


}; // namespace ANANSI

