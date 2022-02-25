//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cstring>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Array1dChar.hpp"
#include "Array1d.hpp"
#include "MPIBroadcast.h"
#include "ErrorMPIBroadcast.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

int MPI_Broadcast<int>::Broadcast(const int int_to_bcast, const MPI_Comm mpi_comm, const std::size_t bcast_rank) 
{

    // Create an int array with 1 element, and assign the 0th element the data
    // to be broadcasted.
    MEMORY_MANAGEMENT::Array1d<int> my_int_array_factory;
    int* array_ptr = my_int_array_factory.createArray(1);
    array_ptr[0] = int_to_bcast;

    // Broadcast the integer and assign broadcasted value to ret_value.
    int mpi_error = MPI_Bcast(array_ptr, 1, MPI_INT, static_cast<int>(bcast_rank), mpi_comm);

    if (mpi_error != MPI_SUCCESS)
    {
        std::string message( "Broadcasting error of int ");
        throw COMMUNICATOR::ErrorMPIBroadcast<int>(message);
    }
    const int ret_value = array_ptr[0];

    // Delete the memory associated with the array.
    my_int_array_factory.destroyArray(array_ptr);

    return ret_value;
}

std::string MPI_Broadcast<std::string>::Broadcast(const std::string str_to_bcast,
        const std::size_t bcast_str_len,
        const MPI_Comm mpi_comm,
        const std::size_t bcast_rank) 
{
    // Copy str_to_bcast to a char* variable char_array_ptr, and use
    // char_array_ptr to broadcast to all other MPI ranks. Don't forget to
    // account the the last '\0' char by adding 1 for the length of
    // char_array_ptr.
    MEMORY_MANAGEMENT::Array1d<char> my_char_array_factory;
    const std::size_t char_array_len = bcast_str_len+1;
    char * char_array_ptr = my_char_array_factory.createArray(str_to_bcast,char_array_len);

    // Broadcast char_array_ptr and assign broadcasted value to variable
    // ret_value.
    int mpi_error = MPI_Bcast(char_array_ptr,
                              static_cast<int>(char_array_len),
                              MPI_CHAR,
                              static_cast<int>(bcast_rank),
                              mpi_comm);

    if (mpi_error != MPI_SUCCESS)
    {
        std::string message( "Broadcasting error of std::string");
        throw COMMUNICATOR::ErrorMPIBroadcast<std::string>(message);
    }
    
    // Copy the broadcasted char_array_ptr to a string. Do not
    // copy the last '\0' char. 
    std::string ret_value(char_array_ptr,bcast_str_len); 

    // Free memory resources.
    my_char_array_factory.destroyArray(char_array_ptr);

    return ret_value;
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


} // namespace COMMUNICATOR
