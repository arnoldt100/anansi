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
    ReceiverInterface<ControlFileXMLReceiver>(),
    results_(0),
    controlFileName_(""),
    commID_(-1)
{
    return;
}

ControlFileXMLReceiver::ControlFileXMLReceiver( ControlFileXMLReceiver const & other) :
    ReceiverInterface<ControlFileXMLReceiver>(other),
    results_(other.results_),
    controlFileName_(other.controlFileName_),
    commID_(other.commID_)
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileXMLReceiver::ControlFileXMLReceiver( ControlFileXMLReceiver && other) :
    ReceiverInterface<ControlFileXMLReceiver>(std::move(other)),
    results_(std::move(other.results_)),
    controlFileName_(std::move(other.controlFileName_)),
    commID_(std::move(other.commID_))
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

std::unique_ptr<ControlFileXMLReceiver::receiver_result_t> ControlFileXMLReceiver::receiverGetCopyOfResults() const
{
    std::unique_ptr<ControlFileXMLReceiver::receiver_result_t> my_ptr =
        std::make_unique<ControlFileXMLReceiver::receiver_result_t>(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

template<>
void ControlFileXMLReceiver::enableReceiver(std::string & arg)
{
    this->controlFileName_ = arg;
}
//============================= OPERATORS ====================================

ControlFileXMLReceiver& ControlFileXMLReceiver::operator= ( const ControlFileXMLReceiver &other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileXMLReceiver>::operator=(other);
        this->controlFileName_ = other.controlFileName_;
        this->commID_ = other.commID_;
    }
    return *this;
} // assignment operator

ControlFileXMLReceiver& ControlFileXMLReceiver::operator= ( ControlFileXMLReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileXMLReceiver>::operator=(std::move(other));
        this->controlFileName_ = std::move(other.controlFileName_);
        this->commID_ = std::move(other.commID_);
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
