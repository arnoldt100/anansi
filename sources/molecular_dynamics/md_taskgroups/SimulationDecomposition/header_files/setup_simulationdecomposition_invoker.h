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

//! \brief The function sets up the generic task invoker that has the responsibility doing workload decomposition of the atoms.
//!
//! \details The responsibility of this invoker is to  distrubuted among the processing units the atoms of the system. We call this deccomposing the
//!          the atoms. There are 2 kinds of atoms decomposition supported, spatial and replicated data decomposition. The parameter 
//!          contains information that determines which type of workload decomposition and the topology of the decomposition. If this
//!          workload decomposition fails, then the function will throw an error. The error should be handles by terminating the program for 
//!          it is is an unrecoverable state.
//!
//! \param [in] work_load_parameters This object contains the parameters for the simulation workload decomposition.
//! \param [in,out] simulatiion_decomposer_invoker  The task invoker that does the simulation workload decomposition.
void setup_simulationdecomposition_invoker (const SimulationDecompositionParameters & work_load_parameters,
                                            std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                       SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulatiion_decomposer_invoker );

}; // namespace ANANSI

#endif // ANANSI_setup_simulationdecomposition_invoker_INC
