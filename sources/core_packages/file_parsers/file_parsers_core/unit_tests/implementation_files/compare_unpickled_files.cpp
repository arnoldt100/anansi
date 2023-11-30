//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/optional.hpp>
#include <boost/format.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "compare_unpickled_files.h"

namespace ANANSI
{

std::tuple<bool, std::string> compare_unpickled_files (const std::map<std::string,std::string> & pickle_file_A,
                                                       const boost::property_tree::ptree & ptree_B)
{
    boost::format frmter_not_found("Warning! Key not found. Testing key '%1%', Key status : '%2%'.\n");
    boost::format frmter_key_value_different("Warning! The key value pair is are not the same. Testing key '%1%'; values : '%2%', '%3%'\n");
    boost::format frmter_key_value_same("The key value pair is the same. Testing key '%1%'; values : '%2%', '%3%'\n");
    bool unpickled_correctly = true;
    std::string message;
    for (auto it = pickle_file_A.begin(); it != pickle_file_A.end(); ++it)
    {
        const std::string key = it->first;
        const auto value_A = it->second;
        boost::optional<std::string> value_B = ptree_B.get_optional<std::string>(key);
        if (value_B)
        {
            if (*value_B == value_A)
            {
                frmter_key_value_same % key.c_str() % value_A % *value_B;
                message += frmter_key_value_same.str();
            }
            else
            {
                frmter_key_value_different % key.c_str() %  value_A % *value_B;
                message += frmter_key_value_different.str();
            }
        }
        else
        {
            unpickled_correctly = false;
            frmter_not_found % key.c_str() % key.c_str() % "not present";
            message += frmter_not_found.str();
        }

    }
    return std::make_tuple(unpickled_correctly,message);
}   // -----  end of function compare_unpickled_files  -----


}; // namespace ANANSI

