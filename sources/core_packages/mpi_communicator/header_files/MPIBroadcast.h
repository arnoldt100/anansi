//! \file MPI_Broadcast

#ifndef  ANANSI_MPIBroadcast_INC
#define  ANANSI_MPIBroadcast_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "VectorStringCache.h"

namespace ANANSI
{

template<typename T>
class MPI_Broadcast;

template<>
class MPI_Broadcast<int>
{
    public:

    static int Broadcast(const int data_to_broadcast,
                         const MPI_Comm mpi_comm, const std::size_t bcast_rank);


}; // -----  end of class MPI_BROADCAST  -----

template<>
class MPI_Broadcast<std::size_t>
{
    public:

    static std::size_t Broadcast(const std::size_t data_to_broadcast,
                                 const MPI_Comm mpi_comm, 
                                 const std::size_t bcast_rank);


}; // -----  end of class MPI_BROADCAST  -----

template<>
class MPI_Broadcast<std::string>
{
    public:
    static std::string Broadcast(const std::string data_to_broadcast,
                                 const std::size_t bcast_str_len,
                                 const MPI_Comm mpi_comm,
                                 const std::size_t bcast_rank);
};


//! \brief Broadcasts thes VectorStringCache object "data_to_broadcast" from the processor with rank "bcast_rank"
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
    static  STRING_UTILITIES::VectorStringCache Broadcast(const STRING_UTILITIES::VectorStringCache data_to_broadcast,
                                                          const MPI_Comm mpi_comm,
                                                          const std::size_t bcast_rank);
};

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_MPIBroadcast_INC  -----
