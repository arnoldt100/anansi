//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationDecompositionTaskTraits.h"
#include "setup_simulationdecomposition_invoker.h"
#include "setup_read_pointatoms_receiver.h"
#include "setup_pointatoms_decomposer_receiver.h"
#include "setup_pointatoms_communicator_receiver.h"

namespace ANANSI
{

void setup_simulationdecomposition_invoker (const SimulationDecompositionParameters & work_load_parameters,
		                                        std::unique_ptr<COMMUNICATOR::Communicator> world_communicator,
                                            std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                       SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulation_decomposer_invoker )
{
    setup_pointatoms_communicator_receiver(work_load_parameters,std::move(world_communicator),simulation_decomposer_invoker);
    setup_pointatoms_decomposer_receiver();
    setup_read_pointatoms_receiver();
    return;
}   // -----  end of function setup_simulationdecomposition_invoker  -----


}; // namespace ANANSI

