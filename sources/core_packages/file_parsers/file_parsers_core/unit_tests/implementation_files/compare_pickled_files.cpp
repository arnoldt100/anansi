//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <tuple>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/format.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "compare_pickled_files.h"

namespace ANANSI
{

namespace {

    std::string difference_between_pickled_files(const std::map<std::string,std::string> & pickle_file_A,
                                                 const std::map<std::string,std::string> & pickled_file_B)
    {
        boost::format frmter_found("Testing key '%1%', Key status : '%2%'.\n");
        boost::format frmter_not_found("Warning! Key not found. Testing key '%1%', Key status : '%2%'.\n");
        boost::format frmter_key_value_different("Warning! The key value pair is are not the same. Testing key '%1%'; values : '%2%', '%3%'\n");
        boost::format frmter_key_value_same("The key value pair is the same. Testing key '%1%'; values : '%2%', '%3%'\n");

        std::string message = "The pickled files aren't the same.\n\n";
        for (auto it = pickle_file_A.begin(); it != pickle_file_A.end(); ++it)
        {
            const std::string key = it->first;
            const auto value_A = it->second;
            if ( auto search = pickled_file_B.find(it->first); search != pickled_file_B.end() )
            {
                const auto value_B = search->second;

                if ( value_A == value_B)
                {
                    frmter_key_value_same % key.c_str() % value_A % value_B;
                    message += frmter_key_value_same.str();
                }
                else
                {
                    frmter_key_value_different % key.c_str() %  value_A % value_B;
                    message += frmter_key_value_different.str();
                }
            }
            else
            {
                frmter_not_found % key.c_str() % "not present";
                message += frmter_not_found.str();
            }
        }
        return message;
    }
}

std::tuple<bool,std::string> compare_pickled_files (const std::map<std::string,std::string> & correct_pickled_file,
                                                    const std::map<std::string,std::string> & pickled_file)
{
    // This tuple stores the boolean value of the comparison of the pickled files
    // and a descriptive message of the pickled files comparison.
    std::tuple<bool,std::string> ret_value;
    std::string diff_msg;

    // Verify that map correct_pickled_file and pickled_file are equal. If they
    // are not equal, then find their difference. 
    if (correct_pickled_file == pickled_file)
    {
        ret_value = std::make_tuple(true,"The pickled files are the same.");
    } 
    else
    {
        boost::format frmter_header("\n\nTesting if key-value pairs in pickled file '%1%' are the same as in '%2%':\n");

        frmter_header % "correct_pickled_file" % "pickled_file";
        diff_msg += frmter_header.str();
        diff_msg += ANANSI::difference_between_pickled_files(correct_pickled_file,pickled_file);

        frmter_header % "pickled_file" % "correct_pickled_file";
        diff_msg += frmter_header.str();
        diff_msg += ANANSI::difference_between_pickled_files(pickled_file,correct_pickled_file);

        ret_value = std::make_tuple(false,diff_msg.c_str());
    }

    return ret_value;
}   // -----  end of function compare_pickled_files  -----


}; // namespace ANANSI

