//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorInvalidSimulationWorkloadDecompositionType.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorInvalidSimulationWorkloadDecompositionType::ErrorInvalidSimulationWorkloadDecompositionType() :
    MOUSEION::BaseException{},
    errorMessage_{}
{
    return;
}

ErrorInvalidSimulationWorkloadDecompositionType::ErrorInvalidSimulationWorkloadDecompositionType(const std::string message) :
    MOUSEION::BaseException{},
    errorMessage_{message}
{
    return;
}

ErrorInvalidSimulationWorkloadDecompositionType::ErrorInvalidSimulationWorkloadDecompositionType( ErrorInvalidSimulationWorkloadDecompositionType const & other) :
    MOUSEION::BaseException{other},
    errorMessage_{other.errorMessage_}

{
    if (this != &other)
    {
        
    }
    return;
}

ErrorInvalidSimulationWorkloadDecompositionType::ErrorInvalidSimulationWorkloadDecompositionType( ErrorInvalidSimulationWorkloadDecompositionType && other) : 
    MOUSEION::BaseException{std::move(other)},
    errorMessage_{std::move(other.errorMessage_)}

{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ErrorInvalidSimulationWorkloadDecompositionType::ErrorInvalidSimulationWorkloadDecompositionType  -----


ErrorInvalidSimulationWorkloadDecompositionType::~ErrorInvalidSimulationWorkloadDecompositionType()
{
    return;
}

//============================= ACCESSORS ====================================
const char* ErrorInvalidSimulationWorkloadDecompositionType::what() const noexcept
{
    return this->errorMessage_.c_str();
}


ErrorInvalidSimulationWorkloadDecompositionType * ErrorInvalidSimulationWorkloadDecompositionType::clone() const
{
    return new ErrorInvalidSimulationWorkloadDecompositionType(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorInvalidSimulationWorkloadDecompositionType& ErrorInvalidSimulationWorkloadDecompositionType::operator= ( const ErrorInvalidSimulationWorkloadDecompositionType &other )
{
    if (this != &other)
    {
        MOUSEION::BaseException::operator=(other);
        this->errorMessage_ = other.errorMessage_;
    }
    return *this;
} // assignment operator

ErrorInvalidSimulationWorkloadDecompositionType& ErrorInvalidSimulationWorkloadDecompositionType::operator= ( ErrorInvalidSimulationWorkloadDecompositionType && other )
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
