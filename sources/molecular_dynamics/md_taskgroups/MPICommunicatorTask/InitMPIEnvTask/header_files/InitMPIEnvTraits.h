#ifndef  ANANSI_InitMPIEnvTraits_INC
#define  ANANSI_InitMPIEnvTraits_INC

//! @file InitMPIEnvTraits.h
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
#include "InitMPIEnvReceiver.h"

namespace ANANSI
{

class InitMPIEnvTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        InitMPIEnvTraits ();   // constructor

        InitMPIEnvTraits (const InitMPIEnvTraits & other);   // copy constructor

        InitMPIEnvTraits (InitMPIEnvTraits && other);   // copy-move constructor

        ~InitMPIEnvTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        InitMPIEnvTraits& operator= ( const InitMPIEnvTraits &other ); // assignment operator

        InitMPIEnvTraits& operator= ( InitMPIEnvTraits && other ); // assignment-move operator
        
        using abstract_products = MPL::mpl_typelist<
                                                       CommunicatorTask
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                       GenericMDTask<CommunicatorTask,InitMPIEnvReceiver>
                                                   >;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class InitMPIEnvTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitMPIEnvTraits_INC  ----- 
