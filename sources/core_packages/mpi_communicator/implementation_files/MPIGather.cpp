//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AssertValidValueForType.hpp"
#include "MPIGather.h"

namespace ANANSI {

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

    ANANSI::MasterSlaveIdentification<MPI_Comm> my_identity(aCommunicator,
                                                            task_id_to_gather_data);

    // Get the size of the communicator group.
    int comm_group_size;
    auto mpi_return_code = MPI_Comm_size(aCommunicator,&comm_group_size);
    if (mpi_return_code != MPI_SUCCESS)
    {
        throw ANANSI::MPICommSizeException();
    }
    nm_mpi_tasks = static_cast<std::size_t>(comm_group_size);

    // Declare the recv buffer and only on the mpi task to gather the
    // data do we allocate the recieve buffer.
    std::size_t recv_buffer_size = 0;
    char* my_recv_buffer_ptr = nullptr;

    // Ensure it safe to cast recv_buffer_count and send_buffer_count to int.
    #ifdef MOUSEION_DBG_VALID_VALUE
    DEBUGGING::AssertValidValueForType::isValidValueForCast<std::size_t,int>(send_buffer_count);
    #endif
    const auto send_buffer_count_as_int = static_cast<int>(send_buffer_count); 
    const auto recv_buffer_count = send_buffer_count_as_int;
    switch ( my_identity.getMyIdentity() )
    {
        case MASTER_SLAVE_IDENTITIES::master_mpi_task :
            recv_buffer_size = static_cast<std::size_t>(comm_group_size)*send_buffer_count;
            my_recv_buffer_ptr = my_char_array_factory.createArray(recv_buffer_size);
            break;

        case MASTER_SLAVE_IDENTITIES::slave_mpi_task :
            // Do nothing
            break;

    };

    mpi_return_code  = MPI_Gather(send_buffer_ptr, 
                                  send_buffer_count_as_int, 
                                  MPI_DATA_TYPE<char>::value(),
                                  my_recv_buffer_ptr,
                                  recv_buffer_count,
                                  MPI_DATA_TYPE<char>::value(),
                                  task_id_to_gather_data,
                                  aCommunicator);

    if (mpi_return_code != MPI_SUCCESS)
    {
        throw ANANSI::MPIGatherException();
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

    ANANSI::MasterSlaveIdentification<MPI_Comm> my_identity(aCommunicator,
                                                            task_id_to_gather_data);

    // Get the size of the communicator group.
    int comm_group_size;
    auto mpi_return_code = MPI_Comm_size(aCommunicator,&comm_group_size);
    if (mpi_return_code != MPI_SUCCESS)
    {
        throw ANANSI::MPICommSizeException();
    }

    // Declare the recv buffer and only on the mpi task to gather the 
    // data do we allocate the recieve buffer.
    std::size_t recv_buffer_size = 0;
    int* my_recv_buffer_ptr = nullptr;

    // Ensure it is safe to cast recv_buffer_count and send_buffer_count to int.
    #ifdef MOUSEION_DBG_VALID_VALUE
    DEBUGGING::AssertValidValueForType::isValidValueForCast<std::size_t,int>(send_buffer_count);
    #endif
    const auto send_buffer_count_as_int = static_cast<int>(send_buffer_count); 
    const auto recv_buffer_count = send_buffer_count_as_int;
    switch ( my_identity.getMyIdentity() )
    {
        case MASTER_SLAVE_IDENTITIES::master_mpi_task :
            recv_buffer_size = static_cast<std::size_t>(comm_group_size)*send_buffer_count;
            my_recv_buffer_ptr = my_array_factory.createArray(recv_buffer_size);
            break;

        case MASTER_SLAVE_IDENTITIES::slave_mpi_task :
            // Do nothing
            break;
    };


    // We now call the MPi_Gather.
    std::unique_ptr<int[]> my_recv_buffer(my_recv_buffer_ptr);
    mpi_return_code  = MPI_Gather(send_buffer_ptr, 
                                  send_buffer_count_as_int, 
                                  MPI_DATA_TYPE<int>::value(),
                                  my_recv_buffer.get(),
                                  recv_buffer_count,
                                  MPI_DATA_TYPE<int>::value(),
                                  task_id_to_gather_data,
                                  aCommunicator);

    if (mpi_return_code != MPI_SUCCESS)
    {
        throw ANANSI::MPIGatherException();
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


} /* namespace ANANSI */
