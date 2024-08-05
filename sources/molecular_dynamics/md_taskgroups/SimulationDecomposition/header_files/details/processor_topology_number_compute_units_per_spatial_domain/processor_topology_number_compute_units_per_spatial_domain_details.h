#ifndef ANANSI_processor_topology_number_compute_units_per_spatial_domain_details_INC
#define ANANSI_processor_topology_number_compute_units_per_spatial_domain_details_INC

//! \file processor_topology_number_compute_units_per_spatial_domain_details.h

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

//! Returns a boolean indicating if the key for processor lattice type is mandatory.
std::string MessageInvalidProcessorTopologyNumberComputeUnitsPerSpatialDomain(const std::string invalid_value);

int ProcessorTopologyNumberComputeUnitsPerSpatialDomainValues(const std::string node_value);

};
}; // namespace ANANSI

#endif // ANANSI_processor_topology_number_compute_units_per_spatial_domain_details_INC
