
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CPUCentricStoragePolicy.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CPUCentricStoragePolicy::CPUCentricStoragePolicy()
{
    return;
}

CPUCentricStoragePolicy::CPUCentricStoragePolicy( CPUCentricStoragePolicy const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

CPUCentricStoragePolicy::CPUCentricStoragePolicy( CPUCentricStoragePolicy && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method CPUCentricStoragePolicy::CPUCentricStoragePolicy  -----


CPUCentricStoragePolicy::~CPUCentricStoragePolicy()
{
    return;
}

//============================= ACCESSORS ====================================

CPUCentricStoragePolicy * CPUCentricStoragePolicy::clone() const
{
    return new CPUCentricStoragePolicy(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CPUCentricStoragePolicy& CPUCentricStoragePolicy::operator= ( const CPUCentricStoragePolicy &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

CPUCentricStoragePolicy& CPUCentricStoragePolicy::operator= ( CPUCentricStoragePolicy && other )
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
