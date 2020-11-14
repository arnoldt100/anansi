/*
 * MPIAllgather.cpp
 *
 *  Created on: 01/06/19
 *      Authors: Arnold Tharrington
 */

#include "MPIAllgather.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

 char* MPI_ALL_GATHER<char>::allGather(
    const MPI_Comm aCommunicator,
    std::size_t & nm_mpi_tasks,
    char const * send_buffer_ptr,
    const std::size_t send_buffer_count)
{
    MEMORY_MANAGEMENT::Array1d<char> my_char_array_factory;

    // Get the size of the communicator group.
    int group_size;
    int mpi_return_code = MPI_Comm_size(aCommunicator,&group_size);
    if (mpi_return_code != MPI_SUCCESS)
    {
        throw COMMUNICATOR::MPICommSizeException();
    }
    nm_mpi_tasks = static_cast<std::size_t>(group_size);


    // Declare the recv buffer 
    std::size_t recv_buffer_size = static_cast<std::size_t>(group_size*send_buffer_count);
    char* my_recv_buffer_ptr = my_char_array_factory.createArray(recv_buffer_size);

    // Do the allgather operation.
    int my_recv_buffer_count = static_cast<std::size_t>(send_buffer_count);
    int my_send_buffer_count = static_cast<std::size_t>(send_buffer_count);
    MPI_Comm my_communicator = aCommunicator;
    mpi_return_code = MPI_Allgather(send_buffer_ptr,
                                    my_send_buffer_count,
                                    MPI_DATA_TYPE<char>::value(),
                                    my_recv_buffer_ptr,
                                    my_recv_buffer_count,
                                    MPI_DATA_TYPE<char>::value(),
                                    my_communicator);

    if (mpi_return_code != MPI_SUCCESS)
    {
        throw MPIAllGatherException();
    }

    return &(my_recv_buffer_ptr[0]);
 }
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace COMMUNICATOR */
