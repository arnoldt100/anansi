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


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_MPIBroadcast_INC  -----
