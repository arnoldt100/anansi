
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PointAtomsInternalNodeKeys.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

PointAtomsInternalNodeKeys::PointAtomsInternalNodeKeys()
{
    return;
}

PointAtomsInternalNodeKeys::PointAtomsInternalNodeKeys( PointAtomsInternalNodeKeys const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

PointAtomsInternalNodeKeys::PointAtomsInternalNodeKeys( PointAtomsInternalNodeKeys && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method PointAtomsInternalNodeKeys::PointAtomsInternalNodeKeys  -----


PointAtomsInternalNodeKeys::~PointAtomsInternalNodeKeys()
{
    return;
}

//============================= ACCESSORS ====================================

PointAtomsInternalNodeKeys * PointAtomsInternalNodeKeys::clone() const
{
    return new PointAtomsInternalNodeKeys(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

PointAtomsInternalNodeKeys& PointAtomsInternalNodeKeys::operator= ( const PointAtomsInternalNodeKeys &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

PointAtomsInternalNodeKeys& PointAtomsInternalNodeKeys::operator= ( PointAtomsInternalNodeKeys && other )
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
