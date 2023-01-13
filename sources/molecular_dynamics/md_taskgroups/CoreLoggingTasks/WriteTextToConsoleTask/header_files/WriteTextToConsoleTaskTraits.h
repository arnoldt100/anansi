#ifndef ANANSI_WriteTextToConsoleTaskTraits_INC
#define ANANSI_WriteTextToConsoleTaskTraits_INC
//! @file WriteTextToConsoleTaskTraits.h
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

class WriteTextToConsoleTaskTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        WriteTextToConsoleTaskTraits ();   // constructor

        WriteTextToConsoleTaskTraits (const WriteTextToConsoleTaskTraits & other);   // copy constructor

        WriteTextToConsoleTaskTraits (WriteTextToConsoleTaskTraits && other);   // copy-move constructor

        ~WriteTextToConsoleTaskTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        WriteTextToConsoleTaskTraits& operator= ( const WriteTextToConsoleTaskTraits &other ); // assignment operator

        WriteTextToConsoleTaskTraits& operator= ( WriteTextToConsoleTaskTraits && other ); // assignment-move operator
        
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

}; // -----  end of class WriteTextToConsoleTaskTraits  -----


}; // namespace ANANSI

#endif // ANANSI_WriteTextToConsoleTaskTraits_INC
