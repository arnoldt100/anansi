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

void verify_controlfile_keys_are_valid (const MasterControlFileNodeKeys & master_node_keys,
                                        const boost::property_tree::ptree & pt )
{
    auto keys = master_node_keys.allKeysIterator();
    for(; keys.first != keys.second; keys.first++)
    {
        const auto node_key = (keys.first)->c_str();
        boost::property_tree::ptree::const_assoc_iterator it = pt.find(node_key);
        if ( it == pt.not_found()  )
        {
            throw ControlFileNodeKeyNotFound(); 
        }
    }

    return;
}   // -----  end of function verify_controlfile_keys_are_valid  -----


}; // namespace ANANSI

