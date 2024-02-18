//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PointAtomsCommunicatorResultsTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

PointAtomsCommunicatorResultsTraits::PointAtomsCommunicatorResultsTraits()
{
    return;
}

PointAtomsCommunicatorResultsTraits::PointAtomsCommunicatorResultsTraits( PointAtomsCommunicatorResultsTraits const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

PointAtomsCommunicatorResultsTraits::PointAtomsCommunicatorResultsTraits( PointAtomsCommunicatorResultsTraits && other)
{
    if (this != &other)
    {
    }
    return;
}   


PointAtomsCommunicatorResultsTraits::~PointAtomsCommunicatorResultsTraits()
{
    return;
}

//============================= ACCESSORS ====================================

PointAtomsCommunicatorResultsTraits * PointAtomsCommunicatorResultsTraits::clone() const
{
    return new PointAtomsCommunicatorResultsTraits(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

PointAtomsCommunicatorResultsTraits& PointAtomsCommunicatorResultsTraits::operator= ( const PointAtomsCommunicatorResultsTraits &other )
{
    if (this != &other)
    {
    }
    return *this;
} 

PointAtomsCommunicatorResultsTraits& PointAtomsCommunicatorResultsTraits::operator= ( PointAtomsCommunicatorResultsTraits && other )
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
