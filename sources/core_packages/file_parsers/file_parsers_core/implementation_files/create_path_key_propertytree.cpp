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
    return "";
}

}; // namespace ANANSI

