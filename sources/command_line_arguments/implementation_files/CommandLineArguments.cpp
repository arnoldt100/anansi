/*
 * CommandLineArguments.cpp
 *
 *      Authors: Arnold N. Tharrington
 */

#include "CommandLineArguments.h"

namespace COMMANDLINE {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommandLineArguments::CommandLineArguments() :
_numberOfArguments(0)
{
    return;
}

CommandLineArguments::CommandLineArguments( const int argc, char const * const *const & argv) :
_numberOfArguments(argc)
{
    for (int ip=0; ip < argc; ++ip)
    {
        const std::string aArgument(argv[ip]); 
        (this->_commandLineArguments).push_back(aArgument);
    }
    return;
}

CommandLineArguments::CommandLineArguments( const CommandLineArguments &other ) :
_numberOfArguments(other._numberOfArguments),
_commandLineArguments(other._commandLineArguments)
{
    return;
}

CommandLineArguments::~CommandLineArguments()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CommandLineArguments&
CommandLineArguments::operator=( const CommandLineArguments &other )
{
    if (this != &other)
    {
        this->_numberOfArguments = other._numberOfArguments;
        this->_commandLineArguments = other._commandLineArguments;
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


} /* namespace COMMANDLINE */
