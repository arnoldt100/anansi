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

    namespace 
    {
        //! The values for the workload decomposition types.
        static std::map<std::string,std::string> valid_work_load_decomposition_values{
            {std::string{"replicated-data-domain-decomposition"}, std::string{"internal_replicated-data-domain-decomposition"} },
            {std::string{"spatial-data-domain-decomposition"}, std::string{"internal_spatial-data-domain-decomposition"}}
        };
    }; // End of anonynous namespace

    std::string default_workload_decomposition_type()
    {
        return valid_work_load_decomposition_values.at("spatial-data-domain-decomposition"); 
    };

    bool is_valid_workload_decomposition_type_values(const std::string node_value)
    {
        return valid_work_load_decomposition_values.contains(node_value);
    }

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
    
     
    };  // -----  end of function workload_decomposition_type -----
}; // end of namespace SDPConstructorHelpers 
}; // end of namespace ANANSI

