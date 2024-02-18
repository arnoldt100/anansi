#ifndef ANANSI_setup_simulationdecomposition_invoker_INC
#define ANANSI_setup_simulationdecomposition_invoker_INC

//! \file setup_simulationdecomposition_invoker.h

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
#include "SimulationDecompositionTaskTraits.h"
#include "GenericTaskInvoker.hpp"
#include "SimulationDecompositionParameters.h"

namespace ANANSI
{

void setup_simulationdecomposition_invoker (const SimulationDecompositionParameters & work_load_parameters,
                                            std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                       SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulatiion_decomposer_invoker );

}; // namespace ANANSI

#endif // ANANSI_setup_simulationdecomposition_invoker_INC
