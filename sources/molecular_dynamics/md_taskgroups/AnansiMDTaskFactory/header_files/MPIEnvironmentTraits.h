#ifndef ANANSI_MPIEnvironmentTraits_INC
#define ANANSI_MPIEnvironmentTraits_INC
//! @file MPIEnvironmentTraits.h
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
#include "MPLAliases.hpp"
#include "InterProcessCommEnv.h"
#include "GenericMDTask.hpp"
#include "DefaultFunctorImpl.h"
#include "MPIEnvReceiver.h"


namespace ANANSI
{

class MPIEnvironmentTraits 
{
    public:
        // ====================  LIFECYCLE     =======================================

        MPIEnvironmentTraits ();   // constructor

        MPIEnvironmentTraits (const MPIEnvironmentTraits & other);   // copy constructor

        MPIEnvironmentTraits (MPIEnvironmentTraits && other);   // copy-move constructor

        ~MPIEnvironmentTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MPIEnvironmentTraits& operator= ( const MPIEnvironmentTraits &other ); // assignment operator

        MPIEnvironmentTraits& operator= ( MPIEnvironmentTraits && other ); // assignment-move operator

        using abstract_products = MPL::mpl_typelist<
                                                       InterProcessCommEnv
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                       GenericMDTask<InterProcessCommEnv,MPIEnvReceiver>
                                                   >;
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MPIEnvironmentTraits  -----


}; // namespace ANANSI

#endif // ANANSI_MPIEnvironmentTraits_INC
