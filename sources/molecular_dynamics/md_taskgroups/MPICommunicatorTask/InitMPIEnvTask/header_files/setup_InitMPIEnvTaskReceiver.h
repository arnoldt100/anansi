#ifndef ANANSI_setup_InitMPIEnvTaskReceiver_INC
#define ANANSI_setup_InitMPIEnvTaskReceiver_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "GenericTaskInvoker.hpp"
#include "InitMPIEnvTaskTraits.h"


namespace ANANSI
{

void setup_InitMPIEnvTaskReceiver(std::shared_ptr<ANANSI::GenericTaskInvoker<InitMPIEnvTaskTraits::abstract_products,
        InitMPIEnvTaskTraits::concrete_products>
        > mpi_comm_invoker);


}; // namespace ANANSI

#endif // ANANSI_setup_InitMPIEnvTaskReceiver_INC
