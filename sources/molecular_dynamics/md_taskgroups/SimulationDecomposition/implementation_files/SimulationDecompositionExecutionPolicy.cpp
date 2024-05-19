
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationDecompositionExecutionPolicy.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

SimulationDecompositionExecutionPolicy::SimulationDecompositionExecutionPolicy()
{
	// TODO Auto-generated constructor stub
    return;
}

SimulationDecompositionExecutionPolicy::SimulationDecompositionExecutionPolicy( SimulationDecompositionExecutionPolicy const & other)
{
	// TODO Auto-generated constructor stub
    if (this != &other)
    {
        
    }
    return;
}

SimulationDecompositionExecutionPolicy::SimulationDecompositionExecutionPolicy( SimulationDecompositionExecutionPolicy && other)
{
	// TODO Auto-generated constructor stub
    if (this != &other)
    {
    }
    return;
}		// -----  end of method SimulationDecompositionExecutionPolicy::SimulationDecompositionExecutionPolicy  -----


SimulationDecompositionExecutionPolicy::~SimulationDecompositionExecutionPolicy()
{
	// TODO Auto-generated destructor stub
    return;
}

//============================= ACCESSORS ====================================

SimulationDecompositionExecutionPolicy * SimulationDecompositionExecutionPolicy::clone() const
{
    return new SimulationDecompositionExecutionPolicy(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

SimulationDecompositionExecutionPolicy& SimulationDecompositionExecutionPolicy::operator= ( const SimulationDecompositionExecutionPolicy &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

SimulationDecompositionExecutionPolicy& SimulationDecompositionExecutionPolicy::operator= ( SimulationDecompositionExecutionPolicy && other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment-move operator

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


} // namespace ANANSI
