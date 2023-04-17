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
#include "ControlFileXMLMPICommReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileXMLMPICommReceiver::ControlFileXMLMPICommReceiver() :
    ReceiverInterface<ControlFileXMLMPICommReceiver>(),
    results_()
{
    return;
}

ControlFileXMLMPICommReceiver::ControlFileXMLMPICommReceiver( ControlFileXMLMPICommReceiver && other) :
    ReceiverInterface<ControlFileXMLMPICommReceiver>(std::move(other)),
    results_(other.results_)
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileXMLMPICommReceiver::~ControlFileXMLMPICommReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

std::unique_ptr<ControlFileXMLMPICommReceiver::receiver_result_t> ControlFileXMLMPICommReceiver::receiverGetCopyOfResults() const
{
    std::unique_ptr<ControlFileXMLMPICommReceiver::receiver_result_t> my_ptr =
        std::make_unique<ControlFileXMLMPICommReceiver::receiver_result_t>(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFileXMLMPICommReceiver& ControlFileXMLMPICommReceiver::operator= ( ControlFileXMLMPICommReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileXMLMPICommReceiver>::operator=(std::move(other));
        this->results_ = std::move(other.results_);
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
