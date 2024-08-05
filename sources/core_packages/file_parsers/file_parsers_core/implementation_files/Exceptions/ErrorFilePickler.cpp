
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorFilePickler.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorFilePickler::ErrorFilePickler() : 
    MOUSEION::BaseException{},
    errorMessage_{}
{
    return;
}

ErrorFilePickler::ErrorFilePickler( ErrorFilePickler const & other) :
    MOUSEION::BaseException{other},
    errorMessage_{other.errorMessage_}
{
    if (this != &other)
    {
        
    }
    return;
}

ErrorFilePickler::ErrorFilePickler( ErrorFilePickler && other) :
    MOUSEION::BaseException{std::move(other)},
    errorMessage_{std::move(other.errorMessage_)}
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ErrorFilePickler::ErrorFilePickler  -----


ErrorFilePickler::~ErrorFilePickler()
{
    return;
}

//============================= ACCESSORS ====================================

ErrorFilePickler * ErrorFilePickler::clone() const
{
    return new ErrorFilePickler(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorFilePickler& ErrorFilePickler::operator= ( const ErrorFilePickler &other )
{
    if (this != &other)
    {
        MOUSEION::BaseException::operator=(other);
        this->errorMessage_ = other.errorMessage_;
    }
    return *this;
} // assignment operator

ErrorFilePickler& ErrorFilePickler::operator= ( ErrorFilePickler && other )
{
    if (this != &other)
    {
        MOUSEION::BaseException::operator=(std::move(other));
        this->errorMessage_ = std::move(other.errorMessage_);
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
