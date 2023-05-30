#ifndef RECEIVERConcreteReceiverConstraints_INC
#define RECEIVERConcreteReceiverConstraints_INC
//! @file ConcreteReceiverConstraints.hpp

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

namespace RECEIVER
{

template <typename ConcreteReceiver_t>
concept ConcreteReceiverConstraints = requires  (ConcreteReceiver_t x)
{
    typename ConcreteReceiver_t::MyComponentReceiverTypelist; 
    typename ConcreteReceiver_t::receiver_result_t;
    typename ConcreteReceiver_t::MyParentTask; 
}; 


}; // namespace RECEIVER

#endif // RECEIVERConcreteReceiverConstraints_INC
