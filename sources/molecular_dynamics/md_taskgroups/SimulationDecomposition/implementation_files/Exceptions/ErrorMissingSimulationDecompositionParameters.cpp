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
#include "ErrorMissingSimulationWorkloadDecompositionParameters.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorMissingSimulationWorkloadDecompositionParameters::ErrorMissingSimulationWorkloadDecompositionParameters() :
    MOUSEION::BaseException{},
    errorMessage_{}
{
    return;
}

ErrorMissingSimulationWorkloadDecompositionParameters::ErrorMissingSimulationWorkloadDecompositionParameters(const std::string message) :
    MOUSEION::BaseException{},
    errorMessage_{message}
{
    return;
}

ErrorMissingSimulationWorkloadDecompositionParameters::ErrorMissingSimulationWorkloadDecompositionParameters( ErrorMissingSimulationWorkloadDecompositionParameters const & other) :
    MOUSEION::BaseException{other},
    errorMessage_{other.errorMessage_}
{
    if (this != &other)
    {
        
    }
    return;
}

ErrorMissingSimulationWorkloadDecompositionParameters::ErrorMissingSimulationWorkloadDecompositionParameters( ErrorMissingSimulationWorkloadDecompositionParameters && other) : 
    MOUSEION::BaseException{std::move(other)},
    errorMessage_{std::move(other.errorMessage_)}
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ErrorMissingSimulationWorkloadDecompositionParameters::ErrorMissingSimulationWorkloadDecompositionParameters  -----


ErrorMissingSimulationWorkloadDecompositionParameters::~ErrorMissingSimulationWorkloadDecompositionParameters()
{
    return;
}

//============================= ACCESSORS ====================================
const char* ErrorMissingSimulationWorkloadDecompositionParameters::what () const noexcept
{
    return this->errorMessage_.c_str();
}

ErrorMissingSimulationWorkloadDecompositionParameters * ErrorMissingSimulationWorkloadDecompositionParameters::clone() const
{
    return new ErrorMissingSimulationWorkloadDecompositionParameters(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorMissingSimulationWorkloadDecompositionParameters& ErrorMissingSimulationWorkloadDecompositionParameters::operator= ( const ErrorMissingSimulationWorkloadDecompositionParameters &other ) 
{
    if (this != &other)
    {
        MOUSEION::BaseException::operator=(other);
        this->errorMessage_ = other.errorMessage_;
    }
    return *this;
} // assignment operator

ErrorMissingSimulationWorkloadDecompositionParameters& ErrorMissingSimulationWorkloadDecompositionParameters::operator= ( ErrorMissingSimulationWorkloadDecompositionParameters && other )
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
