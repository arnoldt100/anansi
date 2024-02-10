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

//! Returs an message for an invalid value for the workload decompostion type. 
std::string MessageInvalidWorkloadDecompositionTypeValues(const std::string invalid_value);

//! The values for the workload decomposition types.
static const std::map<std::string,std::string> valid_work_load_decomposition_values{
    {std::string{"replicated-data-domain-decomposition"}, std::string{"internal_replicated-data-domain-decomposition"} },
    {std::string{"spatial-data-domain-decomposition"}, std::string{"internal_spatial-data-domain-decomposition"}}
};

}; // end of namespace SDPConstructorHelpers
}; //end of  namespace ANANSI

#endif // ANANSI_workload_decomposition_type_details_INC
