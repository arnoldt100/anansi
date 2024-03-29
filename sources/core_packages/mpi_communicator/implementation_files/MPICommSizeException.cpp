/*
 * MPICommSizeException.cpp
 *
 *  Created on: 01/06/19
 *      Authors: Arnold Tharrington
 */

#include "MPICommSizeException.h"

namespace ANANSI{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPICommSizeException::MPICommSizeException() 
{
    return;
}

MPICommSizeException::~MPICommSizeException() 
{
    return;
}

//============================= ACCESSORS ====================================
const char * MPICommSizeException::what() const noexcept 
{
       return "The MPI experienced an exception in MPI_Comm_size."; 
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    

} /* namespace ANANSI*/
