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
#include "GenericTaskInvokerFactory.hpp"

namespace ANANSI
{

void setup_mpi_communication_environment_receivers (std::shared_ptr<ANANSI::GenericTaskInvoker<InitMPIEnvTaskTraits::abstract_products,
        InitMPIEnvTaskTraits::concrete_products>
        > & mpi_comm_invoker,
        const COMMANDLINE::CommandLineArguments & command_line_arguments)
        
{
    mpi_comm_invoker =
        GenericTaskInvokerFactory<InitMPIEnvTaskTraits::abstract_products,InitMPIEnvTaskTraits::concrete_products>::initializeInvoker();

    // Setup the concrete products of typelist InitMPIEnvTaskTraits::concrete_products:
    //      - InitMPIEnvTaskReceiver
    setup_InitMPIEnvTaskReceiver(mpi_comm_invoker,command_line_arguments); 
    return;
}   /* -----  end of function __function__  ----- */


}; // namespace ANANSI

