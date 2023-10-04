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

        template<typename MasterKeyPolicy_t>
        std::map<std::string,std::string> pickle(const boost::property_tree::ptree & tree) const
        {
            const MasterKeyPolicy_t master_keys;
            std::map<std::string,std::string> a_map;
            const auto it_keys = master_keys.allKeysIterator();
            for (auto it = it_keys.first; it != it_keys.second; ++it)
            {
                const std::string key(*it);
                if ( master_keys.isCommentTag(key))
                {
                   continue; 
                }

                if (auto search = tree.find(key); search != tree.not_found() )
                {
                    a_map[key] = tree.get<std::string>(key);
                }
                else
                {
                    a_map[key] = master_keys.DefaultNullValue;
                }
            }
            return a_map;
        }

        template<typename MasterKeyPolicy_t>
        boost::property_tree::ptree unPickle(const std::map<std::string,std::string>& a_map) const
        {
            const MasterKeyPolicy_t master_keys;
            boost::property_tree::ptree tree;
            const auto it_keys = master_keys.allKeysIterator();
            for (auto it = it_keys.first; it != it_keys.second; ++it)
            {
                const std::string key(*it);
                if ( master_keys.isCommentTag(key))
                {
                   continue; 
                }
                
                if (auto search = tree.find(key); search != tree.not_found() )
                {
                    tree.put(key,a_map.at(key));
                }
                else
                {
                    tree.put(key,master_keys.DefaultNullValue);
                }
            }
            return tree;
        }

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
