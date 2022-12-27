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

        // ====================  STATIC       =======================================

        static constexpr char tmpstr[TaskLabelTraits::MAX_NM_CHARS] = {'m', 'p', 'i', '_', 'e', 'n', 'v', 'i', 'r', 'o', 'n', 'm', 'e', 'n', 't'};

        static const 
        RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>::TASK_LABEL_TYPE TASKLABEL;

        // ====================  LIFECYCLE     =======================================

        InitMPIEnvTaskReceiver ();   // constructor

        InitMPIEnvTaskReceiver (const InitMPIEnvTaskReceiver & other);   // copy constructor

        InitMPIEnvTaskReceiver (InitMPIEnvTaskReceiver && other);   // copy-move constructor

        ~InitMPIEnvTaskReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        RECEIVER::ReceiverInterface<InitMPIEnvTaskReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel() const;

        template<typename... Types>
        void receiverDoAction(Types &... args) const;

        template<typename... Types>
        void receiverUndoAction(Types &... args) const;

        // ====================  MUTATORS      =======================================

        template<typename T>
        void enableReceiver(T & arg);

        template<typename... Types>
        void disableReceiver(Types &...  args);

        template<typename T>
        void receiverModifyMyself(T & arg);

        // ====================  OPERATORS     =======================================

        InitMPIEnvTaskReceiver& operator= ( const InitMPIEnvTaskReceiver &other ); // assignment operator

        InitMPIEnvTaskReceiver& operator= ( InitMPIEnvTaskReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable std::shared_ptr<ANANSI::MPIEnvironment> mpiEnvironment_;

}; // -----  end of class InitMPIEnvTaskReceiver  -----

template<typename... Types>
void InitMPIEnvTaskReceiver::disableReceiver(Types &...  args)
{
    return;
}

template<typename... Types>
void InitMPIEnvTaskReceiver::receiverDoAction(Types &... args) const
{
    this->mpiEnvironment_->enableEnvironment();
    return;
}

template<typename... Types>
void InitMPIEnvTaskReceiver::receiverUndoAction(Types &... args) const
{
    this->mpiEnvironment_->disableEnvironment();
    return;
}

}; // namespace ANANSI

#endif // ANANSI_InitMPIEnvTaskReceiver_INC
