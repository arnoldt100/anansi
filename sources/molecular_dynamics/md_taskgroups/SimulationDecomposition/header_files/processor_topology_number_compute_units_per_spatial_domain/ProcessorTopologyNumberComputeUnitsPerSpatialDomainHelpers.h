#ifndef ANANSI_ProcessorTopologyNumberComputeUnitsPerSoatialDomainHelpers_INC
#define ANANSI_ProcessorTopologyNumberComputeUnitsPerSpatialDomainHelpers_INC

//! \file ProcessorTopologyNumberComputeUnitsPerSpatialDomainHelpers.h

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


namespace ANANSI
{
namespace SDPConstructorHelpers
{

//! Returns the processor topology inumber of compute units per spatial domain
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
//!         number of compute unit per spatial domain fails.
int parse_processor_topology_number_processor_compute_units_per_spatial_domain(
    const std::string a_string,
    const std::string flag_default_null_value );

//! Returns the default number of compute units per spatial domain.
int default_processor_topology_number_compute_units_per_spatial_domain();

};
}; // namespace ANANSI

#endif // ANANSI_ProcessorTopologyNumberComputeUnitsPerSpatialDomainHelpers_INC
