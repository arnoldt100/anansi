//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReadPointAtomsResultsTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ReadPointAtomsResultsTraits::ReadPointAtomsResultsTraits()
{
    return;
}

ReadPointAtomsResultsTraits::ReadPointAtomsResultsTraits( ReadPointAtomsResultsTraits const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

ReadPointAtomsResultsTraits::ReadPointAtomsResultsTraits( ReadPointAtomsResultsTraits && other)
{
    if (this != &other)
    {
    }
    return;
}   


ReadPointAtomsResultsTraits::~ReadPointAtomsResultsTraits()
{
    return;
}

//============================= ACCESSORS ====================================

ReadPointAtomsResultsTraits * ReadPointAtomsResultsTraits::clone() const
{
    return new ReadPointAtomsResultsTraits(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ReadPointAtomsResultsTraits& ReadPointAtomsResultsTraits::operator= ( const ReadPointAtomsResultsTraits &other )
{
    if (this != &other)
    {
    }
    return *this;
} 

ReadPointAtomsResultsTraits& ReadPointAtomsResultsTraits::operator= ( ReadPointAtomsResultsTraits && other )
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
