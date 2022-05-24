/*
 * MasterSlaveIdentification.cpp
 */

#include "MasterSlaveIdentification_Specialization_1.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================


MasterSlaveIdentification<Communicator>::MasterSlaveIdentification(
    const Communicator & aCommunicator,
    const int master_mpi_rank) : Identification<Communicator>()
{

    if ( aCommunicator.sameCommunicatorRank(master_mpi_rank) )
    {
        this->_myIdentity=MASTER_SLAVE_IDENTITIES::master_mpi_task;
    }
    else
    {
        this->_myIdentity=MASTER_SLAVE_IDENTITIES::slave_mpi_task;
    }
    return;
}


MasterSlaveIdentification<Communicator>::MasterSlaveIdentification(MasterSlaveIdentification<Communicator> const & other) :
    Identification<Communicator>(),
    _myIdentity(other._myIdentity)
{
    if ( this != &other )
    {
        
    }
    return;
}

MasterSlaveIdentification<Communicator>::~MasterSlaveIdentification()
{
    return;
}

//============================= ACCESSORS ====================================

COMMUNICATOR::MASTER_SLAVE_IDENTITIES MasterSlaveIdentification<Communicator>::_getMyIdentity() const
{
    return this->_myIdentity;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MasterSlaveIdentification<Communicator>& MasterSlaveIdentification<Communicator>::operator=(MasterSlaveIdentification<Communicator> const & other)
{
    Identification<Communicator>::operator=(other);

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
