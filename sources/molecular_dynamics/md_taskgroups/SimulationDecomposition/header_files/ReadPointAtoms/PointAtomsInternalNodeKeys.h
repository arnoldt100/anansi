#ifndef ANANSI_PointAtomsInternalNodeKeys_INC
#define ANANSI_PointAtomsInternalNodeKeys_INC
//! \file PointAtomsInternalNodeKeys.h
//!
//! \brief Brief description
//!
//! \details Detailed description

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

//! This class contains the internal keys with respect to the Point Attoms configuration file.
//! 
//! The internal program keys correspond to the external node tags
//! in the point atoms input file. These internal program keys are not exposed 
//! to the program users but are intended to used by the program developers 
//! to have a consistent key throughout the program. This permits the developer 
//! the developer to reduce the dependence of the external keys of the point atoms 
//! input file.
class PointAtomsInternalNodeKeys
{
    public:
        // ====================  STATIC        =======================================
        //!  \brief This is the name of the region the atoms are in. 
        //!
        //!  \details Each atom is initially assigned to one region, and the atoms do not
        //!  necessarily have to stay in the same region throughout the program. The region name
        //!  shall have no impact of the physical properties of the simulation.
        static constexpr std::string_view Region_Name  = "region_name";

        static constexpr std::string_view Coordinate_System  = "coordinate_system";
        static constexpr std::string_view Number_Atoms_In_File = "number_atoms_in_file";
        static constexpr std::string_view X_Coordinate_Atom_i = "x_coordinate_atom::i::";
        static constexpr std::string_view Y_Coordinate_Atom_i = "y_coordinate_atom::i::";
        static constexpr std::string_view Z_Coordinate_Atom_i = "z_coordinate_atom::i::";
        static constexpr std::string_view X_Velocity_Atom_i = "x_velocity_atom::i::";
        static constexpr std::string_view Y_Velocity_Atom_i = "y_velocity_atom::i::";
        static constexpr std::string_view Z_Velocity_Atom_i = "z_velocity_atom::i::";
        static constexpr std::string_view Atom_Type_i = "Atom_Type_i::i::";
        static constexpr std::string_view Atom_Symbol_i = "Atom_Symbol::i::";
        static constexpr std::string_view Atom_Global_Atom_Index_i = "Atom_Global_Atoms_Index::i::";
        static constexpr std::string_view Atom_Global_Group_Index_i = "Atom_Global_Group_Index::i::";
        static constexpr std::string_view Atom_Group_Type_i = "Atom_Group_Type:i::";

        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        PointAtomsInternalNodeKeys ();   // constructor

        //! The copy constructor.
        PointAtomsInternalNodeKeys (const PointAtomsInternalNodeKeys & other);   // copy constructor

        //! The move constructor.
        PointAtomsInternalNodeKeys (PointAtomsInternalNodeKeys && other);   // copy-move constructor

        ~PointAtomsInternalNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        PointAtomsInternalNodeKeys * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        PointAtomsInternalNodeKeys& operator= ( const PointAtomsInternalNodeKeys &other ); // assignment operator

        //! The move assignment operator.
        PointAtomsInternalNodeKeys& operator= ( PointAtomsInternalNodeKeys && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class PointAtomsInternalNodeKeys  -----


}; // End of namespace ANANSI

#endif // ANANSI_PointAtomsInternalNodeKeys_INC
