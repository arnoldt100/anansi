/*
 * MPIUtilityFunctions.cpp
 *
 *  Created on: 04/21/19
 *      Authors: Arnold Tharrington
 */

#include "MPIUtilityFunctions.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPIUtilityFunctions::MPIUtilityFunctions() 
{
	return;
}

MPIUtilityFunctions::~MPIUtilityFunctions() 
{
	return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//============================= STATIC METHODS ===============================
bool MPIUtilityFunctions::i_am_master(const std::size_t id)
{
    return ( id == COMMUNICATOR::MASTER_TASK_ID ? true : false );
};

bool MPIUtilityFunctions::i_am_master(const MPI_Comm & aCommunicator)
{
    const auto my_rank = MPIUtilityFunctions::myRank(aCommunicator);
    return MPIUtilityFunctions::i_am_master(my_rank);
};

std::size_t MPIUtilityFunctions::myRank(const MPI_Comm & aCommunicator)
{
    int my_rank = 0;
    try
    {
        int mpi_error_code = MPI_Comm_rank(aCommunicator,&my_rank);
        if ( mpi_error_code != MPI_SUCCESS )
        {
            throw MPIGenericException();
        }
    }
    catch(  MPIGenericException const & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }

    auto mpi_rank = static_cast<std::size_t>(my_rank);
    return mpi_rank;
}

bool MPIUtilityFunctions::same_rank(const std::size_t id1,
                                    const std::size_t id2)
{
    return ( id1==id2 ? true : false);
}

bool MPIUtilityFunctions::same_rank(const std::size_t id1,
                                    const MPI_Comm & aCommunicator)
{
    std::size_t my_rank = COMMUNICATOR::MPIUtilityFunctions::myRank(aCommunicator);
    return ( id1==my_rank ? true : false);
}


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//============================= STATIC METHODS ===============================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//============================= STATIC METHODS ===============================

} /* namespace COMMUNICATOR */
