#ifndef ANANSI_setup_macro_read_pointatoms_receiver_INC
#define ANANSI_setup_macro_read_pointatoms_receiver_INC

//! \file setup_macro_read_pointatoms_receiver.h

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
#include "GenericTaskInvoker.hpp"
#include "SimulationDecompositionTaskTraits.h"

namespace ANANSI
{

//! \brief Stud text for brief description
void setup_macro_read_pointatoms_receiver (std::shared_ptr<ANANSI::GenericTaskInvoker<SimulationDecompositionTaskTraits::abstract_products,
                                                                                      SimulationDecompositionTaskTraits::concrete_products>
                                               > & simulation_decomposer_invoker );


}; // namespace ANANSI

#endif // ANANSI_setup_macro_read_pointatoms_receiver_INC
