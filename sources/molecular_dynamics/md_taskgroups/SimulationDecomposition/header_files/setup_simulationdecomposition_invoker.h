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

//! \details The function sets the generic task invoker that has the responsibility of deccomposing the atoms.
//!
//! \param [in] work_load_parameters This object contains the parameters for the simulation workload decomposition.
//! \param [in,out] simulatiion_decomposer_invoker  The task invoker that does the simulation workload decomposition.
void setup_simulationdecomposition_invoker (const SimulationDecompositionParameters & work_load_parameters,
                                            std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                       SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulatiion_decomposer_invoker );

}; // namespace ANANSI

#endif // ANANSI_setup_simulationdecomposition_invoker_INC
