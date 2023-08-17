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
        // Only check for a valid tag if the number of direct child
        // nodes are 0.
        if ( pt.size() == 0)
        {
            if (! master_node_keys.find(key))
            {
                std::string   error_message("The following node key in the internal boost::property_tree::ptree representation of the contol file\n");
                error_message += std::string("is not valid: ");
                error_message += key;
                error_message += std::string("\n");
                error_message += std::string("Please check the corresponding section of the control file for valid tags.\n");
                throw ControlFileNodeKeyNotFound(error_message);
            }
        }
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

