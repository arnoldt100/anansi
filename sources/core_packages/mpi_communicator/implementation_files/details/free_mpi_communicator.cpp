//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIFreeException.h"
#include "free_mpi_communicator.h"

namespace ANANSI
{

void free_mpi_communicator (MPI_Comm & mpi_comm_handle)
{
    try 
    {
        if ( mpi_comm_handle != MPI_COMM_NULL )
        {
            int mpi_return_code = MPI_Comm_free(&(mpi_comm_handle));
            
            if ( mpi_return_code != MPI_SUCCESS ) 
            {
                throw ANANSI::MPIFreeException();
            }
            mpi_comm_handle = MPI_COMM_NULL;
        }
    }
    catch (  ANANSI::MPIFreeException const & my_mpi_exception ) 
    {
        std::cout << "Freeing the communicator failed in function free_mpi_communicator." << std::endl;
        std::abort();
    }
    return;
}   // -----  end of function free_mpi_communicator  -----


}; // namespace ANANSI

