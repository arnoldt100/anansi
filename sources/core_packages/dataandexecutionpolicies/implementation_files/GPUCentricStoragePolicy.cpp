
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "GPUCentricStoragePolicy.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

GPUCentricStoragePolicy::GPUCentricStoragePolicy()
{
    return;
}

GPUCentricStoragePolicy::GPUCentricStoragePolicy( GPUCentricStoragePolicy const & other)
{
    if (this != &other)
    {
    }
    return;
}

GPUCentricStoragePolicy::GPUCentricStoragePolicy( GPUCentricStoragePolicy && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method GPUCentricStoragePolicy::GPUCentricStoragePolicy  -----


GPUCentricStoragePolicy::~GPUCentricStoragePolicy()
{
    return;
}

//============================= ACCESSORS ====================================

GPUCentricStoragePolicy * GPUCentricStoragePolicy::clone() const
{
    return new GPUCentricStoragePolicy(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

GPUCentricStoragePolicy& GPUCentricStoragePolicy::operator= ( const GPUCentricStoragePolicy &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

GPUCentricStoragePolicy& GPUCentricStoragePolicy::operator= ( GPUCentricStoragePolicy && other )
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
