//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "add_values_to_property_tree.h"

namespace ANANSI
{

void add_values_to_property_tree (const MasterControlFileNodeKeys & master_node_keys,
                                  const boost::property_tree::ptree & source_pt,
                                  boost::property_tree::ptree & dest_pt)
{
    const auto  it_keys = master_node_keys.allKeysIterator();
    for (auto it = it_keys.first; it != it_keys.second; ++it)
    {
        const std::string key(*it);
        // Check if the key is in source_pt. If the key get value and put 
        // to dest_pt.
        if ( source_pt.find(key) == source_pt.not_found() )
        {
            const auto data = source_pt.get<std::string>(key.c_str());
            dest_pt.put(key.c_str(), data);
        }
    }
    return ;
}   // -----  end of function add_values_to_property_tree  -----


}; // namespace ANANSI

