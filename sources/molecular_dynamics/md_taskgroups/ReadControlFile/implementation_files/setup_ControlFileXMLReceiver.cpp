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
    // ---------------------------------------------------
    // We define some type aliases to reduce the amount of typing.
    //
    // ---------------------------------------------------
    using my_abstract_tasks = ReadControlFileTraits::abstract_products; // The abstract task typelist.
    using my_concrete_tasks = ReadControlFileTraits::concrete_products; // The concrete tasks typelist.
    using receiver_t = ANANSI::ControlFileXMLReceiver; // The concrete tasks we are setting up.

    // ---------------------------------------------------
    // Get the task label for the task
    // GenericMDTask<ControlFile,ControlFileXMLReceiver>
    //
    // ---------------------------------------------------
    auto constexpr task_label = receiver_t::TASKLABEL;

    // ---------------------------------------------------
    // Declare the concrete task factory for the these set of concrete task  products.
    //
    // ---------------------------------------------------
    auto conrete_task_factory = std::make_unique<GenericTaskFactory<my_abstract_tasks,
                                                                    my_concrete_tasks>
                                                >();

    // ---------------------------------------------------
    // Create the receiver of concrete task 
    // GenericMDTask<ControlFile,ControlFileXMLReceiver> 
    // ---------------------------------------------------
    auto control_file_xml_receiver = 
        RECEIVER::GenericReceiverFactory<my_abstract_tasks,my_concrete_tasks>::createSharedReceiver<receiver_t>();

    // ---------------------------------------------------
    // Now setup the receiver 
    //
    // ---------------------------------------------------

    // We nead to add to the reciever the control file name

    // Create the task GenericMDTask<ControlFile,ControlFileXMLReceiver> and bind
    // the receiver to it. 
    
    return;
}   // -----  end of function setup_ControlFileXMLReceiver 


}; // namespace ANANSI

