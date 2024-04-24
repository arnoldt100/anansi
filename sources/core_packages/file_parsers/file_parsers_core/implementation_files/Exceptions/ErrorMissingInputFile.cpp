
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorMissingInputFile.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorMissingInputFile::ErrorMissingInputFile() :
    errorMessage_{}
{
    return;
}

ErrorMissingInputFile::ErrorMissingInputFile(const std::string message) :
    errorMessage_{message}
{
    return;
}

ErrorMissingInputFile::ErrorMissingInputFile( ErrorMissingInputFile const & other) :
   errorMessage_{other.errorMessage_}
{
    if (this != &other)
    {
    }
    return;
}

ErrorMissingInputFile::ErrorMissingInputFile( ErrorMissingInputFile && other) :
   errorMessage_{std::move(other.errorMessage_)}
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ErrorMissingInputFile::ErrorMissingInputFile  -----


ErrorMissingInputFile::~ErrorMissingInputFile()
{
    return;
}

//============================= ACCESSORS ====================================

ErrorMissingInputFile * ErrorMissingInputFile::clone() const
{
    return new ErrorMissingInputFile(*this);
}

const char* ErrorMissingInputFile::what() const noexcept
{
    return this->errorMessage_.c_str();
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorMissingInputFile& ErrorMissingInputFile::operator= ( const ErrorMissingInputFile &other )
{
    if (this != &other)
    {
        this->errorMessage_ = other.errorMessage_;
    }
    return *this;
} // assignment operator

ErrorMissingInputFile& ErrorMissingInputFile::operator= ( ErrorMissingInputFile && other )
{
    if (this != &other)
    {
        this->errorMessage_ = std::move(other.errorMessage_);
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
