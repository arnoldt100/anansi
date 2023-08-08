#ifndef ANANSI_add_values_to_nodekeys_INC
#define ANANSI_add_values_to_nodekeys_INC

//! \file add_values_to_nodekeys.h

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
void add_values_to_nodekeys (const MasterControlFileNodeKeys & node_keys,
                             const boost::property_tree::ptree & pt );

}; // namespace ANANSI

#endif // ANANSI_add_values_to_nodekeys_INC
