#ifndef ANANSI_InterProcessCommEnv
#define ANANSI_InterProcessCommEnv
//! @file __filename__
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
#include "InterProcessCommEnv.h"

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

}; // -----  end of class MPIEnvTask  -----


}; // namespace ANANSI

#endif // ANANSI_InterProcessCommEnv
