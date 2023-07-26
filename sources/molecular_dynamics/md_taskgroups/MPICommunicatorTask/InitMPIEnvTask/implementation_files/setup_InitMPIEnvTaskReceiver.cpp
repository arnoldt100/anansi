//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_InitMPIEnvTaskReceiver.h"
#include "GenericTaskFactory.hpp"
#include "GenericReceiverFactory.hpp"

namespace ANANSI
{

void setup_InitMPIEnvTaskReceiver(std::shared_ptr<ANANSI::GenericTaskInvoker<InitMPIEnvTaskTraits::abstract_products,
        InitMPIEnvTaskTraits::concrete_products>
        > mpi_comm_invoker)
{
    // ---------------------------------------------------
    // We define some type aliases to reduce the amount of typing.
    //
    // ---------------------------------------------------
    using my_abstract_tasks = ANANSI::InitMPIEnvTaskTraits::abstract_products; // The abstract task typelist.
    using my_concrete_tasks = ANANSI::InitMPIEnvTaskTraits::concrete_products; // The concrete tasks typelist.
    using base_receiver_t = ANANSI::InterProcessCommEnv;
    using concrete_receiver_t = ANANSI::InitMPIEnvTaskTraits; // The concrete tasks we are setting up.

    return ;
}   // -----  end of function setup_InitMPIEnvTaskReceiver


}; //namespace ANANSI

