//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorInvalidWorkloadDecompositionType.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorInvalidWorkloadDecompositionType::ErrorInvalidWorkloadDecompositionType()
{
    return;
}

ErrorInvalidWorkloadDecompositionType::ErrorInvalidWorkloadDecompositionType( ErrorInvalidWorkloadDecompositionType const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

ErrorInvalidWorkloadDecompositionType::ErrorInvalidWorkloadDecompositionType( ErrorInvalidWorkloadDecompositionType && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ErrorInvalidWorkloadDecompositionType::ErrorInvalidWorkloadDecompositionType  -----


ErrorInvalidWorkloadDecompositionType::~ErrorInvalidWorkloadDecompositionType()
{
    return;
}

//============================= ACCESSORS ====================================

ErrorInvalidWorkloadDecompositionType * ErrorInvalidWorkloadDecompositionType::clone() const
{
    return new ErrorInvalidWorkloadDecompositionType(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorInvalidWorkloadDecompositionType& ErrorInvalidWorkloadDecompositionType::operator= ( const ErrorInvalidWorkloadDecompositionType &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

ErrorInvalidWorkloadDecompositionType& ErrorInvalidWorkloadDecompositionType::operator= ( ErrorInvalidWorkloadDecompositionType && other )
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
