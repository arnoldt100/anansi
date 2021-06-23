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

void
AnansiMDStateIIC::_initializeInitialConditions (MolecularDynamics * const aMD) const
{
	aMD->inputSimulationControlFile();

	// If the status of the molecular dynamics simulation is good, then proceed
	// to the next step of reading in the atomic coordinates of the simulation.
	if (aMD->isIICStatusOkay())
	{

	}

    return;
}		// -----  end of method AnansiMDStateIIC::_initializeInitialConditions  -----

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
