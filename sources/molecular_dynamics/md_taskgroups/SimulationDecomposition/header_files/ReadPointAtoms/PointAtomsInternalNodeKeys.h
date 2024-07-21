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
#include <string>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

//! This class contains the internal keys with respect to the Point Atoms configuration file.
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
        //!  \brief This is the internal key name for the  region name the atoms are in.
        //!
        //! \details Each atom is initially assigned to one region, and the atoms do not
        //! necessarily have to stay in the same region throughout the program. The region name
        //! in itself shall have no impact of the physical properties of the simulation. However, atoms
        //! in a region may be subject to constraints that may affect the physical properties
        //! of the system.
        static constexpr std::string_view Region_Name = "Region_Name";

        //!  \brief This is the internal key name for the type of coordinate system.
        static constexpr std::string_view Coordinate_System = "Coordinate_System";

        //!  \brief This is the internal key name for the number of atoms in a coordinate file.
        static constexpr std::string_view Number_Atoms_In_File = "Number_of_Atoms_In_File";

        static constexpr std::string_view i_Atom_Type = "i_Atom_Type";

        // static constexpr std::string_view X_Coordinate_Atom_i = "x_coordinate_atom::i::";
        // static constexpr std::string_view Y_Coordinate_Atom_i = "y_coordinate_atom::i::";
        // static constexpr std::string_view Z_Coordinate_Atom_i = "z_coordinate_atom::i::";
        // static constexpr std::string_view X_Velocity_Atom_i = "x_velocity_atom::i::";
        // static constexpr std::string_view Y_Velocity_Atom_i = "y_velocity_atom::i::";
        // static constexpr std::string_view Z_Velocity_Atom_i = "z_velocity_atom::i::";
        // static constexpr std::string_view Atom_Symbol_i = "Atom_Symbol::i::";
        // static constexpr std::string_view Atom_Global_Atom_Index_i = "Atom_Global_Atoms_Index::i::";
        // static constexpr std::string_view Atom_Global_Group_Index_i = "Atom_Global_Group_Index::i::";
        // static constexpr std::string_view Atom_Group_Type_i = "Atom_Group_Type:i::";

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

        std::string getInternalNodeKey(const std::string_view & global_key) const;

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
        
        // ====================  MUTATORS      =======================================
        void setAllKeys_();

        // ====================  DATA MEMBERS  =======================================
        std::map<std::string,std::string> myKeys_;

        // ====================  HIDDEN FRIENDS=======================================
        friend std::string get_internal_node_key(PointAtomsInternalNodeKeys const & internal_node_keys, std::string_view const & global_key) 
        {
            return internal_node_keys.getInternalNodeKey(global_key);
        }

}; // -----  End of class PointAtomsInternalNodeKeys  -----


}; // End of namespace ANANSI

#endif // ANANSI_PointAtomsInternalNodeKeys_INC
