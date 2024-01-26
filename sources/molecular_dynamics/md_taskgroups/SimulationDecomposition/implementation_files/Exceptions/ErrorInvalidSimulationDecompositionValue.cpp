
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
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

ErrorInvalidSimulationDecompositionValue::ErrorInvalidSimulationDecompositionValue()
{
    return;
}

ErrorInvalidSimulationDecompositionValue::ErrorInvalidSimulationDecompositionValue( ErrorInvalidSimulationDecompositionValue const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

ErrorInvalidSimulationDecompositionValue::ErrorInvalidSimulationDecompositionValue( ErrorInvalidSimulationDecompositionValue && other)
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
    std::string message{"Stud message for invalid Simulation decomposition value."};
    return message.c_str();
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
    }
    return *this;
} // assignment operator

ErrorInvalidSimulationDecompositionValue& ErrorInvalidSimulationDecompositionValue::operator=( ErrorInvalidSimulationDecompositionValue && other )
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
