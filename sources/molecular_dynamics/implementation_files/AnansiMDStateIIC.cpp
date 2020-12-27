#include "AnansiMDStateIIC.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMDStateIIC::AnansiMDStateIIC() :
    AnansiMDState()
{
    return;
}

AnansiMDStateIIC::AnansiMDStateIIC( AnansiMDStateIIC const & other) :
    AnansiMDState(other)
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method AnansiMDStateIIC::AnansiMDStateIIC  ----- */

AnansiMDStateIIC::AnansiMDStateIIC( AnansiMDStateIIC && other) :
    AnansiMDState(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method AnansiMDStateIIC::AnansiMDStateIIC  ----- */


AnansiMDStateIIC::~AnansiMDStateIIC()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

AnansiMDStateIIC& AnansiMDStateIIC::operator=( const AnansiMDStateIIC & other )
{
    if (this != &other)
    {
        AnansiMDState::operator=(other);
    }
    return *this;
} /* assignment operator */

AnansiMDStateIIC& AnansiMDStateIIC::operator= ( AnansiMDStateIIC && other )
{
    if (this != &other)
    {
        AnansiMDState::operator=(std::move(other));
    }
    return *this;
} /* assignment-move operator */

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


} /* namespace ANANSI */