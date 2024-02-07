#ifndef ANANSI_ProcessorTopology_LatticeTypeHelpers_INC
#define ANANSI_ProcessorTopology_LatticeTypeHelpers_INC

//! \file SDPConstructorHelpers.h
//!
//! \detailed This file contains helper functions for initializing
//!           class SimulationDecompositionParameters data members in
//!           its constructor.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationDecompositionParameters.h"

namespace ANANSI
{
namespace SDPConstructorHelpers
{

//! Returns the processor lattice type.
//!
//! \details This parameter must be explicitly specified. If the parameter 'a_string'
//!          equals "flag_default_null_value" an exception will be thrown. Generally, a_string
//!          equals "flag_default_null_value" if the corresponding input file doesn't
//!          have the entry for the simulation workload decomposition type.
//!
//! \param[in] a_string The string to be parsed for the workload decomposition type.
//! \param[in] flag_default_null_value The flag to potentially use the default value.
//!
//! \throws MOUSEION::GenericErrorClass<SimulationDecompositionParameters> This
//!         exception is thrown if the parsing of 'a_string' for the
//!         workload decomposition type fails.
std::string parse_processor_topology_lattice_type(const std::string a_string,
                                                  const std::string flag_default_null_value);


}; // end of namespace SDPConstructorHelpers 
}; // end of namespace ANANSI

#endif // ANANSI_ProcessorTopology_LatticeTypeHelpers_INC
