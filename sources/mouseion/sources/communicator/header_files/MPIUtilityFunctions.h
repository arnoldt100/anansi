/*
 * MPIUtilityFunctions.h
 *
 *  Created on: 04/21/19
 *      Authors: Arnold N. Tharrington
 */

#ifndef COMMUNICATOR_MPIUTILITYFUNCTIONS_H_
#define COMMUNICATOR_MPIUTILITYFUNCTIONS_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "MPICommunicator.h"
#include "MPIGenericException.h"
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR {

class MPIUtilityFunctions {

public:
    //===== LIFECYCLE ======
	MPIUtilityFunctions();

	~MPIUtilityFunctions();

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======

    //===== MUTATORS =======

    //===== OPERATORS ======

    //===== STATIC METHODS =
   static bool i_am_master(const std::size_t id);

   static bool i_am_master(const MPI_Comm & aCommunicator);

   static bool same_rank( const std::size_t id1,
                          const std::size_t id2);
   
   
   static bool same_rank( const std::size_t id1,
                          const MPI_Comm & aCommunicator);
   
   
   static std::size_t myRank(const MPI_Comm & aCommunicator);

protected:
    //===== LIFECYCLE ======

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======

    //===== MUTATORS =======

    //===== OPERATORS ======

    //===== STATIC METHODS =

private:
    //===== LIFECYCLE ======

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======

    //===== MUTATORS =======

    //===== OPERATORS ======
    
    //===== STATIC METHODS =


};

} /* namespace COMMUNICATOR */

#endif /* COMMUNICATOR_MPIUTILITYFUNCTIONS_H_ */
