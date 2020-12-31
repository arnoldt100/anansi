#include "AnansiMDState.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiMDState::AnansiMDState()
{
    return;
} /* -----  end of method AnansiMDState::AnansiMDState  ----- */

AnansiMDState::AnansiMDState( AnansiMDState const & other)
{
    if (this != &other)
    {

    }
    return;
} /* -----  end of method AnansiMDState::AnansiMDState  ----- */

AnansiMDState::AnansiMDState( AnansiMDState && other)
{
    if (this != &other)
    {

    }
    return;
} /* -----  end of method AnansiMDState::AnansiMDState  ----- */


AnansiMDState::~AnansiMDState()
{
    return;
} /* -----  end of method AnansiMDState::~AnansiMDState  ----- */

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void AnansiMDState::initializeSimulationEnvironment(MolecularDynamics* aMD, int const argc, char const *const *const & argv )
{
    this->_initializeSimulationEnvironment(aMD,argc,argv);
}

//============================= OPERATORS ====================================

AnansiMDState& AnansiMDState::operator=( const AnansiMDState &other )
{
    if (this != &other)
    {

    }
    return *this;
} /* end of assignment operator */

AnansiMDState& AnansiMDState::operator=( AnansiMDState && other )
{
    if (this != &other)
    {

    }
    return *this;
} /* end of assignment-move operator */

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
void AnansiMDState::_initializeSimulationEnvironment(MolecularDynamics* aMD,int const argc, char const *const *const & argv)
{
    std::cout << "Error: This state can't initialize the simulation Environment.";
    return;
}

//============================= OPERATORS ====================================


} /* namespace ANANSI */
