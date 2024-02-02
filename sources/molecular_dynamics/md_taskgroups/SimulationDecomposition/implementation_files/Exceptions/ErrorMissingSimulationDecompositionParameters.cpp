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
#include "ErrorMissingSimulationDecompositionParameters.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorMissingSimulationDecompositionParameters::ErrorMissingSimulationDecompositionParameters() :
    MOUSEION::BaseException{},
    errorMessage_{}
{
    return;
}

ErrorMissingSimulationDecompositionParameters::ErrorMissingSimulationDecompositionParameters(const std::string message) :
    MOUSEION::BaseException{},
    errorMessage_{message}
{
    return;
}

ErrorMissingSimulationDecompositionParameters::ErrorMissingSimulationDecompositionParameters( ErrorMissingSimulationDecompositionParameters const & other) :
    MOUSEION::BaseException{other},
    errorMessage_{other.errorMessage_}
{
    if (this != &other)
    {
        
    }
    return;
}

ErrorMissingSimulationDecompositionParameters::ErrorMissingSimulationDecompositionParameters( ErrorMissingSimulationDecompositionParameters && other) : 
    MOUSEION::BaseException{std::move(other)},
    errorMessage_{std::move(other.errorMessage_)}
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ErrorMissingSimulationDecompositionParameters::ErrorMissingSimulationDecompositionParameters  -----


ErrorMissingSimulationDecompositionParameters::~ErrorMissingSimulationDecompositionParameters()
{
    return;
}

//============================= ACCESSORS ====================================
const char* ErrorMissingSimulationDecompositionParameters::what () const noexcept
{
    return this->errorMessage_.c_str();
}

ErrorMissingSimulationDecompositionParameters * ErrorMissingSimulationDecompositionParameters::clone() const
{
    return new ErrorMissingSimulationDecompositionParameters(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorMissingSimulationDecompositionParameters& ErrorMissingSimulationDecompositionParameters::operator= ( const ErrorMissingSimulationDecompositionParameters &other ) 
{
    if (this != &other)
    {
        MOUSEION::BaseException::operator=(other);
        this->errorMessage_ = other.errorMessage_;
    }
    return *this;
} // assignment operator

ErrorMissingSimulationDecompositionParameters& ErrorMissingSimulationDecompositionParameters::operator= ( ErrorMissingSimulationDecompositionParameters && other )
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
