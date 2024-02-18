//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "disable_simulationdecomposition_invoker.h"
#include "SimulationDecompositionTaskTraits.h"
#include "GenericTaskInvoker.hpp"

namespace ANANSI
{

void disable_simulationdecomposition_invoker (std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                       SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulatiion_decomposer_invoker)
{
    // Disable the concrete products of typelist 
    // SimulationDecompositionTaskTraits:;concrete_products in the 
    // following order
    //      - PointAtomsCommunicator
    //      - ReadPointAtoms
    //      - PointAtomsDecomposer
    const std::vector<ANANSI::TaskLabel> command_labels = {
         PointAtomsCommunicator::TASKLABEL,
         ReadPointAtoms::TASKLABEL,
         PointAtomsDecomposer::TASKLABEL};
    simulatiion_decomposer_invoker->disableTask(command_labels);

    return;
}   // -----  end of function disable_simulationdecomposition_invoker  -----


}; // namespace ANANSI

