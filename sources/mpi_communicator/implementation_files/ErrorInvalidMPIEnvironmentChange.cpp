//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorInvalidMPIEnvironmentChange.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange()
{
    return;
}

ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange( ErrorInvalidMPIEnvironmentChange const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange( ErrorInvalidMPIEnvironmentChange && other)
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange  -----


ErrorInvalidMPIEnvironmentChange::~ErrorInvalidMPIEnvironmentChange()
{
    return;
}

//============================= ACCESSORS ====================================

const char* ErrorInvalidMPIEnvironmentChange::what() const noexcept
{
    return "Invalid change of MPIEnviromentState.";
}


//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorInvalidMPIEnvironmentChange& ErrorInvalidMPIEnvironmentChange::operator= ( const ErrorInvalidMPIEnvironmentChange &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

ErrorInvalidMPIEnvironmentChange& ErrorInvalidMPIEnvironmentChange::operator= ( ErrorInvalidMPIEnvironmentChange && other )
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


} // namespace COMMUNICATOR
