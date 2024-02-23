//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CoordinateSystemFileNameHelpers.h"
#include "check_string_for_banned_chars.h"

namespace ANANSI
{
    namespace
    {
        //! \brief Returns a boolean indicating if the key for the initial coordinate system file
        //!        name is mandatory.
        static bool is_initial_coordinate_system_file_name_mandatory()
        {
           return true;
        };

        //! Verifies that the node value is valid.
        bool is_valid_initial_configuration_file_names_values(const std::string node_value)
        {
            const std::string my_banned_chars{SDPConstructorHelpers::coordinate_system_filename_banned_chars};
            const bool found_banned_chars = STRING_UTILITIES::check_string_for_banned_chars(node_value,my_banned_chars);
            bool valid_file_name = found_banned_chars ? false : true;
            return valid_file_name;
        };
    }; // End of anonymous namespace.

    namespace SDPConstructorHelpers
    {
        std::string default_coordinate_system_file_names()
        {
            std::string filename{""};
            return filename;
        }

        std::string parse_coordinate_system_file_names(const std::string initial_configuration_filenames,
                                                       const std::string flag_default_null_value)
        {
            std::string filename;
            return filename;
        };


    };
}; // namespace ANANSI

