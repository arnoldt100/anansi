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
#include "SimulationDecompositionParameters.h"
#include "GenericTaskInvokerFactory.hpp"
#include "SimulationDecompositionTaskTraits.h"

namespace ANANSI
{

//! \brief Setups the receiver PointAtomsCommunicator.
//!
//! \param The world communicator.
void setup_pointatoms_communicator_receiver (const SimulationDecompositionParameters & work_load_parameters,
                                             std::unique_ptr<COMMUNICATOR::Communicator> world_communicator,
                                             std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                        SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulation_decomposer_invoker);


}; // namespace ANANSI

#endif // ANANSI_setup_pointatoms_communicator_receiver_INC
