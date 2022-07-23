/*
 * CommandLineArguments.cpp
 *
 *      Authors: Arnold N. Tharrington
 */
#include <algorithm>

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

CommandLineArguments::CommandLineArguments( const CommandLineArguments &other ) 
{
    if (this != &other)
    {
        this->_numberOfArguments=other._numberOfArguments;
        this->_commandLineArguments = std::move(other._commandLineArguments);
    }
    return;
}

CommandLineArguments::CommandLineArguments( CommandLineArguments && other ) 
{
    if (this != &other)
    {
        this->_numberOfArguments = other._numberOfArguments;
        this->_commandLineArguments = std::move(other._commandLineArguments);
        other._numberOfArguments = 0;
    }
    return;
}
CommandLineArguments::~CommandLineArguments()
{
    return;
}

//============================= ACCESSORS ====================================
void CommandLineArguments::reformCommandLineArguments(int & argc, char** & argv) const
{
    argc = this->_numberOfArguments;
    argv = new char*[argc];
    for (int ip=0; ip < argc; ++ip)
    {
        const int c_string_length = this->_commandLineArguments[ip].length() + 1;
        argv[ip] = new char[c_string_length];
        strcpy(argv[ip],this->_commandLineArguments[ip].c_str());
    }
    return;
}

bool CommandLineArguments::findArgument( const std::string & str ) const
{
    const auto search = std::find(std::begin(this->_commandLineArguments),
                             std::end(this->_commandLineArguments),
                             str);
    const auto v1 = (search != std::end(this->_commandLineArguments)) ? true : false;

    return v1;
}

//============================= MUTATORS =====================================

void CommandLineArguments::reset()
{
    this->_numberOfArguments=0;
    this->_commandLineArguments.clear();
    return;
}
//============================= OPERATORS ====================================

CommandLineArguments&
CommandLineArguments::operator=( const CommandLineArguments & other )
{
    if (this != &other)
    {
        this->_numberOfArguments = other._numberOfArguments;
        this->_commandLineArguments = other._commandLineArguments;
    }
    return *this;
}

CommandLineArguments&
CommandLineArguments::operator=( CommandLineArguments && other )
{
    if (this != &other)
    {
        this->_numberOfArguments = other._numberOfArguments;
        this->_commandLineArguments = std::move(other._commandLineArguments);
        other._numberOfArguments = 0;
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
