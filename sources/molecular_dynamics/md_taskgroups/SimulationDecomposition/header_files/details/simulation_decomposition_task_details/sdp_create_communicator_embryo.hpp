#ifndef COMMUNICATOR_sdp_create_communicator_embryo_INC
#define COMMUNICATOR_sdp_create_communicator_embryo_INC

//! \file sdp_create_communicator_embryo.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommunicatorEmbryo.h"
#include "create_communicator_embryo.hpp"
#include "SimulationDecompositionParameters.h"

namespace COMMUNICATOR
{

//! \brief Returns a CommunicatorEmbryo from a SimulationDecompositionParameters object.
template<>
CommunicatorEmbryo create_communicator_embryo ( const ANANSI::SimulationDecompositionParameters & sdp  );

}; // namespace COMMUNICATOR

#endif // COMMUNICATOR_sdp_create_communicator_embryo_INC
