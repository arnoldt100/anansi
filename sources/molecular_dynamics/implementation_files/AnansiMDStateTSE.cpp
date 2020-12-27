#include "AnansiMDStateTSE.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMDStateTSE::AnansiMDStateTSE() :
    AnansiMDState()
{
    return;
}

AnansiMDStateTSE::AnansiMDStateTSE( AnansiMDStateTSE const & other) :
    AnansiMDState(other)
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method AnansiMDStateTSE::AnansiMDStateTSE  ----- */

AnansiMDStateTSE::AnansiMDStateTSE( AnansiMDStateTSE && other) :
    AnansiMDState(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method AnansiMDStateTSE::AnansiMDStateTSE  ----- */


AnansiMDStateTSE::~AnansiMDStateTSE()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

AnansiMDStateTSE& AnansiMDStateTSE::operator=( const AnansiMDStateTSE & other )
{
    if (this != &other)
    {
        AnansiMDState::operator=(other);
    }
    return *this;
} /* assignment operator */

AnansiMDStateTSE& AnansiMDStateTSE::operator= ( AnansiMDStateTSE && other )
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