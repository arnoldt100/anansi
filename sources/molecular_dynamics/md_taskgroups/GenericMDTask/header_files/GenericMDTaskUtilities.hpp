#ifndef ANANSI_GenericMDTaskUtilities_INC
#define ANANSI_GenericMDTaskUtilities_INC
//! \file GenericMDTaskUtilities.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class GenericMDTaskUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================

        GenericMDTaskUtilities ();   // constructor

        GenericMDTaskUtilities (const GenericMDTaskUtilities & other);   // copy constructor

        GenericMDTaskUtilities (GenericMDTaskUtilities && other);   // copy-move constructor

        virtual ~GenericMDTaskUtilities ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericMDTaskUtilities& operator= ( const GenericMDTaskUtilities &other ); // assignment operator

        GenericMDTaskUtilities& operator= ( GenericMDTaskUtilities && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class GenericMDTaskUtilities  -----


}; // namespace ANANSI

#endif // ANANSI_GenericMDTaskUtilities_INC
