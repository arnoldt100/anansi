#ifndef ANANSI_verify_correct_size_for_world_communicator_INC
#define ANANSI_verify_correct_size_for_world_communicator_INC

//! \file verify_correct_size_for_world_communicator.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"
#include "error_message_lattice_topology_comm_size_mismatch.h"
#include "ErrorInvalidSimulationDecompositionParameters.h"

namespace ANANSI
{

namespace SimulationDecompositionTasksHelpers 
{
//! \brief Verifies the world communicator size equals the requested 
//!        lattice topology size.
//!
//! \details If the world communicator size doesn't equal the requested
//!          lattice topology size, then an error is thrown, otherwise 
//!          nothing is done.
template<typename Container_t>
void verify_correct_size_for_world_communicator (const Container_t & my_container,
                                                 std::size_t const & communicator_size)
{
    std::size_t product = 1;
    for ( auto it = my_container.begin(); it != my_container.end(); ++it)
    {
        product *= *it;
    }
    if ( product != communicator_size )
    {
        std::string error_message = 
            error_message_lattice_topology_comm_size_mismatch(my_container,communicator_size);
        throw ErrorInvalidSimulationDecompositionParameters(error_message);
    }
    return;
}

}; // ----- End of namespace SimulationDecompositionTasksHelpers
}; // ----- End of namespace ANANSI

#endif // ANANSI_verify_correct_size_for_world_communicator_INC
