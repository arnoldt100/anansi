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
//! The property_tree of source_pt is copied to dest_ptree. In 
//! default null values of dest_ptree are filled in.
//!
//! \param[in] master_node_keys Conatins all valid conftrol file keys,
//! \param[in] source_ptree The property_tree to copy values from.
//! \param[out] dest_ptree The property_tree tp copy values to.
void add_values_to_property_tree (const MasterControlFileNodeKeys & master_node_keys,
                                  const boost::property_tree::ptree & source_pt,
                                  boost::property_tree::ptree & dest_ptree);

}; // namespace ANANSI

#endif // ANANSI_add_values_to_property_tree_INC
