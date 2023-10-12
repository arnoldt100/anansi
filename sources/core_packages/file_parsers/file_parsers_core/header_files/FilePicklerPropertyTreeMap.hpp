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
