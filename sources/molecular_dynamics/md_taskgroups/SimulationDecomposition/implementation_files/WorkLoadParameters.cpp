//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "WorkLoadParameters.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

WorkLoadParameters::WorkLoadParameters()
{
    return;
}

WorkLoadParameters::WorkLoadParameters(std::unique_ptr<COMMUNICATOR::Communicator> world_communicator)
{
    return;
}

WorkLoadParameters::WorkLoadParameters( WorkLoadParameters const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

WorkLoadParameters::WorkLoadParameters( WorkLoadParameters && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method WorkLoadParameters::WorkLoadParameters  -----


WorkLoadParameters::~WorkLoadParameters()
{
    return;
}

//============================= ACCESSORS ====================================

WorkLoadParameters * WorkLoadParameters::clone() const
{
    return new WorkLoadParameters(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

WorkLoadParameters& WorkLoadParameters::operator= ( const WorkLoadParameters &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

WorkLoadParameters& WorkLoadParameters::operator= ( WorkLoadParameters && other )
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
