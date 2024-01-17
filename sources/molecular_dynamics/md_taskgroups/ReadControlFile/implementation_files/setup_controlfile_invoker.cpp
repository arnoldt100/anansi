//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <memory>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_controlfile_invoker.h"
#include "setup_ControlFileXMLMPICommReceiver.h"
#include "setup_ControlFileXMLTask.h"
#include "setup_ControlFileMacroReceiver.h"
#include "GenericTaskInvokerFactory.hpp"

namespace ANANSI
{

void setup_controlfile_invoker (const std::string controlfile_name,
                                std::unique_ptr<COMMUNICATOR::Communicator> my_world_communicator,
                                std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                                           ReadControlFileTraits::concrete_products>
                                               > & control_file_invoker )
{

    control_file_invoker = 
      GenericTaskInvokerFactory<ReadControlFileTraits::abstract_products,
                                ReadControlFileTraits::concrete_products>::initializeInvoker();

    // Setup the concrete products of typelist ReadControlFileTraits::concrete_products:
    //      - ControlFileXMLReceiver
    //      - ControlFileXMLMPICommReceiver
    //      - ControlFileMacroReceiver

    bool master_process = my_world_communicator->iAmMasterProcess();
    setup_ControlFileXMLTask(controlfile_name,master_process,control_file_invoker);

    setup_ControlFileXMLMPICommReceiver(control_file_invoker, std::move(my_world_communicator)); 

    setup_ControlFileMacroReceiver(control_file_invoker);


    return;
}   // -----  end of function setup_controlfile_invoker


}; // namespace ANANSI

