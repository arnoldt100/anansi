//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "verify_controlfile_keys_are_valid.h"
#include "ControlFileNodeKeyNotFound.h"

namespace ANANSI
{

//! Verifies that the node keys in property tree, pt, are valid keys.
//!
//! The node keys in property tree pt are checked for existence against
//! master_node_keys. If a node key in property tree pt isn't found in master_nod_keys, then an
//! exception is thrown.
void verify_controlfile_keys_are_valid (const MasterControlFileNodeKeys & master_node_keys,
                                        const boost::property_tree::ptree & pt )
{
    for(auto it = pt.begin(); pt.begin() != pt.end(); ++it)
    {


        // if ( it == pt.not_found() )
        // {
        //     throw ControlFileNodeKeyNotFound(); 
        // }
    }

    return;
}   // -----  end of function verify_controlfile_keys_are_valid  -----


}; // namespace ANANSI

