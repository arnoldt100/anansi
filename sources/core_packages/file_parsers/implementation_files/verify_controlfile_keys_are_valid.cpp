//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "verify_controlfile_keys_are_valid.h"
#include "ControlFileNodeKeyNotFound.h"

namespace ANANSI
{

//! Verifies that the node keys in property tree, pt, are valid keys.
//!
//! The node keys in property tree pt are checked for existence against
//! master_node_keys. If a node key in property tree pt isn't found in master_node_keys, then an
//! exception is thrown.
void verify_controlfile_keys_are_valid (const MasterControlFileNodeKeys & master_node_keys,
                                        const boost::property_tree::ptree & pt )
{

    for(auto it = pt.begin(); it != pt.end(); ++it)
    {
        parse_tree(master_node_keys,it->second,it->first);
        // if ( it == pt.not_found() )
        // {
        //     throw ControlFileNodeKeyNotFound(); 
        // }
    }

    return;
}   // -----  end of function verify_controlfile_keys_are_valid  -----

void parse_tree (const MasterControlFileNodeKeys & master_node_keys, const boost::property_tree::ptree & pt, std::string key)
{   
    std::string nextkey;

    if (!key.empty())
    {
      // The full-key/value pair for this node is
      // key / pt.data()
      // So do with it what you need
      std::cout << "pt node: " << key.c_str() << std::endl;
      std::cout << "Number of direct child nodes: " << pt.size() << std::endl;
      std::cout << "pt value: " << pt.data() << std::endl;
      std::cout << std::endl;
      nextkey = key + ".";  // More work is involved if you use a different path separator
    }

    boost::property_tree::ptree::const_iterator end = pt.end();
    for (boost::property_tree::ptree::const_iterator it = pt.begin(); it != end; ++it)
    {
      parse_tree(master_node_keys,it->second, nextkey + it->first);
    }
    return;
}

}; // namespace ANANSI

