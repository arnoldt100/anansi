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

namespace ANANSI
{
namespace SDPConstructorHelpers
{

std::array<int,3> parse_proccesor_topology_lattice_spatial_dimensions(const std::string a_string,
                                                                      const std::string flag_default_null_value)
{
    std::array<int,3> my_lattice_topology_spatial_dimensions{1,1,1};
    try
    {
       if ( (a_string == flag_default_null_value) && 
             SimulationDecompositionParameters::IsProccesorTopologyLatticeSpatialDimensionsMandatory() )
       {
            std::string error_message = 
                message_missing_mandatory_node_tag("processor topology lattice spatial dimensions");
            throw ErrorMissingSimulationDecompositionParameters(error_message);
       }
       else if (SimulationDecompositionParameters::IsValidProccesorTopologyLatticeSpatialDimensionsValues(a_string))
       {
            my_lattice_topology_spatial_dimensions = 
                SimulationDecompositionParameters::ProccesorTopologyLatticeSpatialDimensionsValues(a_string);;
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

