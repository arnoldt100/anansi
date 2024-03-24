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
//!
//! 
template<typename iterator_t,
         typename comm_t> 
void verify_correct_size_for_world_communicator (iterator_t const & begin,
                                                 iterator_t const & end,
                                                 comm_t const & world_communicator)
{
    std::size_t product = 1;
    const auto comm_size = world_communicator->getSizeofCommunicator();
    for ( auto it = begin; it != end; ++it)
    {
      product *= *it;   
    }
    if ( product != comm_size )
    {
        // Throw error .....
    }

    return;
}

}; // ----- End of namespace SimulationDecompositionTasksHelpers
}; // ----- End of namespace ANANSI

#endif // ANANSI_verify_correct_size_for_world_communicator_INC
