#ifndef ANANSI_workload_decomposition_type_details_INC
#define ANANSI_workload_decomposition_type_details_INC

//! \file workload_decomposition_type_details.h

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

//! Returns a boolean indicating if the key for workload decompostion is mandatory.
bool IsWorkLoadDecompositionTypeMandatory();

//! The header for error messages.
constexpr char* ErrorMessageHeader = R"""(
# ----------------------
# Error Message
# ----------------------)""";

//! The ifooter for error messages.
constexpr char* ErrorMessageFooter = R"""(# ----------------------)""";

//! Returs an message for an invalid value for the workload decompostion type. 
std::string MessageInvalidWorkloadDecompositionTypeValues(const std::string invalid_value);

}; // end of namespace SDPConstructorHelpers
}; //end of  namespace ANANSI

#endif // ANANSI_workload_decomposition_type_details_INC
