#ifndef  COMMUNICATOR_DisabledMPIEnvironment_INC
#define  COMMUNICATOR_DisabledMPIEnvironment_INC

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

namespace COMMUNICATOR
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

        void enable_(MPIEnvironment* const mpi_environment, int const & argc, char const * const * const & argv) override;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class DisabledMPIEnvironment  -----


}; // namespace COMMUNICATOR

#endif   /* ----- #ifndef COMMUNICATOR_DisabledMPIEnvironment_INC  ----- */
