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
#include "MPIDataType.h"
#include "AssertValidValueForType.hpp"
#include "MPIGenericException.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

std::size_t MPI_Broadcast<std::size_t>::Broadcast(const std::size_t int_to_bcast, const MPI_Comm mpi_comm, const std::size_t bcast_rank) 
{
    // Create an int array with 1 element, and assign the 0th element the data
    // to be broadcasted.
    MEMORY_MANAGEMENT::Array1d<std::size_t> my_int_array_factory;
    std::size_t* array_ptr = my_int_array_factory.createArray(1);
    array_ptr[0] = int_to_bcast;

    // Broadcast the integer and assign broadcasted value to ret_value.
    #ifdef ANANSI_DBG_VALID_VALUES
    DEBUGGING::AssertValidValueForType<std::size_t,int>(bcast_rank);
    #endif // ANANSI_DBG_VALID_VALUES
    int mpi_error = MPI_Bcast(array_ptr, 1, MPI_DATA_TYPE<std::size_t>::value(), static_cast<int>(bcast_rank), mpi_comm);

    if (mpi_error != MPI_SUCCESS)
    {
        std::string message( "Broadcasting error of std::size_t ");
        throw ANANSI::ErrorMPIBroadcast<std::size_t>(message);
    }
    const std::size_t ret_value = array_ptr[0];

    // Delete the memory associated with the array.
    my_int_array_factory.destroyArray(array_ptr);

    return ret_value;
};

int MPI_Broadcast<int>::Broadcast(const int int_to_bcast, const MPI_Comm mpi_comm, const std::size_t bcast_rank) 
{

    // Create an int array with 1 element, and assign the 0th element the data
    // to be broadcasted.
    MEMORY_MANAGEMENT::Array1d<int> my_int_array_factory;
    int* array_ptr = my_int_array_factory.createArray(1);
    array_ptr[0] = int_to_bcast;

    // Broadcast the integer and assign broadcasted value to ret_value.
    #ifdef ANANSI_DBG_VALID_VALUES
    DEBUGGING::AssertValidValueForType<std::size_t,int>(bcast_rank);
    #endif // ANANSI_DBG_VALID_VALUES
    int mpi_error = MPI_Bcast(array_ptr, 1, MPI_INT, static_cast<int>(bcast_rank), mpi_comm);

    if (mpi_error != MPI_SUCCESS)
    {
        std::string message( "Broadcasting error of int ");
        throw ANANSI::ErrorMPIBroadcast<int>(message);
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
    #ifdef ANANSI_DBG_VALID_VALUES
    DEBUGGING::AssertValidValueForType<std::size_t,int>(bcast_rank);
    DEBUGGING::AssertValidValueForType<std::size_t,int>(char_array_len);
    #endif // ANANSI_DBG_VALID_VALUES
    int mpi_error = MPI_Bcast(char_array_ptr,
                              static_cast<int>(char_array_len),
                              MPI_CHAR,
                              static_cast<int>(bcast_rank),
                              mpi_comm);

    if (mpi_error != MPI_SUCCESS)
    {
        std::string message( "Broadcasting error of std::string");
        throw ANANSI::ErrorMPIBroadcast<std::string>(message);
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


} // namespace ANANSI
