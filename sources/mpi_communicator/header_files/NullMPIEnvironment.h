#ifndef  COMMUNICATOR_NullMPIEnvironment_INC
#define  COMMUNICATOR_NullMPIEnvironment_INC

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
//        Class:  NullMPIEnvironment
//  Description:  
//  =====================================================================================
class NullMPIEnvironment : public MPIEnvironmentState
{
    public:
        // ====================  LIFECYCLE     =======================================

        NullMPIEnvironment ();   // constructor

        NullMPIEnvironment (const NullMPIEnvironment & other);   // copy constructor

        NullMPIEnvironment (NullMPIEnvironment && other);   // copy-move constructor

        ~NullMPIEnvironment ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        NullMPIEnvironment& operator= ( const NullMPIEnvironment &other ); // assignment operator

        NullMPIEnvironment& operator= ( NullMPIEnvironment && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  MUTATORS      =======================================

        void enable_(MPIEnvironment* const mpi_environment) override;

        void enable_(MPIEnvironment* const mpi_environment, int const & argc, char const * const * const & argv) override;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class NullMPIEnvironment  -----


}; // namespace COMMUNICATOR

#endif   /* ----- #ifndef COMMUNICATOR_NullMPIEnvironment_INC  ----- */
