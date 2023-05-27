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

namespace RECEIVER
{

template <typename ConcreteReceiver_t>
concept ConcreteReceiverConstraints = requires
{
    //! The concrete receciver parent task.
    typename ConcreteReceiver_t::MyParentTask;
}; 


}; // namespace RECEIVER

#endif // RECEIVERConcreteReceiverConstraints_INC
