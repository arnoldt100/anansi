#ifndef ANANSI_MPIBarrier_INC
#define ANANSI_MPIBarrier_INC
//! \file MPIBarrier.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{
class MPIBarrier
{
    public:
        // ====================  LIFECYCLE     =======================================
    static void Barrier(const MPI_Comm aCommunicator);

}; // -----  end of class MPIBarrier  -----


}; // namespace ANANSI

#endif // ANANSI_MPIBarrier_INC
