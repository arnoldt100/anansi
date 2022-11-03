#ifndef  ANANSI_InitMPIEnvTraits_INC
#define  ANANSI_InitMPIEnvTraits_INC

//! @file InitMPIEnvTaskTraits.h
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
#include "InitMPIEnvTaskReceiver.h"

namespace ANANSI
{

class InitMPIEnvTaskTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        InitMPIEnvTaskTraits ();   // constructor

        InitMPIEnvTaskTraits (const InitMPIEnvTaskTraits & other);   // copy constructor

        InitMPIEnvTaskTraits (InitMPIEnvTaskTraits && other);   // copy-move constructor

        ~InitMPIEnvTaskTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        InitMPIEnvTaskTraits& operator= ( const InitMPIEnvTaskTraits &other ); // assignment operator

        InitMPIEnvTaskTraits& operator= ( InitMPIEnvTaskTraits && other ); // assignment-move operator
        
        using abstract_products = MPL::mpl_typelist<
                                                       CommunicatorTask
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                       GenericMDTask<CommunicatorTask,InitMPIEnvTaskReceiver>
                                                   >;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class InitMPIEnvTaskTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitMPIEnvTraits_INC  ----- 
