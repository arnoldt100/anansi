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
#include "MPLAliases.hpp"
#include "Communicator.h"
#include "CommunicatorTask.h"
#include "ReceiverResultTraits.hpp"
#include "ReceiverInterface.hpp"
#include "MPICommunicatorFactory.h"
#include "TaskLabel.hpp"
#include "InitWorldCommunicatorTaskOwnershipImpl.hpp"
#include "CopyOwnershipPolicy.hpp"
#include "OwnershipTypes.hpp"

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
    private:

        static constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
          {'m','p','i','_', 
           'w', 'o', 'r', 'l', 'd', '_', 
           'c', 'o','m', 'm', 'u', 'n', 'i', 'c', 'a', 't', 'o', 'r'};

        using my_result_type_ = std::unique_ptr<COMMUNICATOR::Communicator>;
        using my_copy_type_ = std::unique_ptr<COMMUNICATOR::Communicator>;
        using my_share_type_ = std::shared_ptr<COMMUNICATOR::Communicator>;
        using my_transfer_type_ = std::unique_ptr<COMMUNICATOR::Communicator>;
        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                      my_copy_type_,
                                                                      my_share_type_,
                                                                      my_transfer_type_>;

        using MyOwnershipImpl_ = InitWorldCommunicatorTaskOwnershipImpl<MyOwnershipImplTraits_>;
        using MyOwnershipPolicy_ = ANANSI::CopyOwnershipPolicy<MyOwnershipImpl_>;


    public: 
        using MyComponentReceiverTypelist = MPL::mpl_typelist<>;

        using MyParentTask = CommunicatorTask;

        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = typename RECEIVER::ReceiverResultOwnershipType<Q,MyOwnershipImpl_>;

        using receiver_result_t = my_result_type_;

        // ====================  STATIC       =======================================

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

    private:

        using receiver_copy_t_ = 
            typename RECEIVER::ReceiverResultOwnershipType_TraitsVersion<RECEIVER::OwnershipTypes::COPYTYPE,
                                                                         MyOwnershipImplTraits_>::TYPE;

        using receiver_share_t_ = 
            typename RECEIVER::ReceiverResultOwnershipType_TraitsVersion<RECEIVER::OwnershipTypes::SHARETYPE,
                                                                         MyOwnershipImplTraits_>::TYPE;

        using receiver_transfer_t_ = 
            typename RECEIVER::ReceiverResultOwnershipType_TraitsVersion<RECEIVER::OwnershipTypes::TRANSFERTYPE,
                                                                         MyOwnershipImplTraits_>::TYPE;

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

        receiver_copy_t_  receiverGetCopyOfResults_() const;


        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void enableReceiver_(Types &...  args);

        template<typename... Types>
        void disableReceiver_(Types &...  args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        receiver_share_t_ receiverShareOwnershipOfResults_();

        receiver_transfer_t_ receiverTransferOwnershipOfResults_();

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  TYPE ALIASES  =======================================

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable receiver_result_t results_;
        MyOwnershipPolicy_ ownershipPolicy_;

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

template<typename... Types>
void InitWorldCommunicatorTaskReceiver::enableReceiver_(Types &...  args)
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
