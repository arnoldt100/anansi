//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "setup_simulationdecomposition_invoker.h"
#include "setup_read_pointatoms_receiver.h"
#include "setup_pointatoms_decomposer_receiver.h"

namespace ANANSI
{

void setup_simulationdecomposition_invoker (const SimulationDecompositionParameters & work_load_parameters,
                                            std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                       SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulatiion_decomposer_invoker )
{
    setup_read_pointatoms_receiver();
    setup_pointatoms_decomposer_receiver();
    return;
}   // -----  end of function setup_simulationdecomposition_invoker  -----


}; // namespace ANANSI

