//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Exceptions/ErrorKeyPathSeparator.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorKeyPathSeparator::ErrorKeyPathSeparator()
{
    return;
}

ErrorKeyPathSeparator::ErrorKeyPathSeparator( const std::array<char,2> & sep_char,const std::string & path_key) : // constructor
    sepChar_{sep_char},
    pathKey_{path_key}
{
    this->errorMessage_ =  std::string("The path_key '");
    this->errorMessage_ +=  path_key;
    this->errorMessage_ += std::string("' ");
    this->errorMessage_ =  std::string("contains a character that matches the\n");
    this->errorMessage_ += std::string("path separator charcter '");
    this->errorMessage_ += std::string(this->sepChar_.begin(),this->sepChar_.end());
    this->errorMessage_ += std::string("'.");
    return;
}

ErrorKeyPathSeparator::ErrorKeyPathSeparator( ErrorKeyPathSeparator const & other) :
    sepChar_{other.sepChar_},
    pathKey_{other.pathKey_}
{
    if (this != &other)
    {
    }
    return;
}

ErrorKeyPathSeparator::ErrorKeyPathSeparator( ErrorKeyPathSeparator && other) :
    sepChar_{std::move(other.sepChar_)},
    pathKey_{std::move(other.pathKey_)}
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ErrorKeyPathSeparator::ErrorKeyPathSeparator  -----


ErrorKeyPathSeparator::~ErrorKeyPathSeparator()
{
    return;
}

//============================= ACCESSORS ====================================

ErrorKeyPathSeparator * ErrorKeyPathSeparator::clone() const
{
    return new ErrorKeyPathSeparator(*this);
}

const char* ErrorKeyPathSeparator::what() const noexcept 
{
    return this->errorMessage_.c_str();
}
//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorKeyPathSeparator& ErrorKeyPathSeparator::operator= ( const ErrorKeyPathSeparator &other )
{
    if (this != &other)
    {
        this->sepChar_ = other.sepChar_;
        this->pathKey_ = other.pathKey_;
    }
    return *this;
} // assignment operator

ErrorKeyPathSeparator& ErrorKeyPathSeparator::operator= ( ErrorKeyPathSeparator && other )
{
    if (this != &other)
    {
        this->sepChar_ = std::move(other.sepChar_);
        this->pathKey_ = std::move(other.pathKey_);
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
