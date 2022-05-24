/*
 * MasterSlaveIdentification_Specialization_0.cpp
 */

#include "MasterSlaveIdentification_Specialization_0.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================


MasterSlaveIdentification<MPI_Comm>::MasterSlaveIdentification(
    const MPI_Comm & aCommunicator,
    const int master_mpi_rank) : Identification<MPI_Comm>()
{
    if (COMMUNICATOR::MPIUtilityFunctions::same_rank(master_mpi_rank,aCommunicator) )
    {
        this->_myIdentity=MASTER_SLAVE_IDENTITIES::master_mpi_task;
    }
    else
    {
        this->_myIdentity=MASTER_SLAVE_IDENTITIES::slave_mpi_task;
    }
    return;
}


MasterSlaveIdentification<MPI_Comm>::MasterSlaveIdentification(MasterSlaveIdentification<MPI_Comm> const & other) :
    Identification<MPI_Comm>(),
    _myIdentity(other._myIdentity)
{
    if ( this != &other )
    {
        
    }
    return;
}

MasterSlaveIdentification<MPI_Comm>::~MasterSlaveIdentification()
{
    return;
}

//============================= ACCESSORS ====================================

COMMUNICATOR::MASTER_SLAVE_IDENTITIES MasterSlaveIdentification<MPI_Comm>::_getMyIdentity() const
{
    return this->_myIdentity;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MasterSlaveIdentification<MPI_Comm>& MasterSlaveIdentification<MPI_Comm>::operator=(MasterSlaveIdentification<MPI_Comm> const & other)
{
    Identification<MPI_Comm>::operator=(other);

    if ( this != &other )
    {
        this->_myIdentity = other._myIdentity;
    }
    return *this;
}

//============================= STATIC METHODS ===============================

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
