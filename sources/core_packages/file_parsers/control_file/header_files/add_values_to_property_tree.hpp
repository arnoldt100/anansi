#ifndef ANANSI_add_values_to_property_tree_INC
#define ANANSI_add_values_to_property_tree_INC

//! \file add_values_to_property_tree.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include  <boost/algorithm/string/trim.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

//! \brief Copies the data form source_pt to dest_pt.
//!
//! The property_tree of source_pt is used to fill in property_tree dest_ptree.
//!
//! \param[in] master_node_keys Conatins all valid conftrol file keys,
//! \param[in] source_ptree The property_tree to copy values from.
//! \param[in] default_value The default value for the property tree.
//! \param[out] dest_ptree The property_tree to be filled in.
template<typename T>
void add_values_to_property_tree (const T & master_node_keys,
                                  const boost::property_tree::ptree & source_ptree,
                                  const std::string default_value,
                                  boost::property_tree::ptree & dest_ptree)
{
    dest_ptree.clear();
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

        std::string data = source_ptree.get(key,default_value);
        boost::algorithm::trim(data);
        dest_ptree.put(key.c_str(), std::as_const(data));
    }

    return ;
}   // -----  end of function add_values_to_property_tree  -----

}; // namespace ANANSI

#endif // ANANSI_add_values_to_property_tree_INC
