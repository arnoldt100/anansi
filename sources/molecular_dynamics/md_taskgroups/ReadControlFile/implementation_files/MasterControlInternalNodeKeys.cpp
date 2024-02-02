//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MasterControlInternalNodeKeys.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MasterControlInternalNodeKeys::MasterControlInternalNodeKeys()
{
    return;
}

MasterControlInternalNodeKeys::MasterControlInternalNodeKeys( MasterControlInternalNodeKeys const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

MasterControlInternalNodeKeys::MasterControlInternalNodeKeys( MasterControlInternalNodeKeys && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method MasterControlInternalNodeKeys::MasterControlInternalNodeKeys  -----


MasterControlInternalNodeKeys::~MasterControlInternalNodeKeys()
{
    return;
}

//============================= ACCESSORS ====================================

MasterControlInternalNodeKeys * MasterControlInternalNodeKeys::clone() const
{
    return new MasterControlInternalNodeKeys(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MasterControlInternalNodeKeys& MasterControlInternalNodeKeys::operator= ( const MasterControlInternalNodeKeys &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

MasterControlInternalNodeKeys& MasterControlInternalNodeKeys::operator= ( MasterControlInternalNodeKeys && other )
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
