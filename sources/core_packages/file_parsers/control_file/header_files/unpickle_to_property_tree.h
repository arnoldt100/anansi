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
#include "MasterControlFileNodeKeys.h"


namespace ANANSI
{

//! \brief Unpickles "pickle_obj" to a property tree.
//!
//! Iterate through the keys of this->masterNodeKeys. Check if a matching is
//! found in the pickle_obj, and if a matching key is found the put key-value pair to
//! boost::property_tree. If the key is not found then add the key
//! value pair with "default-value" as the key's value.
boost::property_tree::ptree unpickle_to_property_tree(const MasterControlFileNodeKeys & keys, 
                                                      const ControlFileTraits::PICKLETYPE & pickle_obj,
                                                      const char default_value[]);

}; // namespace ANANSI

#endif // ANANSI_unpickle_to_property_tree_INC
