//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorInvalidMPIEnvironmentChange.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange() :
    originalState_{"'Original state not specified'"},
    action_{"'Action not specified'"}
{
    return;
}

ErrorInvalidMPIEnvironmentChange::ErrorInvalidMPIEnvironmentChange(std::string_view const original_state,
                                                                   std::string_view const action ) :
    originalState_{original_state},
    action_{action}
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
    std::string message("Invalid action on MPIEnviromentState: ");
    message += std::string(this->originalState_) + std::string("\n");
    message += std::string("Attempting to do action ") + std::string(this->action_);
    message += std::string(" which is not a permitted action for state ") + std::string(this->originalState_) + std::string(".\n");
    return message.c_str();
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

} // namespace ANANSI
