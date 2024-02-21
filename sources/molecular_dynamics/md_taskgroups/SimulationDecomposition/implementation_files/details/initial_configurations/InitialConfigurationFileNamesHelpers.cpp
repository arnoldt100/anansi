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
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>

namespace ANANSI
{
    namespace 
    {   
        constexpr std::string_view banned_chars = ";,";

        //! \brief Returns a boolean indicating if the key for initial configuration file
        //!        name is mandatory.
        static bool is_initial_configuration_file_names_mandatory()
        {
            return true;
        };

        //! Verifies that the node value is valid.
        bool is_valid_initial_configuration_file_names_values(const std::string node_value)
        {
            bool valid_file_names = true;
            using split_vector_type = std::vector<std::string>;

            auto my_strings = STRING_UTILITIES::split_string_by_delimiter(node_value,";");
            for ( auto tmp_str : my_strings)
            {
                split_vector_type SplitVec;
                boost::split( SplitVec, tmp_str, boost::is_any_of(banned_chars), boost::token_compress_on );
                valid_file_names  = ( SplitVec.size() == 1 ) ? true  : false;
                
            }
            return valid_file_names;
        };

        std::vector<std::string> initial_configuration_filename_values(const std::string node_value)
        {
            std::vector<std::string> value{""};
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
                     std::string error_message = MessageInvalidInitialConfigurationTypeValues(a_string);
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
