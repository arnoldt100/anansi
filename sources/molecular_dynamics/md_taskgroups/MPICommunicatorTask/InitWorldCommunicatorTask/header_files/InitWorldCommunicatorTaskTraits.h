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
#include "CommunicatorTask.h"

// Includes for concrete tasks receivers.
#include "InitWorldCommunicatorTaskReceiver.h"

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

        // ====================  ALIASES       =======================================
        
        using abstract_products = MPL::mpl_typelist<
                                                       InitWorldCommunicatorTaskReceiver::MyParentTask
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                       GenericMDTask<InitWorldCommunicatorTaskReceiver::MyParentTask,
                                                                     InitWorldCommunicatorTaskReceiver>
                                                   >;

        using receiver_results_t = MPL::mpl_typelist <
                                                         InitWorldCommunicatorTaskReceiver::receiver_result_t 
                                                     >;

        static constexpr auto LABELS = std::array{
                                                    InitWorldCommunicatorTaskReceiver::TASKLABEL
                                                 };

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class InitWorldCommunicatorTaskTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_InitWorldCommunicatorTaskTraits_INC  ----- 
