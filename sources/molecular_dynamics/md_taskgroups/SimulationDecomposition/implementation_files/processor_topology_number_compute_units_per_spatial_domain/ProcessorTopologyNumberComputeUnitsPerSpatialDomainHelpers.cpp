//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ProcessorTopologyNumberComputeUnitsPerSpatialDomainHelpers.h"
#include "SimulationDecompositionParameters.h"
#include "GenericErrorClass.hpp"
#include "ErrorInvalidSimulationDecompositionParameters.h"
#include "ErrorMissingSimulationDecompositionParameters.h"
#include "processor_topology_number_compute_units_per_spatial_domain_details.h"
#include "message_missing_mandatory_node_tag.h"
#include "verify_N_integers_in_string.hpp"

namespace ANANSI
{
namespace SDPConstructorHelpers
{


    namespace
    {
        //! \brief Returns a boolean indicating if the key for processor number
        //!        compute units per spatial domain is mandatory.
        static bool is_procesor_topology_number_compute_units_per_spatial_domain_mandatory()
        {
            return true;
        }

        bool is_valid_processor_topology_number_compute_units_per_spatial_domain_values(const std::string node_value)
        {
            bool valid_value = STRING_UTILITIES::verify_N_positive_integers_in_string<1>(node_value); 
            return valid_value;
        }

    }; // End of anonymous namespace.

    int default_processor_topology_number_compute_units_per_spatial_domain()
    {
        return 1;
    };

    int parse_processor_topology_number_processor_compute_units_per_spatial_domain(
        const std::string a_string,
        const std::string flag_default_null_value )
    {
        int number_cu_per_spatial_domain = 1;
        try 
        {
            if ( (a_string == flag_default_null_value) &&
                  is_procesor_topology_number_compute_units_per_spatial_domain_mandatory() )
            {
                std::string error_message = 
                    message_missing_mandatory_node_tag("processor topology number compute units per spatial domain");
                throw ErrorMissingSimulationDecompositionParameters(error_message);
            }
            else if ( is_valid_processor_topology_number_compute_units_per_spatial_domain_values(a_string) )
            {

                number_cu_per_spatial_domain = 
                    ProcessorTopologyNumberComputeUnitsPerSpatialDomainValues(a_string);
            }
            else
            {
                std::string error_message = SDPConstructorHelpers::MessageInvalidProcessorTopologyNumberComputeUnitsPerSpatialDomain(a_string);
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

        return number_cu_per_spatial_domain;
    };

};
}; // namespace ANANSI

