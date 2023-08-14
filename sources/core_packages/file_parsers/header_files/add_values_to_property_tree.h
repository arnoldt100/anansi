#ifndef ANANSI_add_values_to_property_tree_INC
#define ANANSI_add_values_to_property_tree_INC

//! \file add_values_to_property_tree.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MasterControlFileNodeKeys.h"

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
void add_values_to_property_tree (const MasterControlFileNodeKeys & master_node_keys,
                                  const boost::property_tree::ptree & source_pt,
                                  const std::string default_value,
                                  boost::property_tree::ptree & dest_ptree);

}; // namespace ANANSI

#endif // ANANSI_add_values_to_property_tree_INC
