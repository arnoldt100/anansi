#ifndef ANANSI_ProccesorTopologyLatticeSpatialDimensionsHelpers_INC
#define ANANSI_ProccesorTopologyLatticeSpatialDimensionsHelpers_INC

//! \file ProccesorTopologyLatticeSpatialDimensionsHelpers.h
//!
//! \details This file contains helper functions for initializing
//!          class SimulationDecompositionParameters data members in
//!          its constructor.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <array>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//


namespace ANANSI
{
namespace SDPConstructorHelpers{
//! Returns the processor topology lattice spatial dimensions.
//!
//! \details This parameter must be explicitly specified. If the parameter 'a_string'
//!          equals "flag_default_null_value" an exception will be thrown. Generally, a_string
//!          equals "flag_default_null_value" if the corresponding input file doesn't
//!          have the entry for the simulation lattice topology spatial dimensions.
//!
//! \param[in] a_string The string to be parsed for the lattice topology spatial dimensions.
//! \param[in] flag_default_null_value The flag to potentially use the default value.
//!
//! \throws MOUSEION::GenericErrorClass<SimulationDecompositionParameters> This
//!         exception is thrown if the parsing of 'a_string' for the
//!         lattice topology spatial dimensions fails.
std::array<int,3> parse_proccesor_topology_lattice_spatial_dimensions ( const std::string a_string,
                                                                        const std::string flag_default_null_value );

//! Returns the default value for the dimensions of the latttice topology of the spatial decomposition.
std::array<int,3> default_processor_topology_lattice_spatial_dimensions();

}; // end of names SDPConstructorHelpers
}; // namespace ANANSI

#endif // ANANSI_ProccesorTopologyLatticeSpatialDimensionsHelpers_INC
