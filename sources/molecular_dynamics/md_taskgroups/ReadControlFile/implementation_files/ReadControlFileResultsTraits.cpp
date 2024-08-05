//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReadControlFileResultsTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ReadControlFileResultsTraits::ReadControlFileResultsTraits()
{
    return;
}

ReadControlFileResultsTraits::ReadControlFileResultsTraits( ReadControlFileResultsTraits const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

ReadControlFileResultsTraits::ReadControlFileResultsTraits( ReadControlFileResultsTraits && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ReadControlFileResultsTraits::ReadControlFileResultsTraits  -----


ReadControlFileResultsTraits::~ReadControlFileResultsTraits()
{
    return;
}

//============================= ACCESSORS ====================================

ReadControlFileResultsTraits * ReadControlFileResultsTraits::clone() const
{
    return new ReadControlFileResultsTraits(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ReadControlFileResultsTraits& ReadControlFileResultsTraits::operator= ( const ReadControlFileResultsTraits &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

ReadControlFileResultsTraits& ReadControlFileResultsTraits::operator= ( ReadControlFileResultsTraits && other )
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
