#ifndef ANANSI_FilePicklerPropertyTreePointAtoms_INC
#define ANANSI_FilePicklerPropertyTreePointAtoms_INC
//! \file FilePicklerPropertyTreePointAtoms.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "FilePickler.hpp"
#include "Atoms.hpp"

namespace ANANSI
{

template<>
class FilePickler<boost::property_tree::ptree,Atoms>
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        FilePickler ();   // constructor

        //! The copy constructor.
        FilePickler (const FilePickler & other);   // copy constructor

        //! The move constructor.
        FilePickler (FilePickler && other);   // copy-move constructor

        ~FilePickler ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        FilePickler * clone () const;

        template<typename MasterPolicy_t>
        Atoms pickle(const boost::property_tree::ptree & tree) const 
        {
            Atoms my_atoms{typename MasterPolicy_t::InternalRepresentationTrait()};
            return my_atoms;
        }

        template<typename MasterPolicy_t>
        boost::property_tree::ptree unPickle( const Atoms & my_point_atoms) const
        {
            boost::property_tree::ptree tree;
            return tree;
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        FilePickler& operator= ( const FilePickler &other ); // assignment operator

        //! The move assignment operator.
        FilePickler& operator= ( FilePickler && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class FilePickler  -----


}; // End of namespace ANANSI

#endif // ANANSI_FilePicklerPropertyTreePointAtoms_INC
