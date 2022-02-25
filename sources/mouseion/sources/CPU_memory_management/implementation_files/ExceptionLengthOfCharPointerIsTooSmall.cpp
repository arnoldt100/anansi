/*
 * =====================================================================================
 *
 *       Filename:  ExceptionLengthOfCharPointerIsTooSmall.cpp
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#include "ExceptionLengthOfCharPointerIsTooSmall.h"

namespace MEMORY_MANAGEMENT
{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ExceptionLengthOfCharPointerIsTooSmall::ExceptionLengthOfCharPointerIsTooSmall(std::string const message) :
    _message(message)
{
    return;
}

ExceptionLengthOfCharPointerIsTooSmall::ExceptionLengthOfCharPointerIsTooSmall(
    ExceptionLengthOfCharPointerIsTooSmall const & other) : _message(other._message)
{
    if (this != &other)
    {
        
    }
    return;
}

ExceptionLengthOfCharPointerIsTooSmall::~ExceptionLengthOfCharPointerIsTooSmall()
{
    return;
}

//============================= ACCESSORS ====================================
const char * ExceptionLengthOfCharPointerIsTooSmall::what() const noexcept 
{
    return _message.c_str();
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace MEMORY_MANAGEMENT */
