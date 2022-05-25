/*
 * MasterSlaveIdentification.h
 */

#ifndef  MasterSlaveIdentification_Specialization_1_INC
#define  MasterSlaveIdentification_Specialization_1_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MasterSlaveIdentification.h"
#include "Identification.h"
#include "MPICommunicator.h"

namespace ANANSI {

template<>
class MasterSlaveIdentification<COMMUNICATOR::Communicator> : public Identification<COMMUNICATOR::Communicator> 
{
    public:
        //===== LIFECYCLE ======
        MasterSlaveIdentification(const COMMUNICATOR::Communicator & aCommunicator,
                                  const int master_mpi_rank);

        MasterSlaveIdentification(MasterSlaveIdentification<COMMUNICATOR::Communicator> const & other);

        ~MasterSlaveIdentification();

        //===== DATA MEMBERS ===

        //===== ACCESSORS ======

        //===== MUTATORS =======

        //===== OPERATORS ======
        MasterSlaveIdentification& operator=(MasterSlaveIdentification<COMMUNICATOR::Communicator> const & other);

        //===== STATIC METHODS =

    protected:
        //===== LIFECYCLE ======

        //===== DATA MEMBERS ===

        //===== ACCESSORS ======

        //===== MUTATORS =======

        //===== OPERATORS ======

    private:
        //===== LIFECYCLE ======

        //===== DATA MEMBERS ===
        MASTER_SLAVE_IDENTITIES _myIdentity;      

        //===== ACCESSORS ======
        ANANSI::MASTER_SLAVE_IDENTITIES _getMyIdentity() const override;

        //===== MUTATORS =======

        //===== OPERATORS ======

        //===== STATIC METHODS =
};



}; /* namespace ANANSI */

#endif   /* ----- #ifndef MasterSlaveIdentification_INC  ----- */

