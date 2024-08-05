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
#include "GenericErrorClass.hpp"
#include "ErrorInvalidSimulationDecompositionParameters.h"
#include "ErrorMissingSimulationDecompositionParameters.h"
#include "coordinate_system_file_name_details.h"
#include "message_missing_mandatory_node_tag.h"
#include "check_string_for_banned_chars.h"
#include "count_words_in_string.h"

namespace ANANSI
{
    namespace
    {
        //! \brief Returns a boolean indicating if the key for the initial coordinate system file
        //!        name is mandatory.
        static bool is_coordinate_system_file_name_mandatory()
        {
           return true;
        };

        //! Verifies that the node value is valid.
        bool is_valid_coordinate_system_file_name(const std::string node_value)
        {
            bool valid_file_name = true;
            std::string my_banned_chars{SDPConstructorHelpers::coordinate_system_filename_banned_chars};

            // The node value must not contain any spaces (i.e it can only be 1 word).
            auto nm_words = STRING_UTILITIES::count_words_in_string(node_value);
            if (nm_words != 1)
            {
                valid_file_name = false;
            }
            else if ( STRING_UTILITIES::check_string_for_banned_chars(node_value,my_banned_chars) )
            {
                valid_file_name = false;
            }
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

        std::string parse_coordinate_system_file_names(const std::string coordinate_sytem_filename,
                                                       const std::string flag_default_null_value)
        {
            std::string value{""};
            try
            {
                if ( (coordinate_sytem_filename == flag_default_null_value) && 
                      is_coordinate_system_file_name_mandatory() )
                {
                     std::string error_message = 
                         message_missing_mandatory_node_tag("coordinate system file name");
                     throw ErrorMissingSimulationDecompositionParameters(error_message);
                }
                else if (is_valid_coordinate_system_file_name(coordinate_sytem_filename))
                {
                     value = coordinate_sytem_filename;
                }
                else
                {
                     std::string error_message =
                             MessageInvalidCoordinateSystemNodeValue(coordinate_sytem_filename,SDPConstructorHelpers::coordinate_system_filename_banned_chars);
                     throw ErrorInvalidSimulationDecompositionParameters(error_message);
                }
            }
            catch (const ErrorMissingSimulationDecompositionParameters & my_error)
            {
                const std::string error_message{my_error.what()};
                throw MOUSEION::GenericErrorClass<SimulationDecompositionParameters>(error_message); 
            }
            catch (const ErrorInvalidSimulationDecompositionParameters& my_error)
            {
                const std::string error_message{my_error.what()};
                throw MOUSEION::GenericErrorClass<SimulationDecompositionParameters>(error_message); 
            }

            return value;
        };


    };
}; // namespace ANANSI

