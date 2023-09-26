#ifndef ANANSI_unpickle_to_property_tree_INC
#define ANANSI_unpickle_to_property_tree_INC

//! \file unpickle_to_property_tree.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFileTraits.h"


namespace ANANSI
{

//! \brief Unpickles "pickle_obj" to a property tree.
//!
//! Check if a matching is
//! found in the pickle_obj, and if a matching key is found the put key-value pair to
//! boost::property_tree. If the key is not found then add the key
//! value pair with "default-value" as the key's value.
template<typename T >
boost::property_tree::ptree unpickle_to_property_tree(const T & master_keys, 
                                                      const ControlFileTraits::PICKLETYPE & pickle_obj,
                                                      const char default_value[])
{
    boost::property_tree::ptree ret_value;
    const auto it_keys = master_keys.allKeysIterator();
    for (auto it = it_keys.first; it != it_keys.second; ++it)
    {
        const std::string key(*it);
        if ( master_keys.isCommentTag(key))
        {
           continue; 
        }
        
        if (auto search = pickle_obj.find(key); search != pickle_obj.end() )
        {
            ret_value.put(key,pickle_obj.at(key));
        }
        else
        {
            ret_value.put(key,default_value);
        }
    }

    return ret_value;
}   // -----  end of function unpickle_to_property_tree  -----

}; // namespace ANANSI

#endif // ANANSI_unpickle_to_property_tree_INC
