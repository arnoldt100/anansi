#ifndef ANANSI_FilePicklerPropertyTreeMap_INC
#define ANANSI_FilePicklerPropertyTreeMap_INC

//! \file FilePicklerPropertyTreeMap.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "FilePickler.hpp"
#include "NodeKeys.h"

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

        //! \brief Converts the a boost::property_tree::ptree to a
        //! std::map<std::string,std::string>.
        //!
        //! \details The internal representation of a command file is
        //!  boost::property_tree::ptree. There are occasional needs to
        //!  represent the command file in the form of std::map\<std::string,std::string\> for easier
        //!  manipulation. For example, MPI communicators can't communicate
        //!  ptree data types, but they can communicate a std::string by
        //!  converting std::string to a 'char*' data types.
        //!
        //! \tparam MasterKeyPolicy_t The policy for the key types of the command file.
        //! \param[in] tree The internal representation of the command file.
        //! \return  The internal representation of a command file.<br>   
        //! The internal representation of a command file is form std::map\<std::string,std::string\>.
        //! A (key,value) entry in ptree is acccessd by <br>  
        //! &emsp; <TT>value = tree.get<std::string>(key)</TT>
        //! <br>  
        //! We store this (key,value) in the std::map<std::string,std::string> as <br>  
        //! &emsp;  <TT>a_map[key] = tree.get\<std::string\>(key)</TT> <br>   
        template<typename MasterKeyPolicy_t>
        std::map<std::string,std::string> pickle(const boost::property_tree::ptree & tree) const
        {
            using path = boost::property_tree::ptree::path_type;
            std::map<std::string,std::string> a_map;
            NodeKeys node_keys(MasterKeyPolicy_t{});
            auto it_keys = all_keys_iterator(node_keys);
            const std::array<char,2> sep_char = separator_char(node_keys);
            const std::string default_value = default_null_value(node_keys);

            for (auto it = it_keys.first; it != it_keys.second; ++it)
            {
                const std::string key(*it);
                if ( is_comment_key(node_keys,key))
                {
                   continue; 
                }
                std::string tmp_str = tree.get<std::string>(path(key,sep_char[0]), default_value);
                boost::algorithm::trim(tmp_str);
                a_map[key] = tmp_str;
            }
            return a_map;
        }

        template<typename MasterKeyPolicy_t>
        boost::property_tree::ptree unPickle(const std::map<std::string,std::string>& a_map) const
        {
            const MasterKeyPolicy_t master_keys;
            boost::property_tree::ptree tree;
            const NodeKeys node_keys(MasterKeyPolicy_t{});
            const std::string default_value = default_null_value(node_keys);
            auto it_keys = all_keys_iterator(node_keys);
            for (auto it = it_keys.first; it != it_keys.second; ++it)
            {
                std::string key(*it);
                boost::algorithm::trim(key);
                if ( is_comment_key(node_keys,key))
                {
                   continue; 
                }
               
                std::string value;
                if (auto search = tree.find(key); search != tree.not_found() )
                {
                    value = a_map.at(key);
                }
                else
                {
                    value = default_value;
                }
                boost::algorithm::trim(value);
                tree.put(key,value);
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
