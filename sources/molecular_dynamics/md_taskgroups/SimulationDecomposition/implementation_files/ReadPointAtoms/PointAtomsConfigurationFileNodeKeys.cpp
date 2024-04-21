
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PointAtomsConfigurationFileNodeKeys.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

PointAtomsConfigurationFileNodeKeys::PointAtomsConfigurationFileNodeKeys()
{
    return;
}

PointAtomsConfigurationFileNodeKeys::PointAtomsConfigurationFileNodeKeys( PointAtomsConfigurationFileNodeKeys const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

PointAtomsConfigurationFileNodeKeys::PointAtomsConfigurationFileNodeKeys( PointAtomsConfigurationFileNodeKeys && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method PointAtomsConfigurationFileNodeKeys::PointAtomsConfigurationFileNodeKeys  -----


PointAtomsConfigurationFileNodeKeys::~PointAtomsConfigurationFileNodeKeys()
{
    return;
}

//============================= ACCESSORS ====================================

PointAtomsConfigurationFileNodeKeys * PointAtomsConfigurationFileNodeKeys::clone() const
{
    return new PointAtomsConfigurationFileNodeKeys(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

PointAtomsConfigurationFileNodeKeys& PointAtomsConfigurationFileNodeKeys::operator= ( const PointAtomsConfigurationFileNodeKeys &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

PointAtomsConfigurationFileNodeKeys& PointAtomsConfigurationFileNodeKeys::operator= ( PointAtomsConfigurationFileNodeKeys && other )
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
