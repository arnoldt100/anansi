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
#include "ControlFileXMLReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileXMLReceiver::ControlFileXMLReceiver() :
    ReceiverInterface<ControlFileXMLReceiver>()
{
    return;
}

ControlFileXMLReceiver::ControlFileXMLReceiver( ControlFileXMLReceiver const & other) :
    ReceiverInterface<ControlFileXMLReceiver>(other)
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileXMLReceiver::ControlFileXMLReceiver( ControlFileXMLReceiver && other) :
    ReceiverInterface<ControlFileXMLReceiver>(std::move(other))
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileXMLReceiver::~ControlFileXMLReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileXMLReceiver& ControlFileXMLReceiver::operator= ( const ControlFileXMLReceiver &other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileXMLReceiver>::operator=(other);

    }
    return *this;
} // assignment operator

ControlFileXMLReceiver& ControlFileXMLReceiver::operator= ( ControlFileXMLReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileXMLReceiver>::operator=(std::move(other));
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
