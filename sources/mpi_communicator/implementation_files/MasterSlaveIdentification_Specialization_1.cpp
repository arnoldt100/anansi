/*
 * MasterSlaveIdentification.cpp
 */

#include "MasterSlaveIdentification_Specialization_1.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================


MasterSlaveIdentification<COMMUNICATOR::Communicator>::MasterSlaveIdentification(
    const COMMUNICATOR::Communicator & aCommunicator,
    const int master_mpi_rank) : Identification<COMMUNICATOR::Communicator>()
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


MasterSlaveIdentification<COMMUNICATOR::Communicator>::MasterSlaveIdentification(MasterSlaveIdentification<COMMUNICATOR::Communicator> const & other) :
    Identification<COMMUNICATOR::Communicator>(),
    _myIdentity(other._myIdentity)
{
    if ( this != &other )
    {
        
    }
    return;
}

MasterSlaveIdentification<COMMUNICATOR::Communicator>::~MasterSlaveIdentification()
{
    return;
}

//============================= ACCESSORS ====================================

ANANSI::MASTER_SLAVE_IDENTITIES MasterSlaveIdentification<COMMUNICATOR::Communicator>::_getMyIdentity() const
{
    return this->_myIdentity;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MasterSlaveIdentification<COMMUNICATOR::Communicator>& MasterSlaveIdentification<COMMUNICATOR::Communicator>::operator=(MasterSlaveIdentification<COMMUNICATOR::Communicator> const & other)
{
    Identification<COMMUNICATOR::Communicator>::operator=(other);

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

} /* namespace ANANSI */
