
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandFiles.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================
CommandFiles::CommandFilesConcept::~CommandFilesConcept()
{
    return;
}

CommandFiles::CommandFiles() :
    valuePtr_(nullptr)
{
    return;
}

CommandFiles::CommandFiles(CommandFiles const & other)
{
    if (this != &other)
    {
        this->valuePtr_ = other.valuePtr_->clone();
    }
    return;
}

CommandFiles::CommandFiles(CommandFiles && other)
{
    if (this != &other)
    {
        this->valuePtr_ = std::move(other.valuePtr_); 
    }
    return;
}		// -----  end of method CommandFiles::CommandFiles  -----


CommandFiles::~CommandFiles()
{
    return;
}

//============================= ACCESSORS ====================================
CommandFiles CommandFiles::clone () const
{
    return new CommandFiles(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CommandFiles& CommandFiles::operator= ( const CommandFiles &other )
{
    if (this != &other)
    {
        this->valuePtr_  = other.valuePtr_->clone();
    }
    return *this;
} // assignment operator

CommandFiles& CommandFiles::operator= ( CommandFiles && other )
{
    if (this != &other)
    {
        this->valuePtr_ = std::move(other.valuePtr_); 
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

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Nonmeber Functions ///////////////////////////
//////////////////////////////////////////////////////////////////////////////

// void set_file_name(CommandFiles && command_file, CommandFileName filename)
// {
//     command_file.setFileName(filename);
// }
// 
// void set_file_name(CommandFiles & command_file, CommandFileName filename)
// {
//     command_file.setFileName(filename);
// }
// 
// void read_command_file(CommandFiles & command_file)
// {
//     command_file.readCommandFile();
// }
// 
// void read_command_file(CommandFiles && command_file)
// {
//     command_file.readCommandFile();
// }

} // namespace ANANSI
