
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationDecompositionPrecisionPolicy.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

SimulationDecompositionPrecisionPolicy::SimulationDecompositionPrecisionPolicy()
{
	// TODO Auto-generated constructor stub
    return;
}

SimulationDecompositionPrecisionPolicy::SimulationDecompositionPrecisionPolicy( SimulationDecompositionPrecisionPolicy const & other)
{
	// TODO Auto-generated constructor stub
    if (this != &other)
    {
        
    }
    return;
}

SimulationDecompositionPrecisionPolicy::SimulationDecompositionPrecisionPolicy( SimulationDecompositionPrecisionPolicy && other)
{
	// TODO Auto-generated constructor stub
    if (this != &other)
    {
    }
    return;
}		// -----  end of method SimulationDecompositionPrecisionPolicy::SimulationDecompositionPrecisionPolicy  -----


SimulationDecompositionPrecisionPolicy::~SimulationDecompositionPrecisionPolicy()
{
	// TODO Auto-generated destructor stub
    return;
}

//============================= ACCESSORS ====================================

SimulationDecompositionPrecisionPolicy * SimulationDecompositionPrecisionPolicy::clone() const
{
    return new SimulationDecompositionPrecisionPolicy(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

SimulationDecompositionPrecisionPolicy& SimulationDecompositionPrecisionPolicy::operator= ( const SimulationDecompositionPrecisionPolicy &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

SimulationDecompositionPrecisionPolicy& SimulationDecompositionPrecisionPolicy::operator= ( SimulationDecompositionPrecisionPolicy && other )
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
