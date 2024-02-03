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

namespace ANANSI
{
namespace SDPConstructorHelpers
{

std::array<int,3> parse_proccesor_topology_lattice_spatial_dimensions(const std::string a_string,
                                                  const std::string flag_default_null_value)
{
    std::array<int,3> lattice_topology_spatial_dimensions{1,1,1};
    return lattice_topology_spatial_dimensions;
} // -----  end of function ProccesorTopologyLatticeSpatialDimensionsHelpers  -----

}; // end of namespace SDPConstructorHelpers.
}; // namespace ANANSI

