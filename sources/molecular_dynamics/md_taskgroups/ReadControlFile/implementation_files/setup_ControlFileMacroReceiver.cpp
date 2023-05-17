//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_ControlFileMacroReceiver.h"
#include "GenericTaskFactory.hpp"
#include "GenericReceiverFactory.hpp"

namespace ANANSI
{

void setup_ControlFileMacroReceiver (std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                                                ReadControlFileTraits::concrete_products>
                                                    > control_file_invoker)
{
    // ---------------------------------------------------
    // We define some type aliases to reduce the amount of typing.
    //
    // ---------------------------------------------------
    using my_abstract_tasks = ReadControlFileTraits::abstract_products; // The abstract task typelist.
    using my_concrete_tasks = ReadControlFileTraits::concrete_products; // The concrete tasks typelist.
    using base_receiver_t = ReadControlFileTraits::MC; // The base class for the task we are setting up. 
    using concrete_receiver_t = ANANSI::ControlFileMacroReceiver; // The concrete tasks we are setting up.

    // ---------------------------------------------------
    // Get the task label for the task
    // GenericMDTask<ControlFile,ControlFileMacroReceiver>
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
    // GenericMDTask<MC,ControlFileMacroReceiver> 
    // ---------------------------------------------------
    auto control_file_xmlmacro_receiver = 
        RECEIVER::GenericReceiverFactory<my_abstract_tasks,my_concrete_tasks>::createSharedReceiver<concrete_receiver_t>();

    // ---------------------------------------------------
    // Create task object and bind the receiver to the task object.
    // 
    // ---------------------------------------------------
    std::shared_ptr<ANANSI::AnansiTask> my_task = 
        conrete_task_factory->create_shared_ptr<base_receiver_t>(control_file_xmlmacro_receiver);

    // ---------------------------------------------------
    // Add the task object/command to the invoker.
    //
    // ---------------------------------------------------
    control_file_invoker->addTask(task_label,my_task);

    return;
}   /* -----  end of function __function__  ----- */


}; /* namespace __NAMESPACE__ */
