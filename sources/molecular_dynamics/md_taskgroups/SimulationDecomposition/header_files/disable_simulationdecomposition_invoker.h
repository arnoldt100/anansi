#ifndef ANANSI_disable_simulationdecomposition_invoker_INC
#define ANANSI_disable_simulationdecomposition_invoker_INC

//! \file disable_simulationdecomposition_invoker.h

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
#include "SimulationDecompositionTaskTraits.h"

namespace ANANSI
{

void disable_simulationdecomposition_invoker (std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                       SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulatiion_decomposer_invoker);


}; // namespace ANANSI

#endif // ANANSI_disable_simulationdecomposition_invoker_INC
