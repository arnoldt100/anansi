//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <tuple>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "WorkloadDecompositionTypeHelpers.h"
#include "SimulationDecompositionParameters.h"
#include "GenericErrorClass.hpp"
#include "ErrorInvalidSimulationDecompositionParameters.h"
#include "ErrorMissingSimulationDecompositionParameters.h"
#include "workload_decomposition_type_details.h"
#include "message_missing_mandatory_node_tag.h"

namespace ANANSI
{
namespace SDPConstructorHelpers
{

std::string workload_decomposition_type (const std::string a_string,
                                         const std::string flag_default_null_value)
{
    std::string my_workload_decomposition_type = "";
    try 
    {
        if ( (a_string == flag_default_null_value) && 
             IsWorkLoadDecompositionTypeMandatory() )
        {
            std::string error_message = message_missing_mandatory_node_tag("workload decomposition type");
            throw ErrorMissingSimulationDecompositionParameters(error_message);
        }
        else if (SimulationDecompositionParameters::IsValidWorkLoadDecompositionTypeValues(a_string))
        {
            my_workload_decomposition_type = SimulationDecompositionParameters::WorkLoadDecompositionTypeValues(a_string);
        }
        else
        {
            std::string error_message = MessageInvalidWorkloadDecompositionTypeValues(a_string);
            throw ErrorInvalidSimulationDecompositionParameters(error_message);
        }
    }
    catch (const ErrorMissingSimulationDecompositionParameters & my_error) 
    {
        const std::string error_message{my_error.what()};
        throw MOUSEION::GenericErrorClass<SimulationDecompositionParameters>(error_message); 
    }
    catch (const ErrorInvalidSimulationDecompositionParameters& my_error) 
    {
        const std::string error_message{my_error.what()};
        throw MOUSEION::GenericErrorClass<SimulationDecompositionParameters>(error_message); 
    }
    return my_workload_decomposition_type;

 
}  // -----  end of function workload_decomposition_type -----
}; // end of namespace SDPConstructorHelpers 
}; // end of namespace ANANSI

