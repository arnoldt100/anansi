#ifndef RECEIVER_BaseReceiverResultOwnershipPolicy_INC
#define RECEIVER_BaseReceiverResultOwnershipPolicy_INC

//! @file BaseReceiverResultOwnershipPolicy.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "OwnershipTypeRequirements.hpp"

namespace RECEIVER {

//! The interface class for the class policies that copy, share, and transfer of
//! the receiver's result.
//!
//! This class uses the CRTP design pattern for implementing the interface of
//! the receiver's result ownership policies. The derived class is
//! ConcreteResultOwnershipPolicy sets policies 
//! which controls if one can copy, share, or transfer the results.
//!
//! The template parameter ConcrteResultOwnershipImpl defines the the implementation
//! details of copying, sharing, and transferring results.
//!
template <typename RT,
          typename ConcreteResultOwnershipPolicy,
          template <typename> typename ConcreteResultOwnershipImpl  
         >
class BaseReceiverResultOwnershipPolicy {
public:
  // ====================  LIFECYCLE     =======================================

  using copy_type = typename ConcreteResultOwnershipImpl<RT>::Copytype;
  using shared_type = typename ConcreteResultOwnershipImpl<RT>::Sharedtype;
  using transfer_type = typename ConcreteResultOwnershipImpl<RT>::Transfertype;

  BaseReceiverResultOwnershipPolicy(
      const BaseReceiverResultOwnershipPolicy &other) // copy constructor
  {
    if (this != &other) {
    }
    return;
  }

  BaseReceiverResultOwnershipPolicy(
      BaseReceiverResultOwnershipPolicy &&other) // copy-move constructor
  {
    if (this != &other) {
    }
    return;
  } // -----  end of method
    // BaseReceiverResultOwnershipPolicy::BaseReceiverResultOwnershipPolicy  -----

  virtual ~BaseReceiverResultOwnershipPolicy() = 0; // destructor

  // ====================  ACCESSORS     =======================================

  //! The copy interface definition for a copy_type receiver's result.
  //!
  //! The underlying object in a_receiver_result is to be copied.
  //!
  //! @param[in] a_receiver_result The receiver result to be copied.
  //! @return A copy_type obtained by copying the underlying object in
  //! a_receiver_result.
  template <typename W>
  copy_type copyReceiverResult(W const &a_receiver_result) const {
    return asDerived_().copyResult(a_receiver_result);
  }

  // ====================  MUTATORS      =======================================

  //! The transfer ownership interface definition for a trasfer_type receiver's
  //! result.
  //!
  //! @param[in] a_receiver_result The receiver result to trasnfer ownership.
  //! @return A transfer_type obtained by transferring ownership of the
  //! underlying object in a_receiver_result.
  template <typename W>
  transfer_type transferOwnershipOfReceiverResult(W &a_receiver_result) {
    return asDerived_().transferOwnershipOfResult(a_receiver_result);
  }

  //! The share ownership interface definition for a shared_type receiver's
  //! result.
  //!
  //! @param[in] a_receiver_result The receiver result to share ownership.
  //! @return A shared_type obtained by transferring ownership of the underlying
  //! object in a_receiver_result.
  template <typename W>
  shared_type shareOwnershipOfReceiverResult(W &a_receiver_result) {
    return asDerived_().shareOwnershipOfResult(a_receiver_result);
  }

  // ====================  OPERATORS     =======================================

  BaseReceiverResultOwnershipPolicy &
  operator=(const BaseReceiverResultOwnershipPolicy &other) // assignment operator
  {
    if (this != &other) {
    }
    return *this;
  }

  BaseReceiverResultOwnershipPolicy &
  operator=(BaseReceiverResultOwnershipPolicy &&other) // assignment-move operator
  {
    if (this != &other) {
    }
    return *this;
  }

protected:
  // ====================  METHODS       =======================================

  // ====================  DATA MEMBERS  =======================================

private:
  //! The following ensures that the CRTP doesn't use the wrong class.
  //!
  //! Only friends of this class can invoke the private  base class
  //! constructor, Therefore incorrect code like
  //!   * class Derived1 : public Base<Derived2>
  //! won't compile.
  friend ConcreteResultOwnershipPolicy;
  BaseReceiverResultOwnershipPolicy() // constructor
  {
    return;
  }

  // ====================  METHODS       =======================================
  //! Provides access to the CRTP derived class "Derived."
  //!
  //! @return A reference to the CRTP derived class.
  constexpr ConcreteResultOwnershipPolicy &asDerived_() {
    return *static_cast<ConcreteResultOwnershipPolicy *>(this);
  }

  //! Provides access to the CRTP derived class "Derived."
  //!
  //! @return A reference to a constant CRTP derived class "Derived".
  constexpr ConcreteResultOwnershipPolicy const &asDerived_() const {
    return *static_cast<ConcreteResultOwnershipPolicy const *>(this);
  }

  // ====================  DATA MEMBERS  =======================================

}; // -----  end of class BaseReceiverResultOwnershipPolicy  -----

template <typename RT,
          class ConcreteResultOwnershipPolicy,
          template <typename> typename ConcreteResultOwnershipImpl 
         >
BaseReceiverResultOwnershipPolicy<RT, 
                                  ConcreteResultOwnershipPolicy,
                                  ConcreteResultOwnershipImpl>::~BaseReceiverResultOwnershipPolicy() {
  return;
}

}; // namespace RECEIVER

#endif // RECEIVER_BaseReceiverResultOwnershipPolicy_INC
