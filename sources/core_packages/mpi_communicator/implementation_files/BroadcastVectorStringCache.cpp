//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

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
                                    const int & rank,
                                    const std::size_t & bcast_rank,
                                    const STRING_UTILITIES::VectorStringCache & data_to_broadcast)
{
    std::unique_ptr<std::size_t[]> buffer_array_lengths = std::make_unique<std::size_t[]>(2);
    if ( static_cast<std::size_t>(rank) == bcast_rank)
    {
        buffer_array_lengths[0] = data_to_broadcast.getNumberCharactersPerVectorArrayLength();
        buffer_array_lengths[1] = data_to_broadcast.getCharacterArrayLength() ;
    }
    else 
    {
        buffer_array_lengths[0] = 0;
        buffer_array_lengths[1] = 0;
    }

    int mpi_error = MPI_Bcast(buffer_array_lengths.get(),2,MPI_DATA_TYPE<unsigned long>::value(),
              static_cast<int>(bcast_rank),mpi_comm);
    if (mpi_error != MPI_SUCCESS)
    {
        std::string error_message("Error broadcasting VectorStringCache.");
        throw ANANSI::ErrorMPIBroadcast<STRING_UTILITIES::VectorStringCache>(error_message);
    }
    
    return std::make_tuple(buffer_array_lengths[0],buffer_array_lengths[1]);
}

std::unique_ptr<char[]> broadcast_ncpv_array(const MPI_Comm & mpi_comm,
                                     const int & rank,
                                     const std::size_t & bcast_rank,
                                     char * & ncpv_array_to_broadcast,
                                     std::size_t const & ncpv_array_length )
{

}


};
};

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
    int rank;
    int mpi_error = MPI_Comm_rank(mpi_comm, &rank);
    if (mpi_error != MPI_SUCCESS)
    {
        throw ANANSI::MPIGenericException();
    }
    std::size_t ncpv_array_length;
    std::size_t ca_array_length;

    std::unique_ptr<std::size_t[]> buffer_array_lengths = 
        details::broadcast_array_lengths(mpi_comm,rank,bcast_rank,data_to_broadcast);

    // ---------------------------------------------------
    // Broadcast the array of number characters per vector element.
    // ---------------------------------------------------
    MEMORY_MANAGEMENT::Array1d<std::size_t> SizeTArray1dFactory;
    std::unique_ptr<std::size_t[]> buffer_ncpv =
      details::broadcast_ncpv_array(mpi_comm,rank,bcast_rank,
                 buffer_array_lengths[0]);


    // // ---------------------------------------------------
    // // Broadcast the array of characters in VectorStringCache.
    // // ---------------------------------------------------

    // MEMORY_MANAGEMENT::Array1d<char> CharArray1dFactory;
    // char* buffer_ca = nullptr;
    // if ( static_cast<std::size_t>(rank) == bcast_rank)
    // {
    //     buffer_ca = data_to_broadcast.getArrayOfCharacters();
    // }
    // else
    // {
    //     buffer_ca = CharArray1dFactory.createArray(buffer_array_lengths[1]);
    // }
    // MPI_Bcast(buffer_ca,buffer_array_lengths[1],MPI_DATA_TYPE<char>::value(),
    //           static_cast<int>(bcast_rank),mpi_comm);

    // // ---------------------------------------------------
    // // Reform the VectorStringCache from the broadcasted data.
    // // ---------------------------------------------------

    // // Destroy buffer arrays.
    // SizeTArray1dFactory.destroyArray(buffer_ncpv);
    // CharArray1dFactory.destroyArray(buffer_ca);

    return data_to_broadcast;
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
