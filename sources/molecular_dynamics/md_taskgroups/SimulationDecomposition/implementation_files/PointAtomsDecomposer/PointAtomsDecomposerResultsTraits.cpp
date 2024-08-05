//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PointAtomsDecomposerResultsTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

PointAtomsDecomposerResultsTraits::PointAtomsDecomposerResultsTraits()
{
    return;
}

PointAtomsDecomposerResultsTraits::PointAtomsDecomposerResultsTraits( PointAtomsDecomposerResultsTraits const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

PointAtomsDecomposerResultsTraits::PointAtomsDecomposerResultsTraits( PointAtomsDecomposerResultsTraits && other)
{
    if (this != &other)
    {
    }
    return;
}   


PointAtomsDecomposerResultsTraits::~PointAtomsDecomposerResultsTraits()
{
    return;
}

//============================= ACCESSORS ====================================

PointAtomsDecomposerResultsTraits * PointAtomsDecomposerResultsTraits::clone() const
{
    return new PointAtomsDecomposerResultsTraits(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

PointAtomsDecomposerResultsTraits& PointAtomsDecomposerResultsTraits::operator= ( const PointAtomsDecomposerResultsTraits &other )
{
    if (this != &other)
    {
    }
    return *this;
} 

PointAtomsDecomposerResultsTraits& PointAtomsDecomposerResultsTraits::operator= ( PointAtomsDecomposerResultsTraits && other )
{
    if (this != &other)
    {

    }
    return *this;
}

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


}; // ----- End of namespace ANANSI -----
