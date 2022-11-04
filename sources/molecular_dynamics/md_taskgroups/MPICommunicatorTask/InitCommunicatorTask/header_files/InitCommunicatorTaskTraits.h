#ifndef  ANANSI_InitCommunicatorTaskTraits_INC
#define  ANANSI_InitCommunicatorTaskTraits_INC

//! @file InitCommunicatorTaskTraits.h
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
#include "InitCommunicatorTaskTraits.h"
#include "InitCommunicatorTaskReceiver.h"

namespace ANANSI
{

class InitCommunicatorTaskTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        InitCommunicatorTaskTraits ();   // constructor

        InitCommunicatorTaskTraits (const InitCommunicatorTaskTraits & other);   // copy constructor

        InitCommunicatorTaskTraits (InitCommunicatorTaskTraits && other);   // copy-move constructor

        ~InitCommunicatorTaskTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        InitCommunicatorTaskTraits& operator= ( const InitCommunicatorTaskTraits &other ); // assignment operator

        InitCommunicatorTaskTraits& operator= ( InitCommunicatorTaskTraits && other ); // assignment-move operator

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

}; // -----  end of class InitCommunicatorTaskTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitCommunicatorTaskTraits_INC  ----- 
