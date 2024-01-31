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

ErrorInvalidSimulationWorkloadDecompositionType::ErrorInvalidSimulationWorkloadDecompositionType()
{
    return;
}

ErrorInvalidSimulationWorkloadDecompositionType::ErrorInvalidSimulationWorkloadDecompositionType( ErrorInvalidSimulationWorkloadDecompositionType const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

ErrorInvalidSimulationWorkloadDecompositionType::ErrorInvalidSimulationWorkloadDecompositionType( ErrorInvalidSimulationWorkloadDecompositionType && other)
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
    }
    return *this;
} // assignment operator

ErrorInvalidSimulationWorkloadDecompositionType& ErrorInvalidSimulationWorkloadDecompositionType::operator= ( ErrorInvalidSimulationWorkloadDecompositionType && other )
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
