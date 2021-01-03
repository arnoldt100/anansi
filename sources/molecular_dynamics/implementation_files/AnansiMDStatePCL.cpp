#include "AnansiMDStatePCL.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMDStatePCL::AnansiMDStatePCL() :
    AnansiMDState()
{
    return;
}

AnansiMDStatePCL::AnansiMDStatePCL( AnansiMDStatePCL const & other) :
    AnansiMDState(other)
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method AnansiMDStatePCL::AnansiMDStatePCL  ----- */

AnansiMDStatePCL::AnansiMDStatePCL( AnansiMDStatePCL && other) :
    AnansiMDState(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method AnansiMDStatePCL::AnansiMDStatePCL  ----- */


AnansiMDStatePCL::~AnansiMDStatePCL()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

AnansiMDStatePCL& AnansiMDStatePCL::operator=( const AnansiMDStatePCL & other )
{
    if (this != &other)
    {
        AnansiMDState::operator=(other);
    }
    return *this;
} /* assignment operator */

AnansiMDStatePCL& AnansiMDStatePCL::operator= ( AnansiMDStatePCL && other )
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
void AnansiMDStatePCL::_processCommandLine(MolecularDynamics * const aMD, int const & argc, char const *const *const & argv ) const
{
    // Execute commands to process command line arguments, and store the
    // simulation parameters.

    // :TODO:01/02/2021 01:43:01 PM:: Store the command line arguments.

    // :TODO:01/02/2021 01:43:58 PM:: Store the simulation parameters.

    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace ANANSI */
