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
#include "ControlFileMPICommReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileMPICommReceiver::ControlFileMPICommReceiver() :
    ReceiverInterface<ControlFileMPICommReceiver>()
{
    return;
}

ControlFileMPICommReceiver::ControlFileMPICommReceiver( ControlFileMPICommReceiver const & other) :
    ReceiverInterface<ControlFileMPICommReceiver>(other)
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileMPICommReceiver::ControlFileMPICommReceiver( ControlFileMPICommReceiver && other) :
    ReceiverInterface<ControlFileMPICommReceiver>(std::move(other))
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileMPICommReceiver::~ControlFileMPICommReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileMPICommReceiver& ControlFileMPICommReceiver::operator= ( const ControlFileMPICommReceiver &other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileMPICommReceiver>::operator=(other);

    }
    return *this;
} // assignment operator

ControlFileMPICommReceiver& ControlFileMPICommReceiver::operator= ( ControlFileMPICommReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileMPICommReceiver>::operator=(std::move(other));
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
