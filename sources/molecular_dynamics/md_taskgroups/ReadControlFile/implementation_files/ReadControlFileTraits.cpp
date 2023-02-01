//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReadControlFileTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ReadControlFileTraits::ReadControlFileTraits() 
{
    return;
}

ReadControlFileTraits::ReadControlFileTraits( ReadControlFileTraits const & other) 
{
    if (this != &other)
    {
    }
    return;
}

ReadControlFileTraits::ReadControlFileTraits( ReadControlFileTraits && other) 
{
    if (this != &other)
    {
    }
    return;
}

ReadControlFileTraits::~ReadControlFileTraits()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ReadControlFileTraits& ReadControlFileTraits::operator= ( const ReadControlFileTraits &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

ReadControlFileTraits& ReadControlFileTraits::operator= ( ReadControlFileTraits && other )
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