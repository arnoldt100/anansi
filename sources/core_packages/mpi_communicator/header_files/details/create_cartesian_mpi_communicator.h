#ifndef ANANSI_create_cartesian_mpi_communicator_INC
#define ANANSI_create_cartesian_mpi_communicator_INC

//! \file create_cartesian_mpi_communicator.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"
#include "MPICommunicator.h"

namespace ANANSI
{

//! \brief Returns a cartesian MPI communicator.
std::unique_ptr<MPICommunicator> create_cartesian_mpi_communicator ( std::unique_ptr<COMMUNICATOR::Communicator> const & communicator);


}; // namespace ANANSI

#endif // ANANSI_create_cartesian_mpi_communicator_INC
