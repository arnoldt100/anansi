#ifndef ANANSI_verify_controlfile_keys_are_valid_INC
#define ANANSI_verify_controlfile_keys_are_valid_INC

//! \file verify_controlfile_keys_are_valid.h

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
#include "MasterControlInputFileNodeKeys.h"


namespace ANANSI
{

//! \brief Verifies that the node keys in property tree, pt, are found in MasterControlInputFileNodeKeys.
//!
//! Each node key in pt is checked for existence in MasterControlInputFileNodeKeys. If the
//! key is not found in MasterControlInputFileNodeKeys, then the error ControlFileNodeKeyNotFound is
//! thrown.
//! 
//! \param[in] master_node_keys Contains the master node keys.
//! \param[in] pt A property_tree of which the node keys are checked against master_node_keys.
//!
//! \throws ControlFileNodeKeyNotFound
void verify_controlfile_keys_are_valid (const MasterControlInputFileNodeKeys & master_node_keys,
                                        const boost::property_tree::ptree & pt );

void parse_tree(const MasterControlInputFileNodeKeys & master_node_keys,const boost::property_tree::ptree & pt, std::string key);

}; // namespace ANANSI

#endif // ANANSI_verify_controlfile_keys_are_valid_INC
