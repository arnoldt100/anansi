
#ifndef  ANANSI_ReadControlFileTraits_INC
#define  ANANSI_ReadControlFileTraits_INC

//! @file ReadControlFileTraits.h
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
#include "GenericMDTask.hpp"

// Includes for abstract tasks.
#include "ControlFile.h"
#include "ControlFileCommunicator.h"
#include "MacroCommand.hpp"

// Includes for concrete tasks receivers.
#include "ControlFileXMLReceiver.h"
#include "ControlFileXMLMPICommReceiver.h"
#include "ControlFileMacroReceiver.h"

namespace ANANSI
{

class ReadControlFileTraits
{
    private: 
        using MC_ = MacroCommand<ControlFile,ControlFileCommunicator>;

    public:

        // ====================  LIFECYCLE     =======================================

        ReadControlFileTraits ();   // constructor

        ReadControlFileTraits (const ReadControlFileTraits & other);   // copy constructor

        ReadControlFileTraits (ReadControlFileTraits && other);   // copy-move constructor

        ~ReadControlFileTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ReadControlFileTraits& operator= ( const ReadControlFileTraits &other ); // assignment operator

        ReadControlFileTraits& operator= ( ReadControlFileTraits && other ); // assignment-move operator

        using abstract_products = MPL::mpl_typelist<
                                                       ControlFile,
                                                       ControlFileCommunicator,
                                                       MC_
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                       GenericMDTask<ControlFile,ControlFileXMLReceiver>,
                                                       GenericMDTask<ControlFileCommunicator,ControlFileXMLMPICommReceiver>,
                                                       GenericMDTask<MC_,ControlFileMacroReceiver>
                                                   >;

        using receiver_results_t = MPL::mpl_typelist<
                                                    	ControlFileXMLReceiver::receiver_result_t,
                                                        ControlFileXMLMPICommReceiver::receiver_result_t,
                                                        ControlFileMacroReceiver::receiver_result_t
                                                     >;

        static constexpr auto LABELS = std::array{
                                                    ControlFileXMLReceiver::TASKLABEL,
                                                    ControlFileXMLMPICommReceiver::TASKLABEL,
                                                    ControlFileMacroReceiver::TASKLABEL
                                                 };

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ReadControlFileTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ReadControlFileTraits_INC  ----- 
