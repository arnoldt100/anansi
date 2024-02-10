//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ProccesorTopologyLatticeSpatialDimensionsHelpers.h"
#include "SimulationDecompositionParameters.h"
#include "GenericErrorClass.hpp"
#include "ErrorInvalidSimulationDecompositionParameters.h"
#include "ErrorMissingSimulationDecompositionParameters.h"
#include "processor_lattice_spatial_dimensions_details.h"
#include "message_missing_mandatory_node_tag.h"
#include "count_words_in_string.h"
#include "verify_N_integers_in_string.hpp"
#include "convert_string_to_int_array.hpp"

namespace ANANSI
{
namespace SDPConstructorHelpers
{

    namespace
    {

        bool is_proccesor_topology_lattice_spatial_dimensions_mandatory()
        {
            return true;
        }

        bool is_valid_proccesor_topology_lattice_spatial_dimensions_values(const std::string node_value)
        {
            // We need to form an array of 3 positive integers. If the string can be parsed to form an 
            // array of 3 positive integers, then we return true, otherwise return false.
            bool valid_value = STRING_UTILITIES::verify_N_positive_integers_in_string<3>(node_value); 
            return valid_value;
        }

        std::array<int,3> proccesor_topology_lattice_spatial_dimensions_values(const std::string node_value)
        {
            std::array<int,3> my_value = STRING_UTILITIES::convert_string_to_int_array<3>(node_value);
            return my_value;
        };

    }; // End of anonynous namespoce.

   std::array<int,3> default_processor_topology_lattice_spatial_dimensions()
   {
       std::array<int,3> my_default_value{1,1,1};
       return my_default_value;
   }

    std::array<int,3> parse_proccesor_topology_lattice_spatial_dimensions(const std::string a_string,
                                                                          const std::string flag_default_null_value)
    {
        std::array<int,3> my_lattice_topology_spatial_dimensions{1,1,1};
        try
        {
           if ( (a_string == flag_default_null_value) && 
                 is_proccesor_topology_lattice_spatial_dimensions_mandatory() )
           {
                std::string error_message = 
                    message_missing_mandatory_node_tag("processor topology lattice spatial dimensions");
                throw ErrorMissingSimulationDecompositionParameters(error_message);
           }
           else if (is_valid_proccesor_topology_lattice_spatial_dimensions_values(a_string))
           {
                my_lattice_topology_spatial_dimensions = 
                    proccesor_topology_lattice_spatial_dimensions_values(a_string);;
           }
           else
           {
                std::string error_message = MessageInvalidProccesorTopologyLatticeSpatialDimensions(a_string);
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
        return my_lattice_topology_spatial_dimensions;
    } // -----  end of function ProccesorTopologyLatticeSpatialDimensionsHelpers  -----

}; // end of namespace SDPConstructorHelpers.
}; // namespace ANANSI

