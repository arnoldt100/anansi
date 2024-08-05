#ifndef ANANSI_setup_mpi_world_communicator_INC
#define ANANSI_setup_mpi_world_communicator_INC

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
#include "InitWorldCommunicatorTaskTraits.h"
#include "MPICommunicatorFactory.h"

namespace ANANSI
{

void setup_mpi_world_communicator_invoker (std::shared_ptr<ANANSI::GenericTaskInvoker<InitWorldCommunicatorTaskTraits::abstract_products,
                                                                              InitWorldCommunicatorTaskTraits::concrete_products>
                                                   > & initworldcomm_invoker);

}; // namespace ANANSI

#endif // ANANSI_setup_mpi_world_communicator_INC
