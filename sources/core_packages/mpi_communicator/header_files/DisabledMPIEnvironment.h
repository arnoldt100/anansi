#ifndef  ANANSI_DisabledMPIEnvironment_INC
#define  ANANSI_DisabledMPIEnvironment_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIEnvironmentState.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  DisabledMPIEnvironment
//  Description:  
//  =====================================================================================
class DisabledMPIEnvironment : public MPIEnvironmentState
{
    public:
        // ====================  LIFECYCLE     =======================================

        DisabledMPIEnvironment ();   // constructor

        DisabledMPIEnvironment (const DisabledMPIEnvironment & other);   // copy constructor

        DisabledMPIEnvironment (DisabledMPIEnvironment && other);   // copy-move constructor

        ~DisabledMPIEnvironment ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        DisabledMPIEnvironment& operator= ( const DisabledMPIEnvironment &other ); // assignment operator

        DisabledMPIEnvironment& operator= ( DisabledMPIEnvironment && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  MUTATORS      =======================================

        void enable_(MPIEnvironment* const mpi_environment) override;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class DisabledMPIEnvironment  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_DisabledMPIEnvironment_INC  ----- */
