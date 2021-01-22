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
#include "AnansiMolecularDynamics.h"
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
void AnansiMDStatePCL::_processCommandLine(MolecularDynamics * const aMD) const
{
    // Execute commands to store the simulation parameters.
    aMD->saveSimulationParameters();

    // If help was processed on the command line, then change state to terminate
    // simulation environment so as to not do any more of the MD algorithm. One
    // simply wants to orderly terminate the simulation.
    auto my_status = RegistryAnansiMDStatus::Undefined;
    if (aMD->isHelpOnCommandLine())
    {
        my_status = RegistryAnansiMDStatus::TerminatingSimulationEnvironmentInProgress;
    }
    else
    {
        my_status = RegistryAnansiMDStatus::ProcessingCommandLineSuccessful;
    }
    aMD->setStatus(my_status);
    return;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace ANANSI */
