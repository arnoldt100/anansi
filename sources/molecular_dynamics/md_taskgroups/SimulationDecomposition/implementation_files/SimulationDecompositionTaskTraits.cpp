
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationDecompositionTaskTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

SimulationDecompositionTaskTraits::SimulationDecompositionTaskTraits()
{
	// TODO Auto-generated constructor stub
    return;
}

SimulationDecompositionTaskTraits::SimulationDecompositionTaskTraits( SimulationDecompositionTaskTraits const & other)
{
	// TODO Auto-generated constructor stub
    if (this != &other)
    {
        
    }
    return;
}

SimulationDecompositionTaskTraits::SimulationDecompositionTaskTraits( SimulationDecompositionTaskTraits && other)
{
	// TODO Auto-generated constructor stub
    if (this != &other)
    {
    }
    return;
}		// -----  end of method SimulationDecompositionTaskTraits::SimulationDecompositionTaskTraits  -----


SimulationDecompositionTaskTraits::~SimulationDecompositionTaskTraits()
{
	// TODO Auto-generated destructor stub
    return;
}

//============================= ACCESSORS ====================================

SimulationDecompositionTaskTraits * SimulationDecompositionTaskTraits::clone() const
{
    return new SimulationDecompositionTaskTraits(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

SimulationDecompositionTaskTraits& SimulationDecompositionTaskTraits::operator= ( const SimulationDecompositionTaskTraits &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

SimulationDecompositionTaskTraits& SimulationDecompositionTaskTraits::operator= ( SimulationDecompositionTaskTraits && other )
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
