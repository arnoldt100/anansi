//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MacroReadPointAtomsResultsTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MacroReadPointAtomsResultsTraits::MacroReadPointAtomsResultsTraits()
{
    return;
}

MacroReadPointAtomsResultsTraits::MacroReadPointAtomsResultsTraits( MacroReadPointAtomsResultsTraits const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

MacroReadPointAtomsResultsTraits::MacroReadPointAtomsResultsTraits( MacroReadPointAtomsResultsTraits && other)
{
    if (this != &other)
    {
    }
    return;
}   


MacroReadPointAtomsResultsTraits::~MacroReadPointAtomsResultsTraits()
{
    return;
}

//============================= ACCESSORS ====================================

MacroReadPointAtomsResultsTraits * MacroReadPointAtomsResultsTraits::clone() const
{
    return new MacroReadPointAtomsResultsTraits(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MacroReadPointAtomsResultsTraits& MacroReadPointAtomsResultsTraits::operator= ( const MacroReadPointAtomsResultsTraits &other )
{
    if (this != &other)
    {
    }
    return *this;
} 

MacroReadPointAtomsResultsTraits& MacroReadPointAtomsResultsTraits::operator= ( MacroReadPointAtomsResultsTraits && other )
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
