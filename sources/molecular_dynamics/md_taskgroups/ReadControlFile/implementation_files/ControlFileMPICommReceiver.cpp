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
    ReceiverInterface<ControlFileMPICommReceiver>(),
    results_(0)
{
    return;
}

ControlFileMPICommReceiver::ControlFileMPICommReceiver( ControlFileMPICommReceiver && other) :
    ReceiverInterface<ControlFileMPICommReceiver>(std::move(other)),
    results_(std::move(other.results_))
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

std::unique_ptr<ControlFileMPICommReceiver::receiver_result_t> ControlFileMPICommReceiver::receiverGetCopyOfResults() const
{
    std::unique_ptr<ControlFileMPICommReceiver::receiver_result_t> my_ptr =
        std::make_unique<ControlFileMPICommReceiver::receiver_result_t>(this->results_);
    return my_ptr;
}

//============================= MUTATORS =====================================

template<>
void ControlFileMPICommReceiver::enableReceiver(int & alpha)
{
    return;
}

template<>
void ControlFileMPICommReceiver::receiverModifyMyself(int & alpha)
{
    return;
}



//============================= OPERATORS ====================================

ControlFileMPICommReceiver& ControlFileMPICommReceiver::operator= ( ControlFileMPICommReceiver && other )
{
    if (this != &other)
    {
        ReceiverInterface<ControlFileMPICommReceiver>::operator=(std::move(other));
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
