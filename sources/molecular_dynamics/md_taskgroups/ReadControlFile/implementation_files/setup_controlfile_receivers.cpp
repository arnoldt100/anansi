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

    setup_ControlFileXMLReceiver();


    setup_ControlFileXMLMPICommReceiver(); 


    return;
}   // -----  end of function setup_controlfile_receivers


}; // namespace ANANSI

