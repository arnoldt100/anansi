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
    MEMORY_MANAGEMENT::Pointer<AnansiMolecularDynamics> my_pointer;

    AnansiMolecularDynamics* my_md = my_pointer.createPointer();

    return my_md;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


}; /* -----  end of namespace ANANSI  ----- */
