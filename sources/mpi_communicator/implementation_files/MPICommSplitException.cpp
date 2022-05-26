/*
 * MPICommSplitException.cpp
 *
 *  Created on: 10/24/18
 *      Authors: Arnold Tharrington
 */

#include "MPICommSplitException.h"

namespace ANANSI{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPICommSplitException::MPICommSplitException() {
    return;
}

MPICommSplitException::~MPICommSplitException() {
    return;
}

//============================= ACCESSORS ====================================
const char * MPICommSplitException::what() const noexcept
{
       return "The MPI Comm split call experienced an exception."; 
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
