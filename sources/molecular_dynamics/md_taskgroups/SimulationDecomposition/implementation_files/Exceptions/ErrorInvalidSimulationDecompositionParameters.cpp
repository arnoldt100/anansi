//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorInvalidSimulationDecompositionValue.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorInvalidSimulationDecompositionValue::ErrorInvalidSimulationDecompositionValue() :
    MOUSEION::BaseException{},
    errorMessage_{}
{
    return;
}

ErrorInvalidSimulationDecompositionValue::ErrorInvalidSimulationDecompositionValue(const std::string message) :
    MOUSEION::BaseException{},
    errorMessage_{message}
{
    return;
}

ErrorInvalidSimulationDecompositionValue::ErrorInvalidSimulationDecompositionValue( ErrorInvalidSimulationDecompositionValue const & other) :
    MOUSEION::BaseException{other},
    errorMessage_{other.errorMessage_}
{
    if (this != &other)
    {
        
    }
    return;
}

ErrorInvalidSimulationDecompositionValue::ErrorInvalidSimulationDecompositionValue( ErrorInvalidSimulationDecompositionValue && other) :
MOUSEION::BaseException{std::move(other)},
    errorMessage_{std::move(other.errorMessage_)}

{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ErrorInvalidSimulationDecompositionValue::ErrorInvalidSimulationDecompositionValue  -----


ErrorInvalidSimulationDecompositionValue::~ErrorInvalidSimulationDecompositionValue()
{
    return;
}

//============================= ACCESSORS ====================================
const char* ErrorInvalidSimulationDecompositionValue::what() const noexcept 
{
    return this->errorMessage_.c_str();
}

ErrorInvalidSimulationDecompositionValue * ErrorInvalidSimulationDecompositionValue::clone() const
{
    return new ErrorInvalidSimulationDecompositionValue(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorInvalidSimulationDecompositionValue& ErrorInvalidSimulationDecompositionValue::operator=( const ErrorInvalidSimulationDecompositionValue &other )
{
    if (this != &other)
    {
        MOUSEION::BaseException::operator=(other);
        this->errorMessage_ = other.errorMessage_;
    }
    return *this;
} // assignment operator

ErrorInvalidSimulationDecompositionValue& ErrorInvalidSimulationDecompositionValue::operator=( ErrorInvalidSimulationDecompositionValue && other )
{
    if (this != &other)
    {
        MOUSEION::BaseException::operator=(std::move(other));
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
