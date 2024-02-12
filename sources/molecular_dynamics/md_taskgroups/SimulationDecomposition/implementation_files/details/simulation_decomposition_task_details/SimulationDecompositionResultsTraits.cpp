
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationDecompositionResultsTraits.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

SimulationDecompositionResultsTraits::SimulationDecompositionResultsTraits()
{
    return;
}

SimulationDecompositionResultsTraits::SimulationDecompositionResultsTraits( SimulationDecompositionResultsTraits const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

SimulationDecompositionResultsTraits::SimulationDecompositionResultsTraits( SimulationDecompositionResultsTraits && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method SimulationDecompositionResultsTraits::SimulationDecompositionResultsTraits  -----


SimulationDecompositionResultsTraits::~SimulationDecompositionResultsTraits()
{
    return;
}

//============================= ACCESSORS ====================================

SimulationDecompositionResultsTraits * SimulationDecompositionResultsTraits::clone() const
{
    return new SimulationDecompositionResultsTraits(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

SimulationDecompositionResultsTraits& SimulationDecompositionResultsTraits::operator= ( const SimulationDecompositionResultsTraits &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

SimulationDecompositionResultsTraits& SimulationDecompositionResultsTraits::operator= ( SimulationDecompositionResultsTraits && other )
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
