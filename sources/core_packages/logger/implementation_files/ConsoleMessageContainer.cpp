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
#include "ConsoleMessageContainer.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ConsoleMessageContainer::ConsoleMessageContainer() :
    message_(),
    sender_()
{
    return;
}


ConsoleMessageContainer::ConsoleMessageContainer(std::string const & message,
                                                 std::string const & sender) :
    message_(message),
    sender_(sender)
{
    return;
}


ConsoleMessageContainer::ConsoleMessageContainer( ConsoleMessageContainer const & other) :
    message_(other.message_),
    sender_(other.sender_)
{
    if (this != &other)
    {
    }
    return;
}

ConsoleMessageContainer::ConsoleMessageContainer( ConsoleMessageContainer && other) :
    message_(std::move(other.message_)),
    sender_(std::move(other.sender_))
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ConsoleMessageContainer::ConsoleMessageContainer  -----


ConsoleMessageContainer::~ConsoleMessageContainer()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ConsoleMessageContainer& ConsoleMessageContainer::operator= ( const ConsoleMessageContainer &other )
{
    if (this != &other)
    {
        this->message_ = other.message_;
        this->sender_ = other.sender_;
    }
    return *this;
} // assignment operator

ConsoleMessageContainer& ConsoleMessageContainer::operator= ( ConsoleMessageContainer && other )
{
    if (this != &other)
    {
        this->message_ = std::move(other.message_);
        this->sender_ = std::move(other.sender_);
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
