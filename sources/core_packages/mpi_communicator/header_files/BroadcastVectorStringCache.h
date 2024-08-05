#ifndef ANANSI_BroadcastVectorStringCache_INC
#define ANANSI_BroadcastVectorStringCache_INC
//! \file BroadcastVectorStringCache.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIBroadcast.h"
#include "VectorStringCache.h"

namespace ANANSI
{

//! \brief Broadcasts the VectorStringCache object "data_to_broadcast" from the processor with rank "bcast_rank"
//!        to the remaining ranks in MPI communicator group "mpi_comm".
//!
//! \param[in] data_to_broadcast This object caches (or stores) a vector of strings and is broadcasted.
//! \param[in] mpi_comm The MPI communicator group involved in the broadcast.
//! \param[in] bcast_rank The MPI broadcast rank.
//! \return Returns an object of type VectorStringCache which is the broadcasted object "data_to_broadcast" from
//!         MPI rank "bcast_rank".
template<>
class MPI_Broadcast<STRING_UTILITIES::VectorStringCache>
{

public:
    static  STRING_UTILITIES::VectorStringCache Broadcast(const STRING_UTILITIES::VectorStringCache & data_to_broadcast,
                                                          const MPI_Comm mpi_comm,
                                                          const std::size_t bcast_rank);

}; // -----  end of class BroadcastVectorStringCache  -----

}; // namespace ANANSI

#endif // ANANSI_BroadcastVectorStringCache_INC
