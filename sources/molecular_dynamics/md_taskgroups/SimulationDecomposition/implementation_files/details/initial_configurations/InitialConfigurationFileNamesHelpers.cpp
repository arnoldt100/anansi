//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "InitialConfigurationFileNamesHelpers.h"
#include "GenericErrorClass.hpp"
#include "ErrorInvalidSimulationDecompositionParameters.h"
#include "ErrorMissingSimulationDecompositionParameters.h"
#include "initial_configuration_type_details.h"
#include "message_missing_mandatory_node_tag.h"
#include "split_string_by_delimiter.h"
#include "check_string_for_banned_chars.h"

namespace ANANSI
{
    namespace 
    {

        //! \brief Returns a boolean indicating if the key for the initial configuration file
        //!        name is mandatory.
        static bool is_initial_configuration_file_names_mandatory()
        {
            return true;
        };

        //! \brief Splits a string with respect to separator characters defined by
        //!        SDPConstructorHelpers::initial_configuration_file_names_separator_char.
        //!
        //! \details Adjacent separator characters are combined and then the split is performed.
        //!          If there is no split, then the original input string is returned as a single
        //!          vector element.
        //!
        //! \return A vector string of input file names.
        std::vector<std::string> split_string_by_separator_chars(const std::string a_str)
        {
            const std::string my_separator_chars{SDPConstructorHelpers::initial_configuration_file_names_separator_char};
            auto my_strings = STRING_UTILITIES::split_string_by_delimiter(a_str,my_separator_chars);
            return my_strings;
        };


        //! Verifies that the node value is valid.
        bool is_valid_initial_configuration_file_names_values(const std::string node_value)
        {
            bool valid_file_names = true;
            const std::string my_banned_chars{SDPConstructorHelpers::initial_configuration_filename_banned_chars};
            auto my_strings = split_string_by_separator_chars(node_value);
            for ( auto tmp_str : my_strings)
            {
                const bool found_banned_chars = STRING_UTILITIES::check_string_for_banned_chars(tmp_str,my_banned_chars);
                if (found_banned_chars)
                {
                    valid_file_names = false;
                    break;
                }
            }
            return valid_file_names;
        };

        std::vector<std::string> initial_configuration_filename_values(const std::string node_value)
        {
            std::vector<std::string> value = split_string_by_separator_chars(node_value);
            return value;
        };

    }; // End of anonymous namespace

    namespace SDPConstructorHelpers 
    {

        std::vector<std::string> parse_initial_configuration_file_names(std::string a_string,
                                                                        const std::string flag_default_null_value)
        {
            std::vector<std::string> value{""};
            try
            {
                if ( (a_string == flag_default_null_value) && 
                      is_initial_configuration_file_names_mandatory() )
                {
                     std::string error_message = 
                         message_missing_mandatory_node_tag("initial configuration file names");
                     throw ErrorMissingSimulationDecompositionParameters(error_message);
                }
                else if (is_valid_initial_configuration_file_names_values(a_string))
                {
                     value = initial_configuration_filename_values(a_string);
                }
                else
                {
                     std::string error_message =
                             MessageInvalidInitialConfigurationTypeValues(a_string,SDPConstructorHelpers::initial_configuration_filename_banned_chars);
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

        std::vector<std::string> default_initial_configuration_file_names()
        {
            std::vector<std::string> value{""};
            return value;
        };
    }; // ----- Eod of namespace SDPConstructorHelpers ----- 

} // ----- End of namespace ANANSI -----
