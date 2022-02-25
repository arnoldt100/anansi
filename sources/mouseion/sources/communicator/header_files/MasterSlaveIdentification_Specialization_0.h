/*
 * MasterSlaveIdentification.h
 */

#ifndef  MasterSlaveIdentification_Specialization_0_INC
#define  MasterSlaveIdentification_Specialization_0_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MasterSlaveIdentification.h"
#include "MPIUtilityFunctions.h"
#include "Identification.h"

namespace COMMUNICATOR {

template<>
class MasterSlaveIdentification<MPI_Comm> : public Identification<MPI_Comm> 
{
    public:
        //===== LIFECYCLE ======
        MasterSlaveIdentification(const MPI_Comm & aCommunicator,
                                  const int master_mpi_rank);

        MasterSlaveIdentification(MasterSlaveIdentification<MPI_Comm> const & other);

        ~MasterSlaveIdentification();

        //===== DATA MEMBERS ===

        //===== ACCESSORS ======

        //===== MUTATORS =======

        //===== OPERATORS ======
        MasterSlaveIdentification& operator=(MasterSlaveIdentification<MPI_Comm> const & other);

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

