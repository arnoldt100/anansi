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
#include "ProcessorTopologyLatticeTypeHelpers.h"
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
        bool is_valid_processor_topology_lattice_type_values(const std::string node_value)
        {
            return valid_processor_topology_lattice_type_values.contains(node_value);
        }

        std::string processor_topology_lattice_type_values(const std::string node_value)
        {
            return valid_processor_topology_lattice_type_values.at(node_value);
        }

        bool is_processor_topology_lattice_type_mandatory() 
        {
            return true;
        }


    }; // End of anonynous namespace

    //! Returns the default value for the lattice type topology of the spatial decomposition.
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
                 is_processor_topology_lattice_type_mandatory()  )
            {
                std::string error_message = message_missing_mandatory_node_tag("processor topology lattice type");
                throw ErrorMissingSimulationDecompositionParameters(error_message);
            }
            else if (is_valid_processor_topology_lattice_type_values(a_string))
            {
                my_processor_topology_lattice_type = processor_topology_lattice_type_values(a_string);
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

