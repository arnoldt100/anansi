#include "convert_commandline_to_vector_string_array.h"
#include <sstream>

namespace STRING_UTILITIES 
{
    std::vector<std::string> 
    convert_commandline_to_vector_string_array(std::string const & my_string)
    {
        std::vector<std::string> my_string_vector;
        std::istringstream iss(my_string);
        std::string temp_arg;
        for( std::string s; iss >> temp_arg;)
        {
            my_string_vector.push_back(temp_arg);
        }
        return my_string_vector;    
    }

} /* namespace STRING_UTILITIES */

