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
#include "GenericReceiverFactory.hpp"

namespace ANANSI
{

void setup_ControlFileXMLReceiver (const std::string controlfile_name,
                                   std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                                              ReadControlFileTraits::concrete_products>
                                                  > control_file_invoker)
{
    using receiver_t = ANANSI::ControlFileXMLReceiver;
    using my_abstract_products = ReadControlFileTraits::abstract_products;
    using my_concrete_products = ReadControlFileTraits::concrete_products;

    // Get the task label for the GenericMDTask<ControlFile,ControlFileXMLReceiver>
    auto constexpr task_label = receiver_t::TASKLABEL;

    // Create the receiver of task GenericMDTask<ControlFile,ControlFileXMLReceiver> 
    auto control_file_xml_receiver = 
        RECEIVER::GenericReceiverFactory<ReadControlFileTraits::abstract_products,
                                         ReadControlFileTraits::concrete_products>::createSharedReceiver<receiver_t>();


    // We nead to add to the reciever the control file name

    // Create the task GenericMDTask<ControlFile,ControlFileXMLReceiver> and bind
    // the receiver to it. 

    return;
}   // -----  end of function setup_ControlFileXMLReceiver 


}; // namespace ANANSI

