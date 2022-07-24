//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ConsoleLogger.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ConsoleLogger::ConsoleLogger() :
    Logger()
{
    return;
}

ConsoleLogger::ConsoleLogger( ConsoleLogger const & other) :
   Logger(other) 
{
    if (this != &other)
    {
        
    }
    return;
}

ConsoleLogger::ConsoleLogger( ConsoleLogger && other) : 
    Logger(std::move(other))
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ConsoleLogger::ConsoleLogger  -----


ConsoleLogger::~ConsoleLogger()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ConsoleLogger& ConsoleLogger::operator=( const ConsoleLogger &other )
{
    if (this != &other)
    {
        Logger::operator=(other);
    }
    return *this;
} // assignment operator

ConsoleLogger& ConsoleLogger::operator=( ConsoleLogger && other )
{
    if (this != &other)
    {
        Logger::operator=(std::move(other));
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
void ConsoleLogger::logMessage_(const std::string message) const 
{
    BOOST_LOG_TRIVIAL(info) << message;
    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
