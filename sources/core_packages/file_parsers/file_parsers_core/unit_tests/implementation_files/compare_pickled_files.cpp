//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <tuple>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "compare_pickled_files.h"

namespace ANANSI
{

bool compare_pickled_files (const std::map<std::string,std::string> & correct_pickle_file,
                            const std::map<std::string,std::string> & pickled_file)
{
    // This holds the 
    std::tuple<bool,std::string> ret_value;

    // Verify that map correct_pickle_file and pickled_file are equal. If they
    // are not equal, then find their difference. 
    if (correct_pickle_file == pickled_file)
    {

    } 
    return false;
}   // -----  end of function compare_pickled_files  -----


}; // namespace ANANSI

