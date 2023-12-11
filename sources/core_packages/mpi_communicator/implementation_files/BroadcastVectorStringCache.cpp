//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <tuple>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Array1dChar.hpp"
#include "Array1d.hpp"
#include "ErrorMPIBroadcast.h"
#include "MPIDataType.h"
#include "MPIGenericException.h"
#include "BroadcastVectorStringCache.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// ANANONYMOUS NAMESPACE ////////////////////////
//////////////////////////////////////////////////////////////////////////////

namespace {
namespace details {

std::tuple<std::size_t,std::size_t> broadcast_array_lengths(const MPI_Comm & mpi_comm,
                                    const std::size_t & bcast_rank,
                                    const STRING_UTILITIES::VectorStringCache & data_to_broadcast)
{
    // ---------------------------------------------------
    // Broadcast the array lengths of the arrays in VectorStringCache.
    // ---------------------------------------------------
    int rank;
    int mpi_error = MPI_Comm_rank(mpi_comm, &rank);
    if (mpi_error != MPI_SUCCESS)
    {
        throw ANANSI::MPIGenericException();
    }

    std::unique_ptr<std::size_t[]> buffer_array_lengths = std::make_unique<std::size_t[]>(2);
    buffer_array_lengths[0] = data_to_broadcast.getNumberCharactersPerVectorArrayLength();
    buffer_array_lengths[1] = data_to_broadcast.getCharacterArrayLength() ;

    mpi_error = MPI_Bcast(buffer_array_lengths.get(),2,MPI_DATA_TYPE<unsigned long>::value(),
              static_cast<int>(bcast_rank),mpi_comm);
    if (mpi_error != MPI_SUCCESS)
    {
        std::string error_message("Error broadcasting VectorStringCache array lengths.");
        throw ANANSI::ErrorMPIBroadcast<STRING_UTILITIES::VectorStringCache>(error_message);
    }
    return std::make_tuple(buffer_array_lengths[0],buffer_array_lengths[1]);
}   // End of function STRING_UTILITIES::(unique)::details::broadcast_array_lengths

std::unique_ptr<std::size_t[]> broadcast_ncpv_array(const MPI_Comm & mpi_comm,
                                     const std::size_t & bcast_rank,
                                     const STRING_UTILITIES::VectorStringCache & data_to_broadcast,
                                     std::size_t const & ncpv_array_length )
{

    int rank;
    int mpi_error = MPI_Comm_rank(mpi_comm, &rank);
    if (mpi_error != MPI_SUCCESS)
    {
        throw ANANSI::MPIGenericException();
    }

    std::unique_ptr<std::size_t[]> buffer_ncpv = std::make_unique<std::size_t[]>(ncpv_array_length);
    if (bcast_rank == static_cast<std::size_t>(rank))
    {
        buffer_ncpv = data_to_broadcast.getArrayOfNumberCharactersPerVector();
    }
    else
    {
        for ( auto ip=static_cast<std::size_t>(0); ip < ncpv_array_length; ++ip )
        {
            buffer_ncpv[ip] = 0; 
        }
    }

    mpi_error = MPI_Bcast(buffer_ncpv.get(),static_cast<int>(ncpv_array_length),
                              MPI_DATA_TYPE<unsigned long>::value(),static_cast<int>(bcast_rank),
                              mpi_comm);
    if (mpi_error != MPI_SUCCESS)
    {
        std::string error_message("Error broadcasting VectorStringCache.");
        throw ANANSI::ErrorMPIBroadcast<STRING_UTILITIES::VectorStringCache>(error_message);
    }
    return buffer_ncpv;
}  // End of function STRING_UTILITIES::(unique)::details::broadcast_ncpv_array

std::unique_ptr<char[]> broadcast_ca_array(const MPI_Comm & mpi_comm,
                                     const std::size_t & bcast_rank,
                                     const STRING_UTILITIES::VectorStringCache & data_to_broadcast,
                                     std::size_t const & ca_array_length )
{
    int rank;
    int mpi_error = MPI_Comm_rank(mpi_comm, &rank);
    if (mpi_error != MPI_SUCCESS)
    {
        throw ANANSI::MPIGenericException();
    }

    std::unique_ptr<char[]> buffer_ca = std::make_unique<char[]>(ca_array_length);
    std::size_t number_of_chars;
    if ( static_cast<std::size_t>(rank) == bcast_rank)
    {
        std::tie(buffer_ca,number_of_chars) = data_to_broadcast.getArrayOfCharacters();
    }
    else
    {
        for ( auto ip=static_cast<std::size_t>(0); ip < ca_array_length; ++ip )
        {
            buffer_ca[ip] = 'z';
        }
        buffer_ca[ca_array_length] = '\0';
    }

    mpi_error = MPI_Bcast(buffer_ca.get(),static_cast<int>(ca_array_length),
                          MPI_DATA_TYPE<char>::value(),
                              static_cast<int>(bcast_rank),mpi_comm);
    if (mpi_error != MPI_SUCCESS)
    {
        std::string error_message("Error broadcasting VectorStringCache.");
        throw ANANSI::ErrorMPIBroadcast<STRING_UTILITIES::VectorStringCache>(error_message);
    }

    return buffer_ca;
} // End of function STRING_UTILITIES::(unique)::details::broadcast_ca_array

}; // End of unamed namespace STRING_UTILITIES::(unique)::details 
}; // End of unamed namespace STRING_UTILITIES::(unique)

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
STRING_UTILITIES::VectorStringCache 
MPI_Broadcast<STRING_UTILITIES::VectorStringCache>::Broadcast(
    const STRING_UTILITIES::VectorStringCache & data_to_broadcast,
    const MPI_Comm mpi_comm,
    const std::size_t bcast_rank)
{
    // ---------------------------------------------------
    // Broadcast the array lengths of the arrays in VectorStringCache.
    // ---------------------------------------------------
    std::size_t ncpv_array_length;
    std::size_t ca_array_length;
    std::tie(ncpv_array_length,ca_array_length) = 
        details::broadcast_array_lengths(mpi_comm,bcast_rank,data_to_broadcast);

    // ---------------------------------------------------
    // Broadcast the array of number characters per vector element.
    // ---------------------------------------------------
    std::unique_ptr<std::size_t[]> broadcasted_buffer_ncpv =
      details::broadcast_ncpv_array(mpi_comm,bcast_rank,data_to_broadcast,
                                    ncpv_array_length);

    // ---------------------------------------------------
    // Broadcast the array of characters in VectorStringCache.
    // ---------------------------------------------------
    std::unique_ptr<char[]> broadcasted_buffer_ca =
      details::broadcast_ca_array(mpi_comm,bcast_rank,data_to_broadcast,
                                  ca_array_length);

    // ---------------------------------------------------
    // Reform the VectorStringCache from the broadcasted data.
    // ---------------------------------------------------
    STRING_UTILITIES::VectorStringCache ret_value(ncpv_array_length,
                                                  std::move(broadcasted_buffer_ncpv),
                                                  ca_array_length,
                                                  std::move(broadcasted_buffer_ca));
    return ret_value;
}

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

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
