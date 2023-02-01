#ifndef  ANANSI_ControlFileMPICommReceiver_INC
#define  ANANSI_ControlFileMPICommReceiver_INC

//! @file ControlFileMPICommReceiver.h
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

class ControlFileMPICommReceiver :  public RECEIVER::ReceiverInterface<ControlFileMPICommReceiver>
{
    public:
        using receiver_result_t = int;

        // ====================  STATIC       =======================================

        static constexpr char tmpstr[TaskLabelTraits::MAX_NM_CHARS] = 
            {'c','o','m','m','u', 'n','i','c','a','t','e','_','c','o','n','t','r','o','l','_','f','i','l','e'};

        static constexpr 
        RECEIVER::ReceiverInterface<ControlFileMPICommReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<ControlFileMPICommReceiver>::TASK_LABEL_TYPE(ControlFileMPICommReceiver::tmpstr);

        // ====================  LIFECYCLE     =======================================

        ControlFileMPICommReceiver ();   // constructor

        ControlFileMPICommReceiver (const ControlFileMPICommReceiver & other);   // copy constructor

        ControlFileMPICommReceiver (ControlFileMPICommReceiver && other);   // copy-move constructor

        ~ControlFileMPICommReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        constexpr RECEIVER::ReceiverInterface<ControlFileMPICommReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel() const
        {
            return  ControlFileMPICommReceiver::TASKLABEL;
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

        ControlFileMPICommReceiver& operator= ( const ControlFileMPICommReceiver &other ); // assignment operator

        ControlFileMPICommReceiver& operator= ( ControlFileMPICommReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable receiver_result_t results_;

}; // -----  end of class ControlFileMPICommReceiver  -----

template<typename... Types>
void ControlFileMPICommReceiver::receiverDoAction(Types & ... args) const
{
    return;
}

template<typename... Types>
void ControlFileMPICommReceiver::receiverUndoAction(Types & ... args) const
{
    return;
}

template<typename... Types>
void ControlFileMPICommReceiver::disableReceiver(Types... args)
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileMPICommReceiver_INC  ----- 
