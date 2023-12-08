
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIBarrier.h"
#include "MPIBarrierException.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

void MPIBarrier::Barrier(const MPI_Comm mpi_comm)
{
    auto mpi_return_code = MPI_Barrier(mpi_comm);
    if (mpi_return_code != MPI_SUCCESS)
    {
        throw MPIBarrierException();
    }
    return;
}

} // namespace ANANSI