#ifndef ANANSI_processor_lattice_type_details_INC
#define ANANSI_processor_lattice_type_details_INC

//! \file processor_lattice_type_details.h

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

//! The header for error messages.

namespace ANANSI
{
namespace SDPConstructorHelpers
{

//! \brief Returns a boolean that indicates if the node value is valid.
bool IsProcessorTopologyLatticeTypeMandatory();

std::string MessageInvalidProcessorTopologyLatticeTypeValues(const std::string invalid_value);

};
}; // namespace ANANSI

#endif // ANANSI_processor_lattice_type_details_INC
