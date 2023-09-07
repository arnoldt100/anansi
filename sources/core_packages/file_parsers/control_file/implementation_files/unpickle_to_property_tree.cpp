//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "unpickle_to_property_tree.h"

namespace ANANSI
{

boost::property_tree::ptree unpickle_to_property_tree(const MasterControlFileNodeKeys & all_keys, 
                               const ControlFileTraits::PICKLETYPE & pickle_obj,
                               const char default_value[])
{
    boost::property_tree::ptree ret_value;
    const auto it_keys = all_keys.allKeysIterator();
    for (auto it = it_keys.first; it != it_keys.second; ++it)
    {
        const std::string key(*it);
        if ( all_keys.isCommentTag(key))
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

