
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MasterControlInputFileParameters.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MasterControlInputFileParameters::MasterControlInputFileParameters()
{
    return;
}

MasterControlInputFileParameters::MasterControlInputFileParameters( MasterControlInputFileParameters const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

MasterControlInputFileParameters::MasterControlInputFileParameters( MasterControlInputFileParameters && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method MasterControlInputFileParameters::MasterControlInputFileParameters  -----


MasterControlInputFileParameters::~MasterControlInputFileParameters()
{
    return;
}

//============================= ACCESSORS ====================================

MasterControlInputFileParameters * MasterControlInputFileParameters::clone() const
{
    return new MasterControlInputFileParameters(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//============================= STATIC    ====================================
SimulationDecompositionParameters MasterControlInputFileParameters::GetSimulationDecompositionParameters()
{
    SimulationDecompositionParameters sim_decomposition_parameters;
    return sim_decomposition_parameters;
}

MasterControlInputFileParameters& MasterControlInputFileParameters::operator= ( const MasterControlInputFileParameters &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

MasterControlInputFileParameters& MasterControlInputFileParameters::operator= ( MasterControlInputFileParameters && other )
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
