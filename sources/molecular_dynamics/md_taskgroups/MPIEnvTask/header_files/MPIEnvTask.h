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

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "InterProcessCommEnv.h"
#include "CommandLineArguments.h"

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

        // ====================  OPERATORS     =======================================

        MPIEnvTask& operator= ( const MPIEnvTask &other ); // assignment operator

        MPIEnvTask& operator= ( MPIEnvTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  ACCESSORS     =======================================
        
        // ====================  MUTATORS      =======================================
        void enable_() override;

        void disable_() override;

        // ====================  DATA MEMBERS  =======================================
        COMMANDLINE::CommandLineArguments commandLineArgs_;

}; // -----  end of class MPIEnvTask  -----


}; // namespace ANANSI

#endif // ANANSI_MPIEnvTask_INC
