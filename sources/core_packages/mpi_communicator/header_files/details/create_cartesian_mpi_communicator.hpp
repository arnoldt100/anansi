#ifndef ANANSI_create_cartesian_mpi_communicator_INC
#define ANANSI_create_cartesian_mpi_communicator_INC

//! \file create_cartesian_mpi_communicator.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include<vector>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/asio.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Array1d.hpp"
#include "free_mpi_communicator.h"
#include "Communicator.h"
#include "MPICommunicator.h"

namespace ANANSI
{

//! \brief Returns a cartesian MPI communicator.
template <std::size_t N>
std::unique_ptr<MPICommunicator> create_cartesian_mpi_communicator ( std::unique_ptr<COMMUNICATOR::Communicator> const & communicator,
                                                                     std::array<std::size_t,N> const & comm_dimensions)
{
    // First get a duplicate of the MPI communicator handle. 
    // We dynamic cast communicator to MPICommunicator and call method 
    // MPICommunicator.getDuplicateCommHandle;
    const MPICommunicator & cartesian_mpi_communicator = dynamic_cast<const MPICommunicator &>(*communicator);
    MPI_Comm comm = cartesian_mpi_communicator.getDuplicateCommHandle();

    // We declare the number of dimensions of Cartesian grid (integer), ndims.
    int ndims = static_cast<int>(N);

    // We declare the array specifying the number of
    // processes in each dimensions, dims.
    MEMORY_MANAGEMENT::Array1d<int> int_array_factory;
    const std::unique_ptr<int[]> my_comm_dims = int_array_factory.create1DUniquePointerFromIterator<std::array<std::size_t,N>,
                                                                                              int
                                                                                             >(comm_dimensions);

    // We set the rectangular grid to be periodic.
    const std::array<int,N> periods{static_cast<int>(true)};

    // We reoder the ranking of the cartesian communicator.
    bool reorder{true};

    MPI_Comm new_comm;
    int mpi_error = MPI_Cart_create(comm,
                    ndims, 
                    my_comm_dims.get(),
                    periods.data(),
                    reorder, 
                    &new_comm);

    std::string hostname = boost::asio::ip::host_name();

    std::unique_ptr<MPICommunicator> my_communicator;

    // Free all resources.
    MPI_Comm_free(&comm);

    return my_communicator;
}   // -----  end of function create_cartesian_mpi_communicator  -----
// std::unique_ptr<MPICommunicator> create_cartesian_mpi_communicator ( std::unique_ptr<COMMUNICATOR::Communicator> const & communicator,
//                                                                      std::vector<std::size_t> const & comm_dimensions);


}; // namespace ANANSI

#endif // ANANSI_create_cartesian_mpi_communicator_INC
