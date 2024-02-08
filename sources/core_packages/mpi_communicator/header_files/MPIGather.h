#ifndef ANANSI_MPIGATHER
#define ANANSI_MPIGATHER
//!file MPIGather.h
//!
//! Contains classes interface to various gathering type MPI calls
//!
//! char* MPI_GATHER<char>::Gather
//! std::vector<int> MPI_GATHER<int>::Gather

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "mpi.h"
#include <vector>
#include <memory>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIGatherException.h"
#include "MPIUtilityFunctions.h"
#include "MPIDataType.h"
#include "MPICommSizeException.h"
#include "Array1d.hpp"
#include "Array1dChar.hpp"
#include "MasterSlaveIdentification_Specialization_0.h"

namespace ANANSI {

template<typename T>
class MPI_GATHER;

//! Specialization to gather char array values on a group of processes.
template<>
class MPI_GATHER<char>
{
    public :
        //! Gathers char arrays values on a group of processes.
        //!
        //! The value of send_buffer_length must be the same on every processor in
        //! the communicator group or undefined results will occur. The gathered
        //! values returned only on processor with id 'task_id_to_gather_data'.
        //!
        //! @param [in] task_id_to_gather_data The id of the task to gather the data on.
        //! @param [in] aCommunicator The MPI communicator handle
        //! @param [out] nm_mpi_tasks The number of processes in the communicator group aCommunicator.
        //! @param [in] send_buffer_ptr A buffer of char.
        //! @param [in] send_buffer_length The length of send_buffer_ptr.
        //! @returns A char array containing the gathered char array buffers.
        static char *Gather(const int task_id_to_gather_data,
                            const MPI_Comm aCommunicator,
                            std::size_t &nm_mpi_tasks,
                            char const *send_buffer_ptr,
                            const std::size_t send_buffer_length);

};

//! Specialization to gather int values on a group of processes.
template<>
class MPI_GATHER<int>
{
    public :
        //! Gathers int values on a group of processes.
        //!
        //! The value of send_buffer_length must be the same on every processor in
        //! the communicator group or undefined results will occur. The gathered
        //! values returned only on processor with id 'task_id_to_gather_data'.
        //!
        //! @param [in] task_id_to_gather_data The id of the task to gather the data on.
        //! @param [in] aCommunicator The MPI communicator handle
        //! @param [in] send_buffer_ptr A buffer of int.
        //! @returns A vector containing the gathered int values.
        static std::vector<int> Gather(
                const int task_id_to_gather_data,
                const MPI_Comm aCommunicator,
                int const * send_buffer_ptr,
                const std::size_t send_buffer_length);
};

} /* namespace ANANSI */

#endif /* ANANSI_MPIGATHER */
