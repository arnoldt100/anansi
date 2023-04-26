#ifndef ANANSI_InitMPIEnvTaskReceiver_INC
#define ANANSI_InitMPIEnvTaskReceiver_INC

//! @file InitMPIEnvTaskReceiver.h
//!
//! This header file declares the class InitMPIEnvTaskReceiver.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReceiverInterface.hpp"
#include "MPIEnvironment.h"
#include "TaskLabel.hpp"
#include "InitMPIEnvTaskOwnershipImpl.h"
#include "ReceiverResultTraits.hpp"

// ---------------------------------------------------
// Uncomment the ownership policies as required for 
// class member ConcreteTaskReceiver::ownershipPolicy_.
// For this class we select NullOwnershipPolicy.hpp.
// ---------------------------------------------------
#include "NullOwnershipPolicyVersion2.hpp"
// #include "TransferOwnershipPolicy.hpp"
// #include "ShareCopyOwnershipPolicy.hpp"
// #include "TransferCopyOwnershipPolicy.hpp""
// #include "ShareOwnershipPolicy.hpp"
// #include "CopyOwnershipPolicy.hpp"


namespace ANANSI
{

//! This receiver task is to initialize the MPI environment.
//!
//! The result of the task is an integer type which store no meaningful information - it is simply
//! a placeholder.
class InitMPIEnvTaskReceiver : public RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>
{

    private:
        static constexpr char tmp_task_label_[ANANSI::TaskLabelTraits::MAX_NM_CHARS] =
            {'m', 'p', 'i', '_', 'e', 'n', 'v', 'i', 'r', 'o', 'n', 'm', 'e', 'n', 't'};

        using my_result_type_ = int;
        using my_copy_type_ = int;
        using my_share_type_ = int;
        using my_transfer_type_ = int;
        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                     my_copy_type_,
                                                                     my_share_type_,
                                                                     my_transfer_type_>;

        using MyOwnershipImpl_ = InitMPIEnvTaskOwnershipImpl<MyOwnershipImplTraits_>;

        using MyOwnershipPolicy_ = ANANSI::NullOwnershipPolicyVersion2<MyOwnershipImplTraits_::Resulttype,
                                                                       MyOwnershipImpl_>;
    public:

        using receiver_result_t = MyOwnershipImplTraits_::Resulttype;

        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>::TASK_LABEL_TYPE TASKLABEL = 
            RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>::TASK_LABEL_TYPE(InitMPIEnvTaskReceiver::tmp_task_label_);

        // ====================  LIFECYCLE     =======================================

        InitMPIEnvTaskReceiver ();   // constructor

        InitMPIEnvTaskReceiver (const InitMPIEnvTaskReceiver & other) = delete;   // copy constructor

        InitMPIEnvTaskReceiver (InitMPIEnvTaskReceiver && other);   // copy-move constructor

        ~InitMPIEnvTaskReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        InitMPIEnvTaskReceiver& operator= ( const InitMPIEnvTaskReceiver &other ) = delete; // assignment operator

        InitMPIEnvTaskReceiver& operator= ( InitMPIEnvTaskReceiver && other ); // assignment-move operator

    protected:
        // ====================  ACCESSORS     =======================================

        template<typename... Types>
        void receiverDoAction_(Types &... args) const;

        template<typename... Types>
        void receiverUndoAction_(Types &... args) const;

        constexpr RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  InitMPIEnvTaskReceiver::TASKLABEL;
        }

        MyOwnershipImpl_::Copytype receiverGetCopyOfResults_() const;

        MyOwnershipImpl_::Transfertype receiverTransferOwnershipOfResults_();

        // ====================  MUTATORS      =======================================
        template<typename... Types>
        void enableReceiver_(Types &... args);


        template<typename... Types>
        void disableReceiver_(Types &...  args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        MyOwnershipImplTraits_::Sharetype receiverShareOwnershipOfResults_();

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable receiver_result_t results_;
        mutable std::shared_ptr<ANANSI::MPIEnvironment> mpiEnvironment_;
        MyOwnershipPolicy_ ownershipPolicy_;

}; // -----  end of class InitMPIEnvTaskReceiver  -----

template<typename... Types>
void InitMPIEnvTaskReceiver::enableReceiver_(Types &...  args)
{
    return;
}

template<typename... Types>
void InitMPIEnvTaskReceiver::disableReceiver_(Types &...  args)
{
    this->mpiEnvironment_->disableEnvironment();
    return;
}

template<typename... Types>
void InitMPIEnvTaskReceiver::receiverDoAction_(Types &... args) const
{
    this->mpiEnvironment_->enableEnvironment();
    return;
}

template<typename... Types>
void InitMPIEnvTaskReceiver::receiverUndoAction_(Types &... args) const
{
    // This class doesn't have an action to undo. 
    return;
}

}; // namespace ANANSI

#endif // ANANSI_InitMPIEnvTaskReceiver_INC
