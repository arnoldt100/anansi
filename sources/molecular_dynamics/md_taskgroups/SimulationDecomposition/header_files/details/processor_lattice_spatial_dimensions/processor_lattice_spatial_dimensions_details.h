#ifndef ANANSI_processor_lattice_spatial_dimensions_details_INC
#define ANANSI_processor_lattice_spatial_dimensions_details_INC

//! \file processor_lattice_spatial_dimensions_details.h

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
std::string MessageInvalidProccesorTopologyLatticeSpatialDimensions(const std::string invalid_value);


}; // End of namespace SDPConstructorHelpers
}; // namespace ANANSI

#endif // ANANSI_processor_lattice_spatial_dimensions_details_INC