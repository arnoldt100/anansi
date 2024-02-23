//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_pointatoms_communicator_receiver.h"

namespace ANANSI
{

void setup_pointatoms_communicator_receiver (const SimulationDecompositionParameters & work_load_parameters,
                                             std::unique_ptr<COMMUNICATOR::Communicator> world_communicator,
                                             std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                       SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulation_decomposer_invoker)
{
    return;
}   // -----  end of function setup_pointatoms_communicator_receiver  -----


}; // namespace ANANSI

