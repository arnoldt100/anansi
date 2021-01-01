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

void AnansiMDState::initializeSimulationEnvironment(MolecularDynamics* aMD, int const & argc, char const *const *const & argv ) const
{
    this->_initializeSimulationEnvironment(aMD,argc,argv);
}

void AnansiMDState::processCommandLine(MolecularDynamics* aMD, int const & argc, char const *const *const & argv ) const
{
    this->_processCommandLine(aMD,argc,argv);
}

//============================= MUTATORS =====================================

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
void AnansiMDState::_initializeSimulationEnvironment(MolecularDynamics * const aMD,int const & argc, char const *const *const & argv) const
{
    std::cout << "Error: This state can't 'initialize the simulation environment'.";
    return;
}

void AnansiMDState::_processCommandLine(MolecularDynamics * const aMD,int const & argc, char const *const *const & argv) const
{
    std::cout << "Error: This state can't 'process the command line environment'.";
    return;
}
//============================= OPERATORS ====================================


} /* namespace ANANSI */
