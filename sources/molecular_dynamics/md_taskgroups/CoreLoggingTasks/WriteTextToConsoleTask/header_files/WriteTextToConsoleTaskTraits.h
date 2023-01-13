#ifndef ANANSI_CoreLoggingTasksTraits_INC
#define ANANSI_CoreLoggingTasksTraits_INC
//! @file CoreLoggingTasksTraits.h
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
#include "ConsoleLoggingTask.h"
#include "GenericMDTask.hpp"
#include "WriteTextToConsoleTaskReceiver.h"

namespace ANANSI
{

class CoreLoggingTasksTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        CoreLoggingTasksTraits ();   // constructor

        CoreLoggingTasksTraits (const CoreLoggingTasksTraits & other);   // copy constructor

        CoreLoggingTasksTraits (CoreLoggingTasksTraits && other);   // copy-move constructor

        ~CoreLoggingTasksTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        CoreLoggingTasksTraits& operator= ( const CoreLoggingTasksTraits &other ); // assignment operator

        CoreLoggingTasksTraits& operator= ( CoreLoggingTasksTraits && other ); // assignment-move operator
        
        // ====================  ALIASES       =======================================

        using abstract_products = MPL::mpl_typelist<
                                                        ConsoleLoggingTask
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                        GenericMDTask<ConsoleLoggingTask,WriteTextToConsoleTaskReceiver>
                                                   >;

        using receiver_results_t = MPL::mpl_typelist <
                                                         WriteTextToConsoleTaskReceiver::receiver_result_t 
                                                     >;

        static constexpr auto LABELS = std::array{
                                                    WriteTextToConsoleTaskReceiver::TASKLABEL
                                                 };

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class CoreLoggingTasksTraits  -----


}; // namespace ANANSI

#endif // ANANSI_CoreLoggingTasksTraits_INC
