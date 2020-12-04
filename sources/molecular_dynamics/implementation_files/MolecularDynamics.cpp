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

void
MolecularDynamics::initializeSimulation(int const argc, char const *const *const & argv )
{
    // Store command line arguments in class CommandLineArguments.
    this->_initializeSimulation(argc, argv);
    return;
}       /* -----  end of method MolecularDynamics::initializeSimulation  ----- */

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
