//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorIllFormedOption.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorIllFormedOption::ErrorIllFormedOption()
{
    return;
}

ErrorIllFormedOption::ErrorIllFormedOption( ErrorIllFormedOption const & other)
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method ErrorIllFormedOption::ErrorIllFormedOption  ----- */

ErrorIllFormedOption::ErrorIllFormedOption( ErrorIllFormedOption && other)
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method ErrorIllFormedOption::ErrorIllFormedOption  ----- */


ErrorIllFormedOption::~ErrorIllFormedOption()
{
    return;
}

//============================= ACCESSORS ====================================
const char* ErrorIllFormedOption::what() const noexcept
{
    return "The option is Illformed.";
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorIllFormedOption& ErrorIllFormedOption::operator= ( const ErrorIllFormedOption &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

ErrorIllFormedOption& ErrorIllFormedOption::operator= ( ErrorIllFormedOption && other )
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


} /* namespace ANANSI */
