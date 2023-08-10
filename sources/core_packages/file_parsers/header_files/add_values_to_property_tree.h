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

//! \brief Stud text for brief description
void add_values_to_property_tree (const MasterControlFileNodeKeys & node_keys,
                                  const boost::property_tree::ptree & source_pt,
                                  boost::property_tree::ptree & dest_ptree);

}; // namespace ANANSI

#endif // ANANSI_add_values_to_property_tree_INC
