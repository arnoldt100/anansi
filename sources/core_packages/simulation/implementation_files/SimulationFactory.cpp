/*
 * =====================================================================================
 *
 *       Filename:  SimulationFactory.cpp
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */


#include "SimulationFactory.h"

namespace ANANSI
{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

/*
 *--------------------------------------------------------------------------------------
 *       Class:  SimulationFactory
 *      Method:  SimulationFactory
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
SimulationFactory::SimulationFactory()
{
    return;
}  /* -----  end of method SimulationFactory::SimulationFactory (constructor)  ----- */


/*
 *--------------------------------------------------------------------------------------
 *       Class:  SimulationFactory
 *      Method:  SimulationFactory :: ~SimulationFactory
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
SimulationFactory::~SimulationFactory()
{
    return;
}  /* -----  end of method SimulationFactory::~SimulationFactory (destructor)  ----- */

//============================= ACCESSORS ====================================
std::shared_ptr<Simulation> SimulationFactory::create_shared_ptr() const
{
    return this->create_shared_ptr_();
}

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

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace __NAMESPACE__ */