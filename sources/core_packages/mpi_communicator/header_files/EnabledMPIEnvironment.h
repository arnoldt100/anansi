#ifndef  ANANSI_EnabledMPIEnvironment_INC
#define  ANANSI_EnabledMPIEnvironment_INC

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
//        Class:  EnabledMPIEnvironment
//  Description:  
//  =====================================================================================
class EnabledMPIEnvironment : public MPIEnvironmentState
{
    public:
        // ====================  LIFECYCLE     =======================================

        EnabledMPIEnvironment ();   // constructor

        EnabledMPIEnvironment (const EnabledMPIEnvironment & other);   // copy constructor

        EnabledMPIEnvironment (EnabledMPIEnvironment && other);   // copy-move constructor

        ~EnabledMPIEnvironment ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        EnabledMPIEnvironment& operator= ( const EnabledMPIEnvironment &other ); // assignment operator

        EnabledMPIEnvironment& operator= ( EnabledMPIEnvironment && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  MUTATORS      =======================================

        void disable_(MPIEnvironment* const mpi_environment) override;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class EnabledMPIEnvironment  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_EnabledMPIEnvironment_INC  ----- */
