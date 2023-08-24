//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

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
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
STRING_UTILITIES::VectorStringCache 
MPI_Broadcast<STRING_UTILITIES::VectorStringCache>::Broadcast(
    const STRING_UTILITIES::VectorStringCache data_to_broadcast,
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

    std::size_t buffer_array_lengths[2];
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
    mpi_error = MPI_Bcast(buffer_array_lengths,2,MPI_DATA_TYPE<unsigned long>::value(),
              static_cast<int>(bcast_rank),mpi_comm);
    if (mpi_error != MPI_SUCCESS)
    {
        std::string error_message("Error broadcasting VectorStringCache.");
        throw ANANSI::ErrorMPIBroadcast<STRING_UTILITIES::VectorStringCache>(error_message);
    }

    // ---------------------------------------------------
    // Broadcast the array of number characters per vector element.
    // ---------------------------------------------------
    MEMORY_MANAGEMENT::Array1d<std::size_t> SizeTArray1dFactory;
    std::size_t* buffer_ncpv = nullptr;
    if ( static_cast<std::size_t>(rank) == bcast_rank)
    {
        buffer_ncpv = SizeTArray1dFactory.createArray(buffer_array_lengths[0]);
    }
    else
    {
        buffer_ncpv = data_to_broadcast.getArrayOfNumberCharactersPerVector();
    }

    // ---------------------------------------------------
    // Broadcast the array of characters in VectorStringCache.
    // ---------------------------------------------------
    MEMORY_MANAGEMENT::Array1d<char> CharArray1dFactory;
    char* buffer_ca = nullptr;
    if ( static_cast<std::size_t>(rank) == bcast_rank)
    {
        buffer_ca = data_to_broadcast.getArrayOfCharacters();
    }
    else
    {
        buffer_ca = CharArray1dFactory.createArray(buffer_array_lengths[1]);
    }
    MPI_Bcast(buffer_ca,buffer_array_lengths[1],MPI_DATA_TYPE<char>::value(),
              static_cast<int>(bcast_rank),mpi_comm);


    // Destroy buffer arrays.
    SizeTArray1dFactory.destroyArray(buffer_ncpv);
    CharArray1dFactory.destroyArray(buffer_ca);

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
