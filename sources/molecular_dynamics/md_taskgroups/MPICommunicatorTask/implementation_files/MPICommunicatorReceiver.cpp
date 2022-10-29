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
#include "MPICommunicatorReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPICommunicatorReceiver::MPICommunicatorReceiver() :
    ReceiverInterface<MPICommunicatorReceiver>()
{
    return;
}

MPICommunicatorReceiver::MPICommunicatorReceiver( MPICommunicatorReceiver const & other) :
    ReceiverInterface<MPICommunicatorReceiver>(other)
{
    if (this != &other)
    {
        
    }
    return;
}

MPICommunicatorReceiver::MPICommunicatorReceiver( MPICommunicatorReceiver && other) :
    ReceiverInterface<MPICommunicatorReceiver>(std::move(other))
{
    if (this != &other)
    {
        
    }
    return;
}

MPICommunicatorReceiver::~MPICommunicatorReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MPICommunicatorReceiver& MPICommunicatorReceiver::operator= ( const MPICommunicatorReceiver &other )
{
    if (this != &other)
    {
        ReceiverInterface<MPICommunicatorReceiver>::operator=(other);

    }
    return *this;
} // assignment operator

MPICommunicatorReceiver& MPICommunicatorReceiver::operator= ( MPICommunicatorReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<MPICommunicatorReceiver>::operator=(std::move(other));
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
