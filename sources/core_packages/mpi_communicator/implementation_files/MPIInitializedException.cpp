/*
 * MPIIntializedException.cpp
 *
 *  Created on: 10/18/18
 *      Authors: Arnold Tharrington
 */

#include "MPIInitializedException.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPIInitializedException::MPIInitializedException()
{
    return;
}

MPIInitializedException::~MPIInitializedException()
{
    return;
}

//============================= ACCESSORS ====================================
const char * MPIInitializedException::what() const noexcept
{
    return "The MPI enviroment is already initialized."; 
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    

} /* namespace ANANSI */
