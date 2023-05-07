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
#include "setup_ControlFileXMLMPICommReceiver.h"
#include "setup_ControlFileXMLReceiver.h"

namespace ANANSI
{

void setup_controlfile_receivers (const std::string controlfile_name,
                                  std::unique_ptr<COMMUNICATOR::Communicator> my_world_communicator,
                                  std::shared_ptr<ANANSI::GenericTaskInvoker<ReadControlFileTraits::abstract_products,
                                                                             ReadControlFileTraits::concrete_products>
                                                 > control_file_invoker )
{

    // Setup the concrete products of typelist ReadControlFileTraits::concrete_products:
    //      - ControlFileXMLReceiver
    //      - ControlFileXMLMPICommReceiver

    bool master_process = my_world_communicator->iAmMasterProcess();
    setup_ControlFileXMLReceiver(controlfile_name,master_process,control_file_invoker);

    setup_ControlFileXMLMPICommReceiver(); 

    return;
}   // -----  end of function setup_controlfile_receivers


}; // namespace ANANSI

