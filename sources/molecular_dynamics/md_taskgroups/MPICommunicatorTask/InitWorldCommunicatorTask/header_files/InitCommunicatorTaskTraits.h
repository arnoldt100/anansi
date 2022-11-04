#ifndef  ANANSI_InitWorldCommunicatorTaskTraits_INC
#define  ANANSI_InitWorldCommunicatorTaskTraits_INC

//! @file InitWorldCommunicatorTaskTraits.h
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"
#include "CommunicatorTask.h"
#include "GenericMDTask.hpp"
#include "DefaultFunctorImpl.h"


//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "InitWorldCommunicatorTaskTraits.h"
#include "InitCommunicatorTaskReceiver.h"

namespace ANANSI
{

class InitWorldCommunicatorTaskTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        InitWorldCommunicatorTaskTraits ();   // constructor

        InitWorldCommunicatorTaskTraits (const InitWorldCommunicatorTaskTraits & other);   // copy constructor

        InitWorldCommunicatorTaskTraits (InitWorldCommunicatorTaskTraits && other);   // copy-move constructor

        ~InitWorldCommunicatorTaskTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        InitWorldCommunicatorTaskTraits& operator= ( const InitWorldCommunicatorTaskTraits &other ); // assignment operator

        InitWorldCommunicatorTaskTraits& operator= ( InitWorldCommunicatorTaskTraits && other ); // assignment-move operator

        using abstract_products = MPL::mpl_typelist<
                                                       CommunicatorTask
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                       GenericMDTask<CommunicatorTask,InitCommunicatorTaskReceiver>
                                                   >;
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class InitWorldCommunicatorTaskTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitWorldCommunicatorTaskTraits_INC  ----- 
