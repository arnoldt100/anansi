//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "KeyPathSeparatorPeriod.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

KeyPathSeparatorPeriod::KeyPathSeparatorPeriod()
{
    return;
}

KeyPathSeparatorPeriod::KeyPathSeparatorPeriod( KeyPathSeparatorPeriod const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

KeyPathSeparatorPeriod::KeyPathSeparatorPeriod( KeyPathSeparatorPeriod && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method KeyPathSeparatorPeriod::KeyPathSeparatorPeriod  -----


KeyPathSeparatorPeriod::~KeyPathSeparatorPeriod()
{
    return;
}

//============================= ACCESSORS ====================================

KeyPathSeparatorPeriod * KeyPathSeparatorPeriod::clone() const
{
    return new KeyPathSeparatorPeriod(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

KeyPathSeparatorPeriod& KeyPathSeparatorPeriod::operator=( const KeyPathSeparatorPeriod &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

KeyPathSeparatorPeriod& KeyPathSeparatorPeriod::operator= ( KeyPathSeparatorPeriod && other )
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
