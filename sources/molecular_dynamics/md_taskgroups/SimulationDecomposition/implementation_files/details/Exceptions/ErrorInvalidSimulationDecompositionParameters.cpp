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
#include "ErrorInvalidSimulationDecompositionParameters.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorInvalidSimulationDecompositionParameters::ErrorInvalidSimulationDecompositionParameters() :
    MOUSEION::BaseException{},
    errorMessage_{}
{
    return;
}

ErrorInvalidSimulationDecompositionParameters::ErrorInvalidSimulationDecompositionParameters(const std::string message) :
    MOUSEION::BaseException{},
    errorMessage_{message}
{
    return;
}

ErrorInvalidSimulationDecompositionParameters::ErrorInvalidSimulationDecompositionParameters( ErrorInvalidSimulationDecompositionParameters const & other) :
    MOUSEION::BaseException{other},
    errorMessage_{other.errorMessage_}
{
    if (this != &other)
    {
        
    }
    return;
}

ErrorInvalidSimulationDecompositionParameters::ErrorInvalidSimulationDecompositionParameters( ErrorInvalidSimulationDecompositionParameters && other) :
MOUSEION::BaseException{std::move(other)},
    errorMessage_{std::move(other.errorMessage_)}

{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ErrorInvalidSimulationDecompositionParameters::ErrorInvalidSimulationDecompositionParameters  -----


ErrorInvalidSimulationDecompositionParameters::~ErrorInvalidSimulationDecompositionParameters()
{
    return;
}

//============================= ACCESSORS ====================================
const char* ErrorInvalidSimulationDecompositionParameters::what() const noexcept 
{
    return this->errorMessage_.c_str();
}

ErrorInvalidSimulationDecompositionParameters * ErrorInvalidSimulationDecompositionParameters::clone() const
{
    return new ErrorInvalidSimulationDecompositionParameters(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorInvalidSimulationDecompositionParameters& ErrorInvalidSimulationDecompositionParameters::operator=( const ErrorInvalidSimulationDecompositionParameters &other )
{
    if (this != &other)
    {
        MOUSEION::BaseException::operator=(other);
        this->errorMessage_ = other.errorMessage_;
    }
    return *this;
} // assignment operator

ErrorInvalidSimulationDecompositionParameters& ErrorInvalidSimulationDecompositionParameters::operator=( ErrorInvalidSimulationDecompositionParameters && other )
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
