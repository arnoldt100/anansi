#ifndef ANANSI_FilePicklerPropertyTreeMap_INC
#define ANANSI_FilePicklerPropertyTreeMap_INC

//! \file FilePicklerPropertyTreeMap.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "FilePickler.hpp"

namespace ANANSI
{

template<>
class FilePickler<boost::property_tree::ptree, std::map<std::string,std::string>>
{
    public:
        // ====================  LIFECYCLE     =======================================

        FilePickler ();   // constructor

        FilePickler (const FilePickler & other);   // copy constructor

        FilePickler (FilePickler && other);   // copy-move constructor

        ~FilePickler ();  // destructor

        // ====================  ACCESSORS     =======================================
        FilePickler * clone () const;

       std::map<std::string,std::string> pickle(const boost::property_tree::ptree & tree) const;

       boost::property_tree::ptree unPickle(const std::map<std::string,std::string>& a_map) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        FilePickler& operator= ( const FilePickler &other ); // assignment operator

        FilePickler& operator= ( FilePickler && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class FilePickler  -----


}; // namespace ANANSI

#endif // ANANSI_FilePickler_INC
