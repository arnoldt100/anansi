
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
#include "ControlFile.h"
#include "ControlFileCommunicator.h"
#include "GenericMDTask.hpp"
#include "DefaultFunctorImpl.h"
#include "ControlFileXMLReceiver.h"
#include "ControlFileXMLMPICommReceiver.h"

namespace ANANSI
{

class ReadControlFileTraits
{
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
                                                       ControlFileCommunicator
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                       GenericMDTask<ControlFile,ControlFileXMLReceiver>,
                                                       GenericMDTask<ControlFileCommunicator,ControlFileXMLMPICommReceiver>
                                                   >;
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ReadControlFileTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ReadControlFileTraits_INC  ----- 
