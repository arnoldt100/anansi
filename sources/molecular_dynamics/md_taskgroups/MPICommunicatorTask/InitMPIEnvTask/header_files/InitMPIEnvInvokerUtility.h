#ifndef  ANANSI_InitMPIEnvInvokerUtility_INC
#define  ANANSI_InitMPIEnvInvokerUtility_INC

//! @file InitMPIEnvInvokerUtility.h
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

class InitMPIEnvInvokerUtility
{
    public:
        // ====================  LIFECYCLE     =======================================

        InitMPIEnvInvokerUtility ();   // constructor

        InitMPIEnvInvokerUtility (const InitMPIEnvInvokerUtility & other);   // copy constructor

        InitMPIEnvInvokerUtility (InitMPIEnvInvokerUtility && other);   // copy-move constructor

        ~InitMPIEnvInvokerUtility ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        InitMPIEnvInvokerUtility& operator= ( const InitMPIEnvInvokerUtility &other ); // assignment operator

        InitMPIEnvInvokerUtility& operator= ( InitMPIEnvInvokerUtility && other ); // assignment-move operator

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

}; // -----  end of class InitMPIEnvInvokerUtility  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitMPIEnvInvokerUtility_INC  ----- 
