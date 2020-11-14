/*
 * MPIDataType.h
 *
 *  Created on: 12/15/18
 *      Authors: Arnold Tharrington
 */

#ifndef COMMUNICATOR_MPIDATATYPE_
#define COMMUNICATOR_MPIDATATYPE_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR {

template< typename T>
class MPI_DATA_TYPE;

template<>
class MPI_DATA_TYPE<int>
{
    public:
        MPI_DATA_TYPE();

        ~MPI_DATA_TYPE();

        static MPI_Datatype value();
};

template<>
class MPI_DATA_TYPE<char>
{

    public:
        MPI_DATA_TYPE();

        ~MPI_DATA_TYPE();

        static MPI_Datatype value();
};

} /* namespace COMMUNICATOR */

#endif /* COMMUNICATOR_MPIDATATYPE_ */
