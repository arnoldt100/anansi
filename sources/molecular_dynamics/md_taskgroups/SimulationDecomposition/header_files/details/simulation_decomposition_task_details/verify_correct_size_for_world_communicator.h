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
void verify_correct_size_for_world_communicator ( );

}; // ----- End of namespace SimulationDecompositionTasksHelpers
}; // ----- End of namespace ANANSI

#endif // ANANSI_verify_correct_size_for_world_communicator_INC
