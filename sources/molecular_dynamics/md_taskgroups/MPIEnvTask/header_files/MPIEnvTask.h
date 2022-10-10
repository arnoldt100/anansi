#ifndef ANANSI_MPIEnvTask_INC
#define ANANSI_MPIEnvTask_INC
//! @file MPIEnvTask.h
//!
//! Brief description
//!
//! Detailed description

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
#include "InterProcessCommEnv.h"
#include "CommandLineArguments.h"
#include "TaskInterface.hpp"
#include "MPIEnvironment.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  MPIEnvTask
//  Description:  
//  =====================================================================================
class MPIEnvTask final : public ANANSI::InterProcessCommEnv
{
    public:
        // ====================  LIFECYCLE     =======================================

        MPIEnvTask ();   // constructor

        MPIEnvTask (const MPIEnvTask & other);   // copy constructor

        MPIEnvTask (MPIEnvTask && other);   // copy-move constructor

        ~MPIEnvTask ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        
        void enableConcreteTask()
        {
            std::cout << "Enabling concrete task MPIEnvTask." << std::endl;
        }

        void disableConcreteTask()
        {
            std::cout << "Disabling concrete task MPIEnvTask." << std::endl;
        }

        void executeConcreteTask()
        {
            return;
        }

        template <typename... Types>
        void bindReceivers(Types... args)
        {
            std::cout << "Binding general receiver." << std::endl;
        }

        template <typename T>
        void bindAReceiver(T arg)
        {
            std::cout << "Binding a general receiver." << std::endl;
        }

        // ====================  OPERATORS     =======================================

        MPIEnvTask& operator= ( const MPIEnvTask &other ); // assignment operator

        MPIEnvTask& operator= ( MPIEnvTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  ACCESSORS     =======================================
        
        // ====================  MUTATORS      =======================================

        // ====================  DATA MEMBERS  =======================================
        std::shared_ptr<TaskInterface<MPIEnvTask>> taskInterface_;
        std::shared_ptr<ANANSI::MPIEnvironment> mpiEnvironment_;

}; // -----  end of class MPIEnvTask  -----



}; // namespace ANANSI

#endif // ANANSI_MPIEnvTask_INC
