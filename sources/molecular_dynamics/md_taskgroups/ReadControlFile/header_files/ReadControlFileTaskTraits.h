
#ifndef  ANANSI_ControlFileMPIXMLTraits_INC
#define  ANANSI_ControlFileMPIXMLTraits_INC

//! @file ControlFileMPIXMLTraits.h
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
#include "GenericMDTask.hpp"
#include "DefaultFunctorImpl.h"
#include "ControlFileMPIXMLReceiver.h"

namespace ANANSI
{

class ControlFileMPIXMLTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFileMPIXMLTraits ();   // constructor

        ControlFileMPIXMLTraits (const ControlFileMPIXMLTraits & other);   // copy constructor

        ControlFileMPIXMLTraits (ControlFileMPIXMLTraits && other);   // copy-move constructor

        ~ControlFileMPIXMLTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileMPIXMLTraits& operator= ( const ControlFileMPIXMLTraits &other ); // assignment operator

        ControlFileMPIXMLTraits& operator= ( ControlFileMPIXMLTraits && other ); // assignment-move operator

        using abstract_products = MPL::mpl_typelist<
                                                       ControlFile
                                                   >;

        using concrete_products = MPL::mpl_typelist<
                                                       GenericMDTask<ControlFile,ControlFileMPIXMLReceiver>
                                                   >;
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFileMPIXMLTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileMPIXMLTraits_INC  ----- 
