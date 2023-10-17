//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "create_path_key_propertytree.hpp"

namespace ANANSI
{

template<>
std::string create_path_key< PathKey<boost::property_tree::ptree>,
                             KeyPathSeparator> ( const std::vector<std::string> & keys )
{
    std::string path_key;
    std::vector<std::string>::size_type iter_count = 0;
    for (auto key : keys )
    {
        if (iter_count > 0)
        {
            path_key += KeyPathSeparator::separator_char[0];
        }

        path_key += key;
        
    }
    return path_key;
}

}; // namespace ANANSI

