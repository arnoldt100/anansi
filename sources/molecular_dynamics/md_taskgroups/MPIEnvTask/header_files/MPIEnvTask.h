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

namespace ANANSI
{

// =====================================================================================
//        Class:  MPIEnvTask
//  Description:  
//  =====================================================================================
class MPIEnvTask final : public TaskInterface<MPIEnvTask>,
                         public ANANSI::InterProcessCommEnv
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
            std::cout << "Executing concrete task MPIEnvTask." << std::endl;
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
        COMMANDLINE::CommandLineArguments commandLineArgs_;

}; // -----  end of class MPIEnvTask  -----


}; // namespace ANANSI

#endif // ANANSI_MPIEnvTask_INC
