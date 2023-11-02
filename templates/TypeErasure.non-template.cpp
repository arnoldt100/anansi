
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "__classname__.h"

namespace __NAMESPACE__ {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

__classname__::__classname__() :
    valuePtr_(nullptr)
{
    return;
}

__classname__::__classname__( __classname__ const & other)
{
    if (this != &other)
    {
        this->valuePtr_ = other.valuePtr_->clone();
    }
    return;
}

__classname__::__classname__( __classname__ && other)
{
    if (this != &other)
    {
        this->valuePtr_ = std::move(other.valuePtr_); 
    }
    return;
}		// -----  end of method __classname__::__classname__  -----


__classname__::~__classname__()
{
    return;
}

__classname__::__classname__Concept::~__classname__Concept()
{
    return;
}


//============================= ACCESSORS ====================================

__classname__ * __classname__::clone() const
{
    return new __classname__(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

__classname__& __classname__::operator= ( const __classname__ & other )
{
    if (this != &other)
    {
        this->valuePtr_  = other.valuePtr_->clone();
    }
    return *this;
} // assignment operator

__classname__& __classname__::operator= ( __classname__ && other )
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


}; // namespace __NAMESPACE__
