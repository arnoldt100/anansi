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
#include "MPIAllgather.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//============================= STATIC    ====================================

 char* MPI_ALL_GATHER<char>::allGather(
    const MPI_Comm aCommunicator,
    std::size_t & nm_mpi_tasks,
    char const * send_buffer_ptr,
    const std::size_t send_buffer_count)
{
    MEMORY_MANAGEMENT::Array1d<char> my_char_array_factory;

    // Get the size of the communicator group.
    int comm_group_size;
    auto mpi_return_code = MPI_Comm_size(aCommunicator,&comm_group_size);
    if (mpi_return_code != MPI_SUCCESS)
    {
        throw ANANSI::MPICommSizeException();
    }
    nm_mpi_tasks = static_cast<std::size_t>(comm_group_size);


    // Declare the recv buffer 
    std::size_t recv_buffer_size = static_cast<std::size_t>(comm_group_size)*send_buffer_count;
    char* my_recv_buffer_ptr = my_char_array_factory.createArray(recv_buffer_size);

    // Ensure it safe to cast recv_buffer_count and send_buffer_count to int.
    #ifdef MOUSEION_DBG_VALID_VALUE
    DEBUGGING::AssertValidValueForType::isValidValueForCast<std::size_t,int>(send_buffer_count);
    #endif
    const auto send_buffer_count_as_int = static_cast<int>(send_buffer_count); 
    const auto recv_buffer_count = send_buffer_count_as_int;

    // Do the allgather operation. Every process in communicator group
    // make this call.
    mpi_return_code = MPI_Allgather(send_buffer_ptr,
                                    send_buffer_count_as_int,
                                    MPI_DATA_TYPE<char>::value(),
                                    my_recv_buffer_ptr,
                                    recv_buffer_count,
                                    MPI_DATA_TYPE<char>::value(),
                                    aCommunicator);

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


} /* namespace ANANSI */
