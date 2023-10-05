//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "KeyPathSeparator.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

KeyPathSeparator::KeyPathSeparator()
{
    return;
}

KeyPathSeparator::KeyPathSeparator( KeyPathSeparator const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

KeyPathSeparator::KeyPathSeparator( KeyPathSeparator && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method KeyPathSeparator::KeyPathSeparator  -----


KeyPathSeparator::~KeyPathSeparator()
{
    return;
}

//============================= ACCESSORS ====================================

KeyPathSeparator * KeyPathSeparator::clone() const
{
    return new KeyPathSeparator(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

KeyPathSeparator& KeyPathSeparator::operator= ( const KeyPathSeparator &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

KeyPathSeparator& KeyPathSeparator::operator= ( KeyPathSeparator && other )
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


} // namespace ANANSI
