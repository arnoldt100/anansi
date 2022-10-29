#ifndef  ANANSI_MPICommunicatorTraits_INC
#define  ANANSI_MPICommunicatorTraits_INC

//! @file MPICommunicatorTraits.h
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
#include "CommunicatorTask.h"
#include "GenericMDTask.hpp"
#include "DefaultFunctorImpl.h"
#include "MPICommunicatorReceiver.h"

namespace ANANSI
{

class MPICommunicatorTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        MPICommunicatorTraits ();   // constructor

        MPICommunicatorTraits (const MPICommunicatorTraits & other);   // copy constructor

        MPICommunicatorTraits (MPICommunicatorTraits && other);   // copy-move constructor

        ~MPICommunicatorTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MPICommunicatorTraits& operator= ( const MPICommunicatorTraits &other ); // assignment operator

        MPICommunicatorTraits& operator= ( MPICommunicatorTraits && other ); // assignment-move operator
        
        using abstract_products = MPL::mpl_typelist<
                                                       CommunicatorTask
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                       GenericMDTask<CommunicatorTask,MPICommunicatorReceiver>
                                                   >;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MPICommunicatorTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_MPICommunicatorTraits_INC  ----- 
