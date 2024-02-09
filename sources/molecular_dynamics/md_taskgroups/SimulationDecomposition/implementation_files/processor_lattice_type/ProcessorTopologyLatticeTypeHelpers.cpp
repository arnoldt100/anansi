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
#include "GenericErrorClass.hpp"
#include "ErrorInvalidSimulationDecompositionParameters.h"
#include "ErrorMissingSimulationDecompositionParameters.h"
#include "processor_lattice_type_details.h"
#include "message_missing_mandatory_node_tag.h"

namespace ANANSI
{
namespace SDPConstructorHelpers 
{
    namespace
    {
        std::map<std::string,std::string> valid_processor_topology_lattice_type_values{
            {std::string{"rectangular"}, std::string{"rectangular"}}
        };

    }; // End of anonynous namespace

    std::string default_processor_topology_lattice_type()
    {
        return valid_processor_topology_lattice_type_values.at("rectangular");
    }

    std::string parse_processor_topology_lattice_type(const std::string a_string,
                                                      const std::string flag_default_null_value)
    {
        std::string my_processor_topology_lattice_type = "";
        try
        {
            if ( (a_string == flag_default_null_value) && 
                 SDPConstructorHelpers::IsProcessorTopologyLatticeTypeMandatory()  )
            {
                std::string error_message = message_missing_mandatory_node_tag("processor topology lattice type");
                throw ErrorMissingSimulationDecompositionParameters(error_message);
            }
            else if (SimulationDecompositionParameters::IsValidProcessorTopologyLatticeTypeValues(a_string))
            {
                my_processor_topology_lattice_type = SimulationDecompositionParameters::ProcessorTopologyLatticeTypeValues(a_string);
            }
            else
            {
                std::string error_message = MessageInvalidProcessorTopologyLatticeTypeValues(a_string);
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
        return my_processor_topology_lattice_type; 
    }

}; // end of namespace SDPConstructorHelpers 
}; // end of namespace ANANSI

