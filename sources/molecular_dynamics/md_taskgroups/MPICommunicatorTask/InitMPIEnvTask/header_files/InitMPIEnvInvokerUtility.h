#ifndef  ANANSI_MPICommunicatorInvokerUtility_INC
#define  ANANSI_MPICommunicatorInvokerUtility_INC

//! @file MPICommunicatorInvokerUtility.h
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

class MPICommunicatorInvokerUtility
{
    public:
        // ====================  LIFECYCLE     =======================================

        MPICommunicatorInvokerUtility ();   // constructor

        MPICommunicatorInvokerUtility (const MPICommunicatorInvokerUtility & other);   // copy constructor

        MPICommunicatorInvokerUtility (MPICommunicatorInvokerUtility && other);   // copy-move constructor

        ~MPICommunicatorInvokerUtility ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MPICommunicatorInvokerUtility& operator= ( const MPICommunicatorInvokerUtility &other ); // assignment operator

        MPICommunicatorInvokerUtility& operator= ( MPICommunicatorInvokerUtility && other ); // assignment-move operator

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
            //     this->mdAnansiMPICommunicatorTaskFactory_->create_shared_ptr<CommunicatorTask>(receiver);

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

}; // -----  end of class MPICommunicatorInvokerUtility  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_MPICommunicatorInvokerUtility_INC  ----- 
