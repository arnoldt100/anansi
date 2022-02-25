/*
 * MPIReductionOperation.cpp
 *
 *  Created on: 12/15/18
 *      Authors: Arnold Tharrington
 */

#include "MPIReductionOperation.h"

namespace COMMUNICATOR 
{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

    MPIReductionOperation::reduction_operation_type MPIReductionOperation::maximum = MPI_MAX;
    MPIReductionOperation::reduction_operation_type MPIReductionOperation::minimum = MPI_MIN;
    MPIReductionOperation::reduction_operation_type MPIReductionOperation::sum = MPI_SUM;
    MPIReductionOperation::reduction_operation_type MPIReductionOperation::product = MPI_PROD;
    MPIReductionOperation::reduction_operation_type MPIReductionOperation::logical_and = MPI_LAND;
    MPIReductionOperation::reduction_operation_type MPIReductionOperation::bitwise_and = MPI_BAND;
    MPIReductionOperation::reduction_operation_type MPIReductionOperation::logical_or = MPI_LOR;
    MPIReductionOperation::reduction_operation_type MPIReductionOperation::bitwise_or = MPI_BOR;
    MPIReductionOperation::reduction_operation_type MPIReductionOperation::logical_xor = MPI_LXOR;
    MPIReductionOperation::reduction_operation_type MPIReductionOperation::bitwise_xor = MPI_BXOR;
    MPIReductionOperation::reduction_operation_type MPIReductionOperation::maximum_location = MPI_MAXLOC;
    MPIReductionOperation::reduction_operation_type MPIReductionOperation::minimum_location = MPI_MINLOC;


} /* namespace COMMUNICATOR */
