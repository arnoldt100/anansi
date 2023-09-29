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
#include "GenericTaskFactory.hpp"
#include "GenericReceiverFactory.hpp"

namespace ANANSI
{

void setup_ControlFileXMLReceiver (const std::string controlfile_name,
                                   const bool master_process,  
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
    using base_receiver_t = ANANSI::ControlFileXMLReceiver::MyParentTask; // The base class for the task we are setting up. 
    using concrete_receiver_t = ANANSI::ControlFileXMLReceiver; // The concrete reciever we are setting up.

    // ---------------------------------------------------
    // Get the task label for the task
    // GenericMDTask<ControlFileXMLReceiver>
    //
    // ---------------------------------------------------
    auto constexpr task_label = concrete_receiver_t::TASKLABEL;

    // ---------------------------------------------------
    // Declare the concrete task factory for the these set of concrete task
    // products.
    //
    // ---------------------------------------------------
    auto conrete_task_factory = std::make_unique<GenericTaskFactory<my_abstract_tasks,
                                                                    my_concrete_tasks>
                                                >();

    // ---------------------------------------------------
    // Create the receiver of concrete task 
    // GenericMDTask<ControlFileXMLReceiver>
    //
    // ---------------------------------------------------
    auto control_file_xml_receiver = 
        RECEIVER::GenericReceiverFactory<my_abstract_tasks,my_concrete_tasks>::createSharedReceiver<concrete_receiver_t>();

    // ---------------------------------------------------
    // Now setup the receiver 
    //
    // ---------------------------------------------------
    CommandFileName my_command_file_name(controlfile_name);
    control_file_xml_receiver->modifyReceiver(my_command_file_name);

    MasterProcess my_master_process(master_process);
    control_file_xml_receiver->modifyReceiver(my_master_process);

    // ---------------------------------------------------
    // Create task object and bind the receiver to the task object.
    // 
    // ---------------------------------------------------
    std::shared_ptr<ANANSI::AnansiTask> my_task = 
        conrete_task_factory->create_shared_ptr<base_receiver_t>(control_file_xml_receiver);

    // ---------------------------------------------------
    // Add the task object/command to the invoker.
    //
    // ---------------------------------------------------
    control_file_invoker->addTask(task_label,my_task);

    return;
}   // -----  end of function setup_ControlFileXMLReceiver 


}; // namespace ANANSI

