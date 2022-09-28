//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ConsoleLoggingTask.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ConsoleLoggingTask::ConsoleLoggingTask() :
    LoggingTask()
{
    return;
}

ConsoleLoggingTask::ConsoleLoggingTask( ConsoleLoggingTask const & other) :
   LoggingTask(other) 
{
    if (this != &other)
    {
        
    }
    return;
}

ConsoleLoggingTask::ConsoleLoggingTask( ConsoleLoggingTask && other) : 
    LoggingTask(std::move(other))
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ConsoleLoggingTask::ConsoleLoggingTask  -----


ConsoleLoggingTask::~ConsoleLoggingTask()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ConsoleLoggingTask& ConsoleLoggingTask::operator=( const ConsoleLoggingTask &other )
{
    if (this != &other)
    {
        LoggingTask::operator=(other);
    }
    return *this;
} // assignment operator

ConsoleLoggingTask& ConsoleLoggingTask::operator=( ConsoleLoggingTask && other )
{
    if (this != &other)
    {
        LoggingTask::operator=(std::move(other));
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

void ConsoleLoggingTask::enable_()
{
    std::cout << "Enabling console logger." << std::endl;
    return;
}
        
void ConsoleLoggingTask::disable_() 
{
    std::cout << "Disabling console logger." << std::endl;
    return;
}
//============================= OPERATORS ====================================


} // namespace ANANSI
