//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "SimulationDecompositionParameters.h"
#include "GenericErrorClass.hpp"
#include "ErrorInvalidSimulationDecompositionParameters.h"
#include "ErrorMissingSimulationDecompositionParameters.h"

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ProccesorTopologyLatticeSpatialDimensionsHelpers.h"

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
        
    }
    catch (const std::exception & my_error)
    {
        
    }
    catch (const std::exception & my_error)
    {
        
    }



    return my_lattice_topology_spatial_dimensions;
} // -----  end of function ProccesorTopologyLatticeSpatialDimensionsHelpers  -----

}; // end of namespace SDPConstructorHelpers.
}; // namespace ANANSI

