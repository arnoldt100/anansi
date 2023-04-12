/*
 * MPIDataType.h
 *
 *  Created on: 12/15/18
 *      Authors: Arnold Tharrington
 */

#ifndef ANANSI_MPIDATATYPE_
#define ANANSI_MPIDATATYPE_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cstddef>
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI {

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

template<>
class MPI_DATA_TYPE<unsigned long>
{

    public:
        MPI_DATA_TYPE();

        ~MPI_DATA_TYPE();

        static MPI_Datatype value();
};

template<>
class MPI_DATA_TYPE<bool>
{

    public:
        MPI_DATA_TYPE();

        ~MPI_DATA_TYPE();

        static MPI_Datatype value();
};


} /* namespace ANANSI */

#endif /* ANANSI_MPIDATATYPE_ */
