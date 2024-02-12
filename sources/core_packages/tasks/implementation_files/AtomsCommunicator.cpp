//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AtomsCommunicator.h"

namespace ANANSI 
{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AtomsCommunicator::AtomsCommunicator() :
    AnansiTask{}
{
    return;
}

AtomsCommunicator::AtomsCommunicator( AtomsCommunicator const & other) :
    AnansiTask{other}
{
    if (this != &other)
    {
        
    }
    return;
}

AtomsCommunicator::AtomsCommunicator( AtomsCommunicator && other) :
    AnansiTask{std::move(other)}
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method AtomsCommunicator::AtomsCommunicator  -----


AtomsCommunicator::~AtomsCommunicator()
{
    return;
}

//============================= ACCESSORS ====================================

AtomsCommunicator * AtomsCommunicator::clone() const
{
    return new AtomsCommunicator(*this);
}


//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

AtomsCommunicator& AtomsCommunicator::operator= ( const AtomsCommunicator &other )
{
    if (this != &other)
    {
        AnansiTask::operator=(other);
    }
    return *this;
} // assignment operator

AtomsCommunicator& AtomsCommunicator::operator= ( AtomsCommunicator && other )
{
    if (this != &other)
    {
        AnansiTask::operator=(std::move(other));
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


}; // ----- End of namespace ANANSI -----
