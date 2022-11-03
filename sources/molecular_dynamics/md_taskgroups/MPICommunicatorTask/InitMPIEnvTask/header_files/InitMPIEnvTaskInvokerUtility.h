#ifndef  ANANSI_InitMPIEnvInvokerTaskUtility_INC
#define  ANANSI_InitMPIEnvInvokerTaskUtility_INC

//! @file InitMPIEnvTaskInvokerUtility.h
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"

namespace ANANSI
{

class InitMPIEnvInvokerTaskUtility
{
    public:
        // ====================  LIFECYCLE     =======================================

        InitMPIEnvInvokerTaskUtility ();   // constructor

        InitMPIEnvInvokerTaskUtility (const InitMPIEnvInvokerTaskUtility & other);   // copy constructor

        InitMPIEnvInvokerTaskUtility (InitMPIEnvInvokerTaskUtility && other);   // copy-move constructor

        ~InitMPIEnvInvokerTaskUtility ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        InitMPIEnvInvokerTaskUtility& operator= ( const InitMPIEnvInvokerTaskUtility &other ); // assignment operator

        InitMPIEnvInvokerTaskUtility& operator= ( InitMPIEnvInvokerTaskUtility && other ); // assignment-move operator

        // ====================  STATIC  METHODS =======================================

        template<typename INVK_t>
        static void addMPITasks(INVK_t & invoker, std::shared_ptr<COMMUNICATOR::Communicator> & communicator)
        {
            // // ----------------------------------------------------
            // // Create the receiver.
            // //
            // // ----------------------------------------------------
            //  ...... some code to create/enable the receiver.
            //
            // // ----------------------------------------------------
            // //  Create the mpi task object and bind the receiver to it.
            // // 
            // // ----------------------------------------------------
            // std::shared_ptr<ANANSI::AnansiTask> mpi_communicator_cmd = 
            //     this->mdAnansiInitMPIEnvTaskFactory_->create_shared_ptr<CommunicatorTask>(receiver);

            // // ---------------------------------------------------
            // // Add the task object/command to the invoker.
            // // 
            // // ---------------------------------------------------
            // this->mdWorldCommunicatorInvk_->addCommand("world_communicator",mpi_communicator_cmd);

            return;
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class InitMPIEnvInvokerTaskUtility  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitMPIEnvInvokerTaskUtility_INC  ----- 
