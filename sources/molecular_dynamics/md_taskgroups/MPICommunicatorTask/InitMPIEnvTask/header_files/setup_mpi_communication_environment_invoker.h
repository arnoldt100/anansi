#ifndef ANANSI_setup_mpi_communication_environment_invoker_INC
#define ANANSI_setup_mpi_communication_environment_invoker_INC

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
#include "CommandLineArguments.h"


namespace ANANSI
{

//! \brief Enables the MPI communcation environment.
void setup_mpi_communication_environment_invoker (std::shared_ptr<ANANSI::GenericTaskInvoker<InitMPIEnvTaskTraits::abstract_products,
        InitMPIEnvTaskTraits::concrete_products>
        > & mpi_comm_invoker,
        const COMMANDLINE::CommandLineArguments & command_line_arguments);


}; // namespace ANANSI

#endif /* ANANSI_setup_mpi_communication_environment_invoker_INC */