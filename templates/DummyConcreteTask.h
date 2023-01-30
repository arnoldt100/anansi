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
#include "ReceiverInterface.hpp"
#include "TaskLabel.hpp"

namespace ANANSI
{

class DummyConcreteTask :  public RECEIVER::ReceiverInterface<DummyConcreteTask>
{
    public:
        using receiver_result_t = int;

        // ====================  STATIC       =======================================

        static constexpr char tmpstr[TaskLabelTraits::MAX_NM_CHARS] = 
            {'d','u','m','m','y', '_','l','a','b','e','l'};

        static constexpr 
        RECEIVER::ReceiverInterface<DummyConcreteTask>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<DummyConcreteTask>::TASK_LABEL_TYPE(DummyConcreteTask::tmpstr);

        // ====================  LIFECYCLE     =======================================

        DummyConcreteTask ();   // constructor

        DummyConcreteTask (const DummyConcreteTask & other);   // copy constructor

        DummyConcreteTask (DummyConcreteTask && other);   // copy-move constructor

        ~DummyConcreteTask ();  // destructor

        // ====================  ACCESSORS     =======================================

        constexpr RECEIVER::ReceiverInterface<DummyConcreteTask>::TASK_LABEL_TYPE receiverGetTaskLabel() const
        {
            return  DummyConcreteTask::TASKLABEL;
        }

        template<typename... Types>
        void receiverDoAction(Types &... args) const;

        template<typename... Types>
        void receiverUndoAction(Types & ... args) const;

        std::unique_ptr<receiver_result_t> receiverGetCopyOfResults() const;

        // ====================  MUTATORS      =======================================
        template<typename T>
        void enableReceiver(T & arg);

        template<typename... Types>
        void disableReceiver(Types... args);

        template<typename T>
        void receiverModifyMyself(T & arg);

        // ====================  OPERATORS     =======================================

        DummyConcreteTask& operator= ( const DummyConcreteTask &other ); // assignment operator

        DummyConcreteTask& operator= ( DummyConcreteTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable receiver_result_t results_;

}; // -----  end of class DummyConcreteTask  -----

template<typename... Types>
void DummyConcreteTask::receiverDoAction(Types & ... args) const
{
    return;
}

template<typename... Types>
void DummyConcreteTask::receiverUndoAction(Types & ... args) const
{
    return;
}

template<typename... Types>
void DummyConcreteTask::disableReceiver(Types... args)
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_DummyConcreteTask_INC  ----- 
