/*
 * MPIReductionOperation.h
 *
 *  Created on: 12/15/18
 *      Authors: Arnold Tharrington
 */

#ifndef ANANSI_MPIREDUCTIONOPERATION_
#define ANANSI_MPIREDUCTIONOPERATION_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI {


class MPIReductionOperation 
{

    public:
        using reduction_operation_type = decltype(MPI_MAX);

        static reduction_operation_type maximum;
        static reduction_operation_type minimum;
        static reduction_operation_type sum;
        static reduction_operation_type product;
        static reduction_operation_type logical_and;
        static reduction_operation_type bitwise_and;
        static reduction_operation_type logical_or;
        static reduction_operation_type bitwise_or;
        static reduction_operation_type logical_xor;
        static reduction_operation_type bitwise_xor;
        static reduction_operation_type maximum_location;
        static reduction_operation_type minimum_location;
};

} /* namespace ANANSI */

#endif /* ANANSI_MPIREDUCTIONOPERATION_ */
