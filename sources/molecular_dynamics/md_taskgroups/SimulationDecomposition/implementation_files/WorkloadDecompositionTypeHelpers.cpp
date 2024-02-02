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
#include "ErrorInvalidSimulationWorkloadDecompositionType.h"
#include "ErrorMissingSimulationWorkloadDecompositionParameters.h"

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
             SimulationDecompositionParameters::WorkLoadDecompositionKeyIsMandatory()  )
        {
            std::string error_message = SimulationDecompositionParameters::ErrorMessageMissingMandatoryNodeTag("workload decomposition type");
            throw ErrorMissingSimulationWorkloadDecompositionParameters(error_message);
        }
        else if (SimulationDecompositionParameters::validWorkLoadDecompositionValues.contains(a_string))
        {
            my_workload_decomposition_type = SimulationDecompositionParameters::validWorkLoadDecompositionValues.at(a_string);
        }
        else
        {
            std::string error_message = SimulationDecompositionParameters::ErrorMessageInvalidWorkloadDecompositionNodeValue(a_string);
            throw ErrorInvalidSimulationWorkloadDecompositionType(error_message);
        }
    }
    catch (const ErrorMissingSimulationWorkloadDecompositionParameters & my_error) 
    {
        const std::string error_message{my_error.what()};
        throw MOUSEION::GenericErrorClass<SimulationDecompositionParameters>(error_message); 
    }
    catch (const ErrorInvalidSimulationWorkloadDecompositionType & my_error) 
    {
        const std::string error_message{my_error.what()};
        throw MOUSEION::GenericErrorClass<SimulationDecompositionParameters>(error_message); 
    }
    return my_workload_decomposition_type;

 
}  // -----  end of function workload_decomposition_type -----
}; // end of namespace SDPConstructorHelpers 
}; // end of namespace ANANSI

