//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorNoOptionAdded.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorNoOptionAdded::ErrorNoOptionAdded()
{
	// TODO Auto-generated constructor stub
    return;
}

ErrorNoOptionAdded::ErrorNoOptionAdded( ErrorNoOptionAdded && other)
{
    return;
}		/* -----  end of method ErrorNoOptionAdded::ErrorNoOptionAdded  ----- */


ErrorNoOptionAdded::~ErrorNoOptionAdded()
{
	// TODO Auto-generated destructor stub
    return;
}

//============================= ACCESSORS ====================================
const char* ErrorNoOptionAdded::what() const noexcept
{
    return "An option was not added.";
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorNoOptionAdded& ErrorNoOptionAdded::operator= ( const ErrorNoOptionAdded &other )
{
    if (this != &other)
    {

    }
    return *this;
} /* assignment operator */

ErrorNoOptionAdded& ErrorNoOptionAdded::operator=( ErrorNoOptionAdded && other )
{
    if (this != &other)
    {

    }
    return *this;
} /* assignment-move operator */

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