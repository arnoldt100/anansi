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

namespace ANANSI
{
namespace SDPConstructorHelpers
{

int parse_processor_topology_number_processor_compute_units_per_spatial_domain(
    const std::string a_string,
    const std::string flag_default_null_value )
{
    int number_cu_per_spatial_domain = 1;
    try 
    {
        if ( (a_string == flag_default_null_value) &&
              SimulationDecompositionParameters::IsProcesorTopologyNumberComputeUnitsPerSpatialDomainMandatory() )
        {
            std::string error_message = 
                SimulationDecompositionParameters::MessageMissingMandatoryNodeTag("processor topology number compute units per spatial domain");
            throw ErrorMissingSimulationDecompositionParameters(error_message);
        }
        else if ( SimulationDecompositionParameters::IsValidProcessorTopologyNumberComputeUnitsPerSpatialDomainValues(a_string) )
        {

        }
        else
        {

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
}

};
}; // namespace ANANSI

