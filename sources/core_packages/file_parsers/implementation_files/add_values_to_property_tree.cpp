//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/xml_parser.hpp>
#include  <boost/algorithm/string/trim.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "add_values_to_property_tree.h"

namespace ANANSI
{

void add_values_to_property_tree (const MasterControlFileNodeKeys & master_node_keys,
                                  const boost::property_tree::ptree & source_pt,
                                  const std::string default_value,
                                  boost::property_tree::ptree & dest_pt)
{
    dest_pt.clear();
    const auto  it_keys = master_node_keys.allKeysIterator();
    for (auto it = it_keys.first; it != it_keys.second; ++it)
    {
        const std::string key(*it);

        // Check if this is a comment tag. If a comment tag then ignore
        // and continue to next key.
        if ( master_node_keys.isCommentTag(key))
        {
           continue; 
        }

        std::string data = source_pt.get(key,default_value);
        boost::algorithm::trim(data);
        dest_pt.put(key.c_str(), std::as_const(data));
    }

    return ;
}   // -----  end of function add_values_to_property_tree  -----


}; // namespace ANANSI

