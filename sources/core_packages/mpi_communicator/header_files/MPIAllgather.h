#ifndef ANANSI_MPIALLGATHER
#define ANANSI_MPIALLGATHER
//!file MPIAllGather.h
//!
//! Contains classes interface to various all gathering type MPI calls
//!
//! char* MPI_ALL_GATHER<char>::allGather

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIDataType.h"
#include "MPICommSizeException.h"
#include "MPIAllGatherException.h"
#include "Array1dChar.hpp"

namespace ANANSI {

template<typename T>
class MPI_ALL_GATHER;

//! Specialization to all gather char array values on a group of processes.
template<>
class MPI_ALL_GATHER<char>
{
    public :
        //! All gathers char arrays values on a group of processes.
        //!
        //! The value of send_buffer_length must be the same on every processor in
        //! the communicator group or undefined results will occur. The gathered
        //! values returned to all processors in the group.
        //! @param [in] aCommunicator The MPI communicator handle
        //! @param [out] nm_mpi_tasks The number of processes in the communicator group aCommunicator.
        //! @param [in] send_buffer_ptr A buffer of char.
        //! @param [in] send_buffer_length The length of send_buffer_ptr.
        //! @returns A char array containing the gathered char array buffers.
        static char* allGather(
                const MPI_Comm aCommunicator,
                std::size_t & nm_mpi_tasks,
                char const * send_buffer_ptr,
                const std::size_t send_buffer_length);

};

} /* namespace ANANSI */

#endif /* ANANSI_MPIALLGATHER */
