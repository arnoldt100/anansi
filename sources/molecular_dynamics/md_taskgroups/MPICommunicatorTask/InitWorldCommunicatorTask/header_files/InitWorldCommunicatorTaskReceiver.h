#ifndef  ANANSI_InitWorldCommunicatorTaskReceiver_INC
#define  ANANSI_InitWorldCommunicatorTaskReceiver_INC

//! @file InitWorldCommunicatorTaskReceiver.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"
#include "ReceiverInterface.hpp"
#include "MPICommunicatorFactory.h"
#include "TaskLabel.hpp"
#include "OwnershipImpl1.hpp"

// ---------------------------------------------------
// Uncomment the ownership policies as required for 
// class member ConcreteTaskReceiver::ownershipPolicy_.
// For this class we select CopyOwnershipPolicy.hpp.
// ---------------------------------------------------
// #include "NullOwnershipPolicy.hpp"
// #include "TransferOwnershipPolicy.hpp"
// #include "ShareCopyOwnershipPolicy.hpp"
// #include "TransferCopyOwnershipPolicy.hpp""
// #include "ShareOwnershipPolicy.hpp"
#include "CopyOwnershipPolicy.hpp"

namespace ANANSI
{

//! InitWorldCommunicatorTaskReceiver creates a world communicator.
//!
//! Below is a summary of the critical methods of InitWorldCommunicatorTaskReceiver.
//!
//! This class is non-copyable for we need the communicator resource created by
//! the class to be solely owned by the object.
//!
//! The method receiverModifyMyself_ modifies the data members of
//! InitWorldCommunicatorTaskReceiver.
//!
//! The result of method receiverdoAction_ is a null action.
//!
//! The result of method receiverUndoAction_ undoes the action of
//! receiverdoAction. For actions that can't be undone this is null action,
//!
//! Invoking method receiverGetCopyOfResults_ returns a smart pointer that is a
//! duplicate of the original world communicator resource.
//!
//! Invoking method disableReceiver_ results in the destruction of the world
//! communicator resource. After this call, all other calls will result in 
//! an error being thrown.
class InitWorldCommunicatorTaskReceiver:  public RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>
{
    public: 
        //! The type of the data member results_.
        using receiver_result_t = std::unique_ptr<COMMUNICATOR::Communicator>;
        
        template<typename T>
        using OwnershipPolicy = OwnershipImpl1<T>;

    private:

        // ---------------------------------------------------
        // Declare the ownership policy of the receivers' result.
        // ---------------------------------------------------
        ANANSI::CopyOwnershipPolicy<receiver_result_t,OwnershipPolicy> ownershipPolicy_;

        mutable receiver_result_t results_;

    public:

        // ====================  STATIC       =======================================

        static constexpr char tmpstr[RECEIVER::TaskLabelTraits::MAX_NM_CHARS] = 
          {'m','p','i','_', 
           'w', 'o', 'r', 'l', 'd', '_', 
           'c', 'o','m', 'm', 'u', 'n', 'i', 'c', 'a', 't', 'o', 'r'};

        static constexpr RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::TASK_LABEL_TYPE(InitWorldCommunicatorTaskReceiver::tmpstr);

        // ====================  LIFECYCLE     =======================================

        InitWorldCommunicatorTaskReceiver ();   // constructor

        InitWorldCommunicatorTaskReceiver (const InitWorldCommunicatorTaskReceiver & other) = delete;   // copy constructor

        InitWorldCommunicatorTaskReceiver (InitWorldCommunicatorTaskReceiver && other);   // copy-move constructor

        ~InitWorldCommunicatorTaskReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        
        // ====================  OPERATORS     =======================================

        InitWorldCommunicatorTaskReceiver& operator= ( const InitWorldCommunicatorTaskReceiver &other ) = delete; // assignment operator

        InitWorldCommunicatorTaskReceiver& operator= ( InitWorldCommunicatorTaskReceiver && other ); // assignment-move operator

    protected:

        // ====================  ACCESSORS     =======================================
        template<typename... Types>
        void receiverDoAction_(Types & ...  args) const;

        template<typename... Types>
        void receiverUndoAction_(Types &... args) const;

        constexpr RECEIVER::ReceiverInterface<InitWorldCommunicatorTaskReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  InitWorldCommunicatorTaskReceiver::TASKLABEL;
        }

        OwnershipPolicy<receiver_result_t>::Copytype receiverGetCopyOfResults_() const;

        // ====================  MUTATORS      =======================================

        template<typename T>
        void enaableReceiver_(T & args);

        template<typename... Types>
        void disableReceiver_(Types &...  args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class InitWorldCommunicatorTaskReceiver  -----

template<typename... Types>
void InitWorldCommunicatorTaskReceiver::receiverDoAction_(Types &...  args) const
{
    // This class doesn't have a do action implemented.
    return;
}

template<typename... Types>
void InitWorldCommunicatorTaskReceiver::receiverUndoAction_(Types &... args) const
{
    // This class doesn't have an undo action.
    return;
}

template<typename T>
void InitWorldCommunicatorTaskReceiver::enaableReceiver_(T & args)
{
    return;
}

template<typename... Types>
void InitWorldCommunicatorTaskReceiver::disableReceiver_(Types &...  args) 
{
    this->results_->freeCommunicator();
    this->results_.reset();
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitWorldCommunicatorTaskReceiver_INC  ----- 
