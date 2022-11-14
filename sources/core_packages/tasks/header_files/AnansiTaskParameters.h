#ifndef  ANANSI_AnansiTaskParameters_INC
#define  ANANSI_AnansiTaskParameters_INC

//! @file __filename__
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

namespace ANANSI
{

class AnansiTaskParameters
{
    public:
        // ====================  LIFECYCLE     =======================================

        AnansiTaskParameters ();   // constructor

        AnansiTaskParameters (const AnansiTaskParameters & other);   // copy constructor

        AnansiTaskParameters (AnansiTaskParameters && other);   // copy-move constructor

        ~AnansiTaskParameters ();  // destructor


        // ====================  ALAISES       =======================================
        using task_size_t = MPL::mpl_size_type;
        
        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        AnansiTaskParameters& operator= ( const AnansiTaskParameters &other ); // assignment operator

        AnansiTaskParameters& operator= ( AnansiTaskParameters && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class AnansiTaskParameters  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_AnansiTaskParameters_INC  ----- 
