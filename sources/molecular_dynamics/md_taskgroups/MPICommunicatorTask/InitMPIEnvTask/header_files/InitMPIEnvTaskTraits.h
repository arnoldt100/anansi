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
#include <array>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"
#include "GenericMDTask.hpp"

// Includes for abstract tasks.
#include "InterProcessCommEnv.h"

// Includes for concrete tasks receivers.
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
                                                       InitMPIEnvTaskReceiver::MyParentTask
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                       GenericMDTask<InitMPIEnvTaskReceiver>
                                                   >;

        using receiver_results_t = MPL::mpl_typelist<
                                                    	InitMPIEnvTaskReceiver::receiver_result_t
                                                    >;

        static constexpr auto LABELS  = std::array{ InitMPIEnvTaskReceiver::TASKLABEL};

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class InitMPIEnvTaskTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitMPIEnvTraits_INC  ----- 
