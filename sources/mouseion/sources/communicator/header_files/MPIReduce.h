/*
 * MPIReduce.h
 *
 *  Created on: 12/14/18
 *      Authors: Arnold Tharrington
 */

#ifndef COMMUNICTOR_MPIREDUCTIONS_
#define COMMUNICTOR_MPIREDUCTIONS_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIDataType.h"
#include "MPIReductionOperation.h"
#include "MPIAllReduceException.h"
#include "Array1d.hpp"

namespace COMMUNICATOR {

template<typename T, typename R_O>
class MPI_ALLREDUCE
{
    public :
        static std::vector<T>
        REDUCE(MPI_Comm const & comm, 
               std::vector<T> & send_data,
               R_O & mpi_operation)
        {
            MEMORY_MANAGEMENT::Array1d<T> my_array_factory;

            // Here we define a convenient alias for vector size type.
            using vector_size_type = typename std::vector<T>::size_type;

        	// Get the the number of elements in the vector.
            auto count1 = static_cast<std::size_t>(send_data.size());
            auto count2 = static_cast<int>(send_data.size());

            // Simply copy the value of comm handle.
            MPI_Comm communicator = comm;

            // Create the recv and send buffers.
            T * send_data_ptr = my_array_factory.createPointerArrayFromVector(send_data); 
            T * recv_data_ptr = my_array_factory.createArray(count1);
            
            int mpi_errror_code = MPI_Allreduce(send_data_ptr,
                          recv_data_ptr,
                          count2,
                          COMMUNICATOR::MPI_DATA_TYPE<T>::value(),
                          mpi_operation,
                          communicator);

            if (mpi_errror_code != MPI_SUCCESS)
            {
                throw COMMUNICATOR::MPIAllReduceException();
            }

            // Copy the values from the recv_data buffer to the recv_data vector.
            const vector_size_type nm_elements = static_cast<vector_size_type>(count2);
            std::vector<T> recv_data(nm_elements);
            for (vector_size_type ip=0; ip < nm_elements; ++ip)
            {
                recv_data[ip] = recv_data_ptr[ip];
            }

            // Destroy all allocated memory.
            my_array_factory.destroyArray(send_data_ptr);
            my_array_factory.destroyArray(recv_data_ptr);

            return recv_data;
        }
};

} /* namespace COMMUNICATOR */

#endif /* COMMUNICTOR_MPIREDUCTIONS_ */
