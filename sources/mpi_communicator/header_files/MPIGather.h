/*
 * MPIAllgather.h
 *
 *  Created on: 04/20/19
 *      Authors: Arnold Tharrington
 */

#ifndef COMMUNICATOR_MPIGATHER
#define COMMUNICATOR_MPIGATHER

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

namespace COMMUNICATOR {

template<typename T>
class MPI_GATHER;

template<>
class MPI_GATHER<char>
{
    public :
        static char* Gather(
                const int task_id_to_gather_data,
                const MPI_Comm aCommunicator,
                std::size_t & nm_mpi_tasks,
                char const * send_buffer_ptr,
                const std::size_t send_buffer_length);

};

template<>
class MPI_GATHER<int>
{
    public :
        static std::vector<int> Gather(
                const int task_id_to_gather_data,
                const MPI_Comm aCommunicator,
                int const * send_buffer_ptr,
                const std::size_t send_buffer_length);

};

} /* namespace COMMUNICATOR */

#endif /* COMMUNICATOR_MPIGATHER */
