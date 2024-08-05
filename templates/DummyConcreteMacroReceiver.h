#ifndef  ANANSI_DummyConcreteTask_INC
#define  ANANSI_DummyConcreteTask_INC

//! @file DummyConcreteTask.h
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReceiverResultTraits.hpp"
#include "ReceiverInterface.hpp"
#include "TaskLabel.hpp"
#include "DummyConcreteTaskOwnershipImpl.hpp"

// ---------------------------------------------------
// Uncomment the ownership policies as required for 
// class member ConcreteTaskReceiver::ownershipPolicy_.
// For this class we select ShareCopyOwnershipPolicy.hpp.
// ---------------------------------------------------
// #include "NullOwnershipPolicy.hpp"
// #include "TransferOwnershipPolicy.hpp"
// #include "ShareCopyOwnershipPolicy.hpp"
// #include "ShareCopyOwnershipPolicy.hpp"
// #include "TransferCopyOwnershipPolicy.hpp""
#include "ShareOwnershipPolicy.hpp"
// #include "CopyOwnershipPolicy.hpp"

namespace ANANSI
{

class DummyConcreteTask :  public RECEIVER::ReceiverInterface<DummyConcreteTask>
{
    private:
        static constexpr char tmpstr[RECEIVER::TaskLabelTraits::MAX_NM_CHARS] = 
            {'d','u','m','m','y', '_','l','a','b','e','l'};

        using my_result_type_ = int;
        using my_copy_type_ = int;
        using my_share_type_ = int;
        using my_transfer_type_ = int;
        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                      my_copy_type_,
                                                                      my_share_type_,
                                                                      my_transfer_type_>;

        using MyOwnershipImpl_ = DummyConcreteTaskOwnershipImpl<MyOwnershipImplTraits_>;

        using MyOwnershipPolicy_ = ANANSI::ShareCopyOwnershipPolicy<MyOwnershipImpl_>;
        
        // Place here the class data members required for doing the task.

    public:
        using receiver_result_t = MyOwnershipImplTraits_::Resulttype;

        // ====================  STATIC       =======================================


        static constexpr 
        RECEIVER::ReceiverInterface<DummyConcreteTask>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<DummyConcreteTask>::TASK_LABEL_TYPE(DummyConcreteTask::tmpstr);

        // ====================  LIFECYCLE     =======================================

        DummyConcreteTask ();   // constructor

        DummyConcreteTask (const DummyConcreteTask & other);   // copy constructor

        DummyConcreteTask (DummyConcreteTask && other);   // copy-move constructor

        ~DummyConcreteTask ();  // destructor

        // ====================  ACCESSORS     =======================================


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        DummyConcreteTask& operator= ( const DummyConcreteTask &other ); // assignment operator

        DummyConcreteTask& operator= ( DummyConcreteTask && other ); // assignment-move operator

    protected:
        // ====================  ACCESSORS     =======================================
        template<typename... Types>
        void receiverDoAction_(Types &... args) const;

        template<typename... Types>
        void receiverUndoAction_(Types &... args) const;

        constexpr RECEIVER::ReceiverInterface<DummyConcreteTask>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  DummyConcreteTask::TASKLABEL;
        }

        MyOwnershipImplTraits_::Copytype receiverGetCopyOfResults_() const;


        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void enableReceiver_(Types &... arg);

        template<typename... Types>
        void disableReceiver_(Types &... args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        MyOwnershipImplTraits_::Sharetype receiverShareOwnershipOfResults_();
    
        MyOwnershipImplTraits_::Transfertype receiverTransferOwnershipOfResults_();

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable receiver_result_t results_;
        MyOwnershipPolicy_ ownershipPolicy_;

}; // -----  end of class DummyConcreteTask  -----

template<typename... Types>
void DummyConcreteTask::enableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void DummyConcreteTask::disableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void DummyConcreteTask::receiverDoAction_(Types & ... args) const
{
    return;
}

template<typename... Types>
void DummyConcreteTask::receiverUndoAction_(Types & ... args) const
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_DummyConcreteTask_INC  ----- 
