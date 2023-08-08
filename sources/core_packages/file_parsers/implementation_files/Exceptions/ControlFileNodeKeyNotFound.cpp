//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFileNodeKeyNotFound.h"

namespace ANANSI
{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileNodeKeyNotFound::ControlFileNodeKeyNotFound()
{
    return;
}

ControlFileNodeKeyNotFound::ControlFileNodeKeyNotFound( const std::string error_message)
{
    this->errorMessage_ = error_message;
    return;
}

ControlFileNodeKeyNotFound::ControlFileNodeKeyNotFound( ControlFileNodeKeyNotFound const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileNodeKeyNotFound::ControlFileNodeKeyNotFound( ControlFileNodeKeyNotFound && other)
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method ControlFileNodeKeyNotFound::ControlFileNodeKeyNotFound  -----


ControlFileNodeKeyNotFound::~ControlFileNodeKeyNotFound()
{
    return;
}

//============================= ACCESSORS ====================================
const char* ControlFileNodeKeyNotFound::what()
{
    return this->errorMessage_.c_str();
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileNodeKeyNotFound& ControlFileNodeKeyNotFound::operator= ( const ControlFileNodeKeyNotFound &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

ControlFileNodeKeyNotFound& ControlFileNodeKeyNotFound::operator= ( ControlFileNodeKeyNotFound && other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment-move operator

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


}; // namespace ANANSI

