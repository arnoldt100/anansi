#ifndef ANANSI_InitMPIEnvTaskReceiver_INC
#define ANANSI_InitMPIEnvTaskReceiver_INC

//! @file InitMPIEnvTaskReceiver.h
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
#include "MPIEnvironment.h"
#include "TaskLabel.hpp"
#include "TaskLabelTraits.hpp"

namespace ANANSI
{

class InitMPIEnvTaskReceiver :  public RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>
{
    public:
        using receiver_result_t = int;

        // ====================  STATIC       =======================================

        static constexpr char tmpstr[RECEIVER::TaskLabelTraits::MAX_NM_CHARS] = {'m', 'p', 'i', '_', 'e', 'n', 'v', 'i', 'r', 'o', 'n', 'm', 'e', 'n', 't'};

        static constexpr 
        RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>::TASK_LABEL_TYPE TASKLABEL = 
            RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>::TASK_LABEL_TYPE(InitMPIEnvTaskReceiver::tmpstr);

        // ====================  LIFECYCLE     =======================================

        InitMPIEnvTaskReceiver ();   // constructor

        InitMPIEnvTaskReceiver (const InitMPIEnvTaskReceiver & other) = delete;   // copy constructor

        InitMPIEnvTaskReceiver (InitMPIEnvTaskReceiver && other);   // copy-move constructor

        ~InitMPIEnvTaskReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        auto receiverGetResults() const;

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

        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void disableReceiver_(Types &...  args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable std::shared_ptr<ANANSI::MPIEnvironment> mpiEnvironment_;
        mutable receiver_result_t results_;

}; // -----  end of class InitMPIEnvTaskReceiver  -----

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
