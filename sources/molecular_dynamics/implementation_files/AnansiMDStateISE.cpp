//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiMolecularDynamics.h"
#include "AnansiMDStateISE.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMDStateISE::AnansiMDStateISE() :
    AnansiMDState()
{
    return;
}

AnansiMDStateISE::AnansiMDStateISE( AnansiMDStateISE const & other) :
    AnansiMDState(other)
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method AnansiMDStateISE::AnansiMDStateISE  ----- */

AnansiMDStateISE::AnansiMDStateISE( AnansiMDStateISE && other) :
    AnansiMDState(std::move(other))
{
    if (this != &other)
    {

    }
    return;
}		/* -----  end of method AnansiMDStateISE::AnansiMDStateISE  ----- */


AnansiMDStateISE::~AnansiMDStateISE()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

AnansiMDStateISE& AnansiMDStateISE::operator=( const AnansiMDStateISE & other )
{
    if (this != &other)
    {
        AnansiMDState::operator=(other);
    }
    return *this;
} /* assignment operator */

AnansiMDStateISE& AnansiMDStateISE::operator= ( AnansiMDStateISE && other )
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
void AnansiMDStateISE::_initializeSimulationEnvironment(MolecularDynamics* aMD,int const argc, char const *const *const & argv)
{
    // Initialize the MPI environment.
    aMD->initializeMpiEnvironment(argc,argv);

    // Enable MPI Communication for the aMD object.
    aMD->enableCommunication();

    std::cout << "This state initialized the simulation Environment.";
    return;
}

//============================= OPERATORS ====================================


} /* namespace ANANSI */
