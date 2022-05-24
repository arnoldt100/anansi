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

namespace COMMUNICATOR {

template<>
class MasterSlaveIdentification<Communicator> : public Identification<Communicator> 
{
    public:
        //===== LIFECYCLE ======
        MasterSlaveIdentification(const Communicator & aCommunicator,
                                  const int master_mpi_rank);

        MasterSlaveIdentification(MasterSlaveIdentification<Communicator> const & other);

        ~MasterSlaveIdentification();

        //===== DATA MEMBERS ===

        //===== ACCESSORS ======

        //===== MUTATORS =======

        //===== OPERATORS ======
        MasterSlaveIdentification& operator=(MasterSlaveIdentification<Communicator> const & other);

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
        COMMUNICATOR::MASTER_SLAVE_IDENTITIES _getMyIdentity() const override;

        //===== MUTATORS =======

        //===== OPERATORS ======

        //===== STATIC METHODS =
};



}; /* namespace COMMUNICATOR */

#endif   /* ----- #ifndef MasterSlaveIdentification_INC  ----- */

