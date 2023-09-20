
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlInputFile.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlInputFile::ControlInputFile() :
    filename_()
{
    return;
}

ControlInputFile::ControlInputFile( ControlInputFile const & other) :
    filename_(other.filename_)
{
    if (this != &other)
    {
        
    }
    return;
}

ControlInputFile::ControlInputFile( ControlInputFile && other) :
    filename_(std::move(other.filename_))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method ControlInputFile::ControlInputFile  -----


ControlInputFile::~ControlInputFile()
{
    return;
}

//============================= ACCESSORS ====================================
ControlInputFile* ControlInputFile::clone() const
{
    return new ControlInputFile(*this);
}

//============================= MUTATORS =====================================
void ControlInputFile::setFileName(const CommandFileName & command_file_name)
{
    this->filename_ = command_file_name;
}

void ControlInputFile::readFile()
{
   return;
}

//============================= OPERATORS ====================================

ControlInputFile& ControlInputFile::operator=( const ControlInputFile &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

ControlInputFile& ControlInputFile::operator=( ControlInputFile && other )
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

void set_file_name_alt(ANANSI::ControlInputFile & object,ANANSI::CommandFileName filename)
{
    object.setFileName(filename);
};

void read_file(ANANSI::ControlInputFile & object)
{
    object.readFile();
};

} // namespace ANANSI
