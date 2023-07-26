//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_mpi_communication_environment_receivers.h"
#include "setup_InitMPIEnvTaskReceiver.h"

namespace ANANSI
{

void setup_mpi_communication_environment_receivers (std::shared_ptr<ANANSI::GenericTaskInvoker<InitMPIEnvTaskTraits::abstract_products,
        InitMPIEnvTaskTraits::concrete_products>
        > mpi_comm_invoker)
{
    // Setup the concrete products of typelist InitMPIEnvTaskTraits::concrete_products:
    //      - InitMPIEnvTaskReceiver
    setup_InitMPIEnvTaskReceiver(mpi_comm_invoker); 
    return;
}   /* -----  end of function __function__  ----- */


}; // namespace ANANSI

