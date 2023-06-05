#ifndef RECEIVERConcreteReceiverConstraints_INC
#define RECEIVERConcreteReceiverConstraints_INC
//! @file ConcreteReceiverConstraints.hpp
//!
//! This header is part of the receiver library.
//!
//! Classes:
//! --------
//! - ConcreteReceiverConstraints 

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <concepts>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiTask.h"
#include "TaskLabel.hpp"



namespace RECEIVER
{

//! The concept for concrete receiever classes derived from  class ReceiverInterface.
//!
//! The ConcreteReceiverConstraints concept requires the following of
//! the class ConcreteReceiver_t:
//! - The class is default default initializable
//! - The class is move move constructible
//! - Has member MyComponentReceiverTypelist
//! - Has member receiver_result_t
//! - Has member MyParentTask
//! \tparam  ConcreteReceiver_t The type of the concrete receiver.
template <typename ConcreteReceiver_t>
concept ConcreteReceiverConstraints = requires (ConcreteReceiver_t x)
{
    requires (std::default_initializable<ConcreteReceiver_t>);
    requires (std::move_constructible<ConcreteReceiver_t>);
    {x.TASKLABEL}->std::same_as<const ANANSI::TaskLabel &>;
    typename ConcreteReceiver_t::MyComponentReceiverTypelist; 
    typename ConcreteReceiver_t::receiver_result_t;
    typename ConcreteReceiver_t::MyParentTask; 
}; 


}; // namespace RECEIVER

#endif // RECEIVERConcreteReceiverConstraints_INC
