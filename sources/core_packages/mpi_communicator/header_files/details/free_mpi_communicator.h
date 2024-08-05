#ifndef ANANSI_free_mpi_communicator_INC
#define ANANSI_free_mpi_communicator_INC

//! \file free_mpi_communicator.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "mpi.h"

//---------------------------------------------------L-----//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//


namespace ANANSI
{

//! \brief Frees a MPI communicator.
//! 
//! \param [in,out] mpi_comm_handle The communicator handle to be freed. 
void free_mpi_communicator (MPI_Comm & mpi_comm_handle);


}; // namespace ANANSI

#endif // ANANSI_free_mpi_communicator_INC
