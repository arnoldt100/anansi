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
    // First get the mpi communicator handle. We dynamic cast communicator to MPICommunicator.
    const MPICommunicator & cartesian_mpi_communicator = dynamic_cast<const MPICommunicator &>(*communicator);
    MPI_Comm my_handle = cartesian_mpi_communicator.getDuplicateCommHandle();

    std::string hostname = boost::asio::ip::host_name();

    std::unique_ptr<MPICommunicator> my_communicator;

    MPI_Comm_free(&my_handle);

    return my_communicator;
}   // -----  end of function create_cartesian_mpi_communicator  -----
// std::unique_ptr<MPICommunicator> create_cartesian_mpi_communicator ( std::unique_ptr<COMMUNICATOR::Communicator> const & communicator,
//                                                                      std::vector<std::size_t> const & comm_dimensions);


}; // namespace ANANSI

#endif // ANANSI_create_cartesian_mpi_communicator_INC
