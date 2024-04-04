#ifndef ANANSI_setup_pointatoms_communicator_receiver_INC
#define ANANSI_setup_pointatoms_communicator_receiver_INC

//! \file setup_pointatoms_communicator_receiver.h

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
#include "Communicator.h"
#include "GenericTaskInvoker.hpp"
#include "SimulationDecompositionTaskTraits.h"

namespace ANANSI
{

//! \brief Setups the receiver PointAtomsCommunicator.
//!
//! \param The world c
//ommunicator.
void setup_pointatoms_communicator_receiver (std::shared_ptr<COMMUNICATOR::Communicator> rect_world_communicator,
                                             std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                        SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulation_decomposer_invoker);


}; // namespace ANANSI

#endif // ANANSI_setup_pointatoms_communicator_receiver_INC
