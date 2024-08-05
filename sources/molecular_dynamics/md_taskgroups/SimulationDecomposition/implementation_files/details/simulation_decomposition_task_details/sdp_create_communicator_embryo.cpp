//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "sdp_create_communicator_embryo.hpp"

namespace COMMUNICATOR
{

//! \brief Returns a CommunicatorEmbryo from a SimulationDecompositionParameters object.
template<>
CommunicatorEmbryo create_communicator_embryo ( const ANANSI::SimulationDecompositionParameters & sdp  )
{
    const std::array<std::size_t,3> my_communicator_spatial_dimensions = sdp.getProccesorTopology();
    const std::string my_type = sdp.getProccesorTopologyLattaiceType();
    COMMUNICATOR::CommunicatorEmbryo::communicator_types my_comm_type;
    if (my_type == std::string("rectangular"))
    {
        my_comm_type = COMMUNICATOR::CommunicatorEmbryo::communicator_types::rectangular; 
    }
    else
    {
        my_comm_type = COMMUNICATOR::CommunicatorEmbryo::communicator_types::rectangular; 
    }
    COMMUNICATOR::CommunicatorEmbryo embryo{my_comm_type,my_communicator_spatial_dimensions};
    return embryo;
}
}; // namespace COMMUNICATOR

