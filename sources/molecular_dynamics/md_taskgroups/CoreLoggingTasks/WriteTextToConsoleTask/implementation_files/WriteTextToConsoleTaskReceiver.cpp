
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "WriteTextToConsoleTaskReceiver.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

WriteTextToConsoleTaskReceiver::WriteTextToConsoleTaskReceiver() :
    RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>()
{
    return;
}

WriteTextToConsoleTaskReceiver::WriteTextToConsoleTaskReceiver( WriteTextToConsoleTaskReceiver const & other) :
    RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>(other)
{
    if (this != &other)
    {
        
    }
    return;
}

WriteTextToConsoleTaskReceiver::WriteTextToConsoleTaskReceiver( WriteTextToConsoleTaskReceiver && other) : 
    RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>(std::move(other))
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method WriteTextToConsoleTaskReceiver::WriteTextToConsoleTaskReceiver  -----


WriteTextToConsoleTaskReceiver::~WriteTextToConsoleTaskReceiver()
{
    return;
}

//============================= ACCESSORS ====================================

RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::TASK_LABEL_TYPE WriteTextToConsoleTaskReceiver::receiverGetTaskLabel() const
{
    return  WriteTextToConsoleTaskReceiver::TASKLABEL;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

WriteTextToConsoleTaskReceiver& WriteTextToConsoleTaskReceiver::operator=( const WriteTextToConsoleTaskReceiver &other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::operator=(other);
    }
    return *this;
} // assignment operator

WriteTextToConsoleTaskReceiver& WriteTextToConsoleTaskReceiver::operator=( WriteTextToConsoleTaskReceiver && other )
{
    if (this != &other)
    {
        RECEIVER::ReceiverInterface<WriteTextToConsoleTaskReceiver>::operator=(std::move(other));
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
template<>
void WriteTextToConsoleTaskReceiver::enableReceiver()
{
    return;
}

//============================= OPERATORS ====================================


} // namespace ANANSI
