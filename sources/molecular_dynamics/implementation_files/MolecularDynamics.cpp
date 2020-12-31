/*
 * MolecularDynamics.cpp
 */

#include "MolecularDynamics.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================


/*
 *--------------------------------------------------------------------------------------
 *       Class:  MolecularDynamics
 *      Method:  MolecularDynamics
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
MolecularDynamics::MolecularDynamics()
{
    return;
}  /* -----  end of method MolecularDynamics::MolecularDynamics  (constructor)  ----- */


/*--------------------------------------------------------------------------------------
 *       Class:  MolecularDynamics
 *      Method:  MolecularDynamics
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
MolecularDynamics::~MolecularDynamics()
{
    return ;
}		/* -----  end of method MolecularDynamics::~MolecularDynamics  ----- */

//============================= ACCESSORS ====================================

void MolecularDynamics::stud_function() const
{
    std::cout << "Doing stud function";
}

//============================= MUTATORS =====================================

void MolecularDynamics::doSimulation()
{
    this->_doSimulation();
    return;
}       /* -----  end of method MolecularDynamics::doSimulation  ----- */

void
MolecularDynamics::enableCommunication ()
{
    this->_enableCommunication();
    return ;
}		/* -----  end of method MolecularDynamics::enableCommunication  ----- */

void
MolecularDynamics::disableCommunication()
{
    this->_disableCommunication();
    return ;
}		/* -----  end of method MolecularDynamics::disableCommunication  ----- */


void MolecularDynamics::initializeSimulationEnvironment( int const & argc, char const *const *const & argv )
{
	this->_initializeSimulationEnvironment(argc,argv);
    return;
}

void MolecularDynamics::initializeMpiEnvironment(int const & argc, char const *const *const & argv)
{
    this->_initializeMpiEnvironment(argc,argv);
    return;
}


void MolecularDynamics::processCommandLine( int const argc, char const *const *const & argv ) 
{
    this->_processCommandLine(argc,argv);
    return;
}

void
MolecularDynamics::setMDState(std::unique_ptr<AnansiMDState> && a_AnansiMDState)
{
    this->_setMDState(std::move(a_AnansiMDState));
	return;
}
//============================= OPERATORS ====================================

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
