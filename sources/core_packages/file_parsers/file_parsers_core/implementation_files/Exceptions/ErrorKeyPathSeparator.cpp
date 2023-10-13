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

ErrorKeyPathSeparator::ErrorKeyPathSeparator( const std::array<char,1> & sep_char) : // constructor
    sepChar_{sep_char}
{
    this->errorMessage_ =  std::string("The key string contains a character that matches the\n");
    this->errorMessage_ += std::string("separator char '");
    this->errorMessage_ += std::string(this->sepChar_.begin(),this->sepChar_.end());
    this->errorMessage_ += std::string("'.");
    return;
}

ErrorKeyPathSeparator::ErrorKeyPathSeparator( ErrorKeyPathSeparator const & other) :
    sepChar_{other.sepChar_}
{
    if (this != &other)
    {
    }
    return;
}

ErrorKeyPathSeparator::ErrorKeyPathSeparator( ErrorKeyPathSeparator && other) :
    sepChar_{std::move(other.sepChar_)}
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
    }
    return *this;
} // assignment operator

ErrorKeyPathSeparator& ErrorKeyPathSeparator::operator= ( ErrorKeyPathSeparator && other )
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
