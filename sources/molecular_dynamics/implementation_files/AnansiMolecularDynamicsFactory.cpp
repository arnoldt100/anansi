/*
 * =====================================================================================
 *
 *       Filename:  AnansiMolecularDynamicsFactory.cpp
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#include "AnansiMolecularDynamicsFactory.h"

namespace ANANSI
{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

/*
 *--------------------------------------------------------------------------------------
 *       Class:  AnansiMolecularDynamicsFactory
 *      Method:  AnansiMolecularDynamicsFactory
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
AnansiMolecularDynamicsFactory::AnansiMolecularDynamicsFactory() :
    MolecularDynamicsFactory()
{
    return;
}  /* -----  end of method AnansiMolecularDynamicsFactory::AnansiMolecularDynamicsFactory  (constructor)  ----- */


/*
 *--------------------------------------------------------------------------------------
 *       Class:  AnansiMolecularDynamicsFactory
 *      Method:  ~AnansiMolecularDynamicsFactory
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
AnansiMolecularDynamicsFactory::~AnansiMolecularDynamicsFactory ()
{
    return;
}  /* -----  end of method AnansiMolecularDynamicsFactory::~AnansiMolecularDynamicsFactory  (destructor)  ----- */


//============================= ACCESSORS ====================================



//============================= MUTATORS =====================================

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

MolecularDynamics* AnansiMolecularDynamicsFactory::_create() 
{
    // Instantiate a pointer to the AnansiMolecularDynamics.
    MEMORY_MANAGEMENT::Pointer<AnansiMolecularDynamics> md_pointer_factory;
    AnansiMolecularDynamics* my_md = md_pointer_factory.createPointer();

    // Enable core fuctionality of the AnansiMolecularDynamics object.
    my_md->enableCommunication();

    return my_md;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


}; /* -----  end of namespace ANANSI  ----- */
