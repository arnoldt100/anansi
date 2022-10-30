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
#include "ControlFileMPIXMLReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileMPIXMLReceiver::ControlFileMPIXMLReceiver() :
    ReceiverInterface<ControlFileMPIXMLReceiver>()
{
    return;
}

ControlFileMPIXMLReceiver::ControlFileMPIXMLReceiver( ControlFileMPIXMLReceiver const & other) :
    ReceiverInterface<ControlFileMPIXMLReceiver>(other)
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileMPIXMLReceiver::ControlFileMPIXMLReceiver( ControlFileMPIXMLReceiver && other) :
    ReceiverInterface<ControlFileMPIXMLReceiver>(std::move(other))
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileMPIXMLReceiver::~ControlFileMPIXMLReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileMPIXMLReceiver& ControlFileMPIXMLReceiver::operator= ( const ControlFileMPIXMLReceiver &other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileMPIXMLReceiver>::operator=(other);

    }
    return *this;
} // assignment operator

ControlFileMPIXMLReceiver& ControlFileMPIXMLReceiver::operator= ( ControlFileMPIXMLReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileMPIXMLReceiver>::operator=(std::move(other));
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
