
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "NodeKeys.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

NodeKeys::NodeKeys() :
    valuePtr_(nullptr)
{
    return;
}

NodeKeys::NodeKeys( NodeKeys const & other)
{
    if (this != &other)
    {
        this->valuePtr_ = other.valuePtr_->clone();
    }
    return;
}

NodeKeys::NodeKeys( NodeKeys && other)
{
    if (this != &other)
    {
        this->valuePtr_ = std::move(other.valuePtr_); 
    }
    return;
}		// -----  end of method NodeKeys::NodeKeys  -----


NodeKeys::~NodeKeys()
{
    return;
}

//============================= ACCESSORS ====================================

NodeKeys * NodeKeys::clone() const
{
    return new NodeKeys(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

NodeKeys& NodeKeys::operator= ( const NodeKeys &other )
{
    if (this != &other)
    {
        this->valuePtr_  = other.valuePtr_->clone();
    }
    return *this;
} // assignment operator

NodeKeys& NodeKeys::operator= ( NodeKeys && other )
{
    if (this != &other)
    {
        this->valuePtr_ = std::move(other.valuePtr_);
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


} // namespace ANANSI
