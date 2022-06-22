/*
 * MPIAllgather.h
 *
 *  Created on: 12/14/18
 *      Authors: Arnold Tharrington
 */

#ifndef ANANSI_MPIALLGATHER
#define ANANSI_MPIALLGATHER

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

template<>
class MPI_ALL_GATHER<char>
{
    public :
        static char* allGather(
                const MPI_Comm aCommunicator,
                std::size_t & nm_mpi_tasks,
                char const * send_buffer_ptr,
                const std::size_t send_buffer_length);

};

} /* namespace ANANSI */

#endif /* ANANSI_MPIALLGATHER */
