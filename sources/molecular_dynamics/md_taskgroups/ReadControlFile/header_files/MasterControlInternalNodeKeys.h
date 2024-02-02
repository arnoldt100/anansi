#ifndef ANANSI_MasterControlInternalNodeKeys_INC
#define ANANSI_MasterControlInternalNodeKeys_INC
//! \file MasterControlInternalNodeKeys.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string_view>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

//! This class contains the internal keys wit respect to the master control file.
class MasterControlInternalNodeKeys
{
    public:
        // ====================  LIFECYCLE     =======================================

        MasterControlInternalNodeKeys ();   // constructor

        MasterControlInternalNodeKeys (const MasterControlInternalNodeKeys & other);   // copy constructor

        MasterControlInternalNodeKeys (MasterControlInternalNodeKeys && other);   // copy-move constructor

        virtual ~MasterControlInternalNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================

        MasterControlInternalNodeKeys * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MasterControlInternalNodeKeys& operator= ( const MasterControlInternalNodeKeys &other ); // assignment operator

        MasterControlInternalNodeKeys& operator= ( MasterControlInternalNodeKeys && other ); // assignment-move operator


        static constexpr std::string_view Simulation_Workload_Decomposition_Type = "Simulation_Workload_Decomposition_Type";

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MasterControlInternalNodeKeys  -----


}; // namespace ANANSI

#endif // ANANSI_MasterControlInternalNodeKeys_INC
