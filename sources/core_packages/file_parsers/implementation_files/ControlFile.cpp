
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFile.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFile::ControlFile() :
    BaseInputFile<ControlFile>(),
    fileName_()
{
    return;
}

ControlFile::ControlFile( const ControlFile & other) : 
    BaseInputFile<ControlFile>(other),
    fileName_(other.fileName_)
{
    return;
} // -----  end of method ControlFile::ControlFile  -----

ControlFile::ControlFile( ControlFile && other) :
    BaseInputFile<ControlFile>(std::move(other)),
    fileName_(std::move(other.fileName_))

{
    return;
} // -----  end of method ControlFile::ControlFile  -----


ControlFile::~ControlFile()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFile& ControlFile::operator= ( const ControlFile & other )
{
    if (this != &other)
    {
        BaseInputFile<ControlFile>::operator=(other);
        this->fileName_ = other.fileName_;
    }
    return *this;
} // assignment operator


ControlFile& ControlFile::operator= ( ControlFile && other )
{
    if (this != &other)
    {
        BaseInputFile<ControlFile>::operator=(std::move(other));
        this->fileName_ = std::move(other.fileName_);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void ControlFile::setFileName_(const std::string my_file_name)
{
    this->fileName_ = my_file_name;
    return;
}

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
