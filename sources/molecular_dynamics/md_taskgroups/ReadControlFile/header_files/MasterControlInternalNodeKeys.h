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

//! This class contains the internal keys with respect to the master control file.
//! 
//! The internal program keys correspond to the external node tags
//! in the master control input file. These internal program keys are not exposed 
//! to the program users but are intended to used by the program developers 
//! to have a consistent key throughout the program. This permits the developer 
//! the developer to reduce the dependence of the extenal keys in the master control
//! input file within the program.
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

        //! The internal key for the the simulation title
        static constexpr std::string_view Simulation_Title = "Simulation_Title";

        //! The internal key for the the type of workload decomposition.
        static constexpr std::string_view Simulation_Workload_Decomposition_Type = "Simulation_Workload_Decomposition_Type";

        // The internal key for the processor topology lattice type.
        static constexpr std::string_view Simulation_Processor_Lattice_Topology = "Simulation_Processor_Lattice_Topology";

        // The internal key for the workload processor spatial decomposition.
        static constexpr std::string_view Simulation_Processor_Spatial_Decomposition = "Simulation_Processor_Spatial_Decomposition";

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MasterControlInternalNodeKeys  -----


}; // namespace ANANSI

#endif // ANANSI_MasterControlInternalNodeKeys_INC
