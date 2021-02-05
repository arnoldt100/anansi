//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorNoOptionDescription.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorNoOptionDescription::ErrorNoOptionDescription()
{
	// TODO Auto-generated constructor stub
    return;
}

ErrorNoOptionDescription::ErrorNoOptionDescription( ErrorNoOptionDescription && other)
{
    return;
}		/* -----  end of method ErrorNoOptionDescription::ErrorNoOptionDescription  ----- */


ErrorNoOptionDescription::~ErrorNoOptionDescription()
{
	// TODO Auto-generated destructor stub
    return;
}

//============================= ACCESSORS ====================================
const char* ErrorNoOptionDescription::what() const noexcept
{
    return "The option has no option description.";
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorNoOptionDescription& ErrorNoOptionDescription::operator= ( const ErrorNoOptionDescription &other )
{
    if (this != &other)
    {

    }
    return *this;
} /* assignment operator */

ErrorNoOptionDescription& ErrorNoOptionDescription::operator=( ErrorNoOptionDescription && other )
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
