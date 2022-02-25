/*
 * MPIGather.cpp
 *
 *  Created on: 04/20/19
 *      Authors: Arnold Tharrington
 */

#include "MPIGather.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

 char* MPI_GATHER<char>::Gather(
    const int task_id_to_gather_data,
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

    // Declare the recv buffer and only on the mpi task to gather the 
    // data do we allocate the recieve buffer.
    std::size_t recv_buffer_size = 0;
    char* my_recv_buffer_ptr = nullptr;
    if ( COMMUNICATOR::MPIUtilityFunctions::same_rank(task_id_to_gather_data,aCommunicator) )
    {
        recv_buffer_size = static_cast<std::size_t>(group_size*send_buffer_count);
        my_recv_buffer_ptr = my_char_array_factory.createArray(recv_buffer_size);
    }

    const int recv_buffer_count = send_buffer_count;
    mpi_return_code  = MPI_Gather(send_buffer_ptr, 
                                  send_buffer_count, 
                                  MPI_DATA_TYPE<char>::value(),
                                  my_recv_buffer_ptr,
                                  recv_buffer_count,
                                  MPI_DATA_TYPE<char>::value(),
                                  task_id_to_gather_data,
                                  aCommunicator);

    if (mpi_return_code != MPI_SUCCESS)
    {
        throw COMMUNICATOR::MPIGatherException();
    }

    return my_recv_buffer_ptr;
 }

std::vector<int> MPI_GATHER<int>::Gather(
    const int task_id_to_gather_data,
    const MPI_Comm aCommunicator,
    const int * send_buffer_ptr,
    const std::size_t send_buffer_count)
{
    MEMORY_MANAGEMENT::Array1d<int> my_array_factory;

    COMMUNICATOR::MasterSlaveIdentification<MPI_Comm> my_identity(aCommunicator,
                                                                  task_id_to_gather_data);

    // Get the size of the communicator group.
    int comm_group_size;
    int mpi_return_code = MPI_Comm_size(aCommunicator,&comm_group_size);
    if (mpi_return_code != MPI_SUCCESS)
    {
        throw COMMUNICATOR::MPICommSizeException();
    }

    // Declare the recv buffer and only on the mpi task to gather the 
    // data do we allocate the recieve buffer.
    std::size_t recv_buffer_size = 0;
    int* my_recv_buffer_ptr = nullptr;

    switch ( my_identity.getMyIdentity() )
    {
        case MASTER_SLAVE_IDENTITIES::master_mpi_task :
            recv_buffer_size = static_cast<std::size_t>(comm_group_size*send_buffer_count);
            my_recv_buffer_ptr = my_array_factory.createArray(recv_buffer_size);
            break;

        case MASTER_SLAVE_IDENTITIES::slave_mpi_task :
            // Do nothing
            break;
    };

    std::unique_ptr<int[]> my_recv_buffer(my_recv_buffer_ptr);
    const int recv_buffer_count = send_buffer_count;

    // We now call the MPi_Gather.
    mpi_return_code  = MPI_Gather(send_buffer_ptr, 
                                  send_buffer_count, 
                                  MPI_DATA_TYPE<int>::value(),
                                  my_recv_buffer.get(),
                                  recv_buffer_count,
                                  MPI_DATA_TYPE<int>::value(),
                                  task_id_to_gather_data,
                                  aCommunicator);

    if (mpi_return_code != MPI_SUCCESS)
    {
        throw COMMUNICATOR::MPIGatherException();
    }

    // Fill in the standard vector.
    std::vector<int> gathered_data;
    switch ( my_identity.getMyIdentity() )
    {
        case MASTER_SLAVE_IDENTITIES::master_mpi_task :
            gathered_data.resize(recv_buffer_size);
            for (std::size_t ip=0; ip < recv_buffer_size; ++ip)
            {
                gathered_data[ip] = my_recv_buffer[ip];
            }
            break;

        case MASTER_SLAVE_IDENTITIES::slave_mpi_task :
            // Do nothing
            break;
    };

    return gathered_data;
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
