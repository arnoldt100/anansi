#ifndef ANANSI_setup_mpi_communication_environment_receivers_INC
#define ANANSI_setup_mpi_communication_environment_receivers_INC

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
#include "GenericTaskInvoker.hpp"
#include "InitMPIEnvTaskTraits.h"


namespace ANANSI
{

//! \brief Enables the MPI communcation environment.
void setup_mpi_communication_environment_receivers (std::shared_ptr<ANANSI::GenericTaskInvoker<InitMPIEnvTaskTraits::abstract_products,
        InitMPIEnvTaskTraits::concrete_products>
        > mpi_comm_invoker);


}; // namespace ANANSI

#endif /* ANANSI_setup_mpi_communication_environment_receivers_INC */
