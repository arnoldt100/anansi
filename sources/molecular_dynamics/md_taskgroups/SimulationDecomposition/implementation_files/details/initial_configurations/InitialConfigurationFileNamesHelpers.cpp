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

namespace ANANSI
{
    namespace 
    {   
        //! \brief Returns a boolean indicating if the key for initial configuration file
        //!        name is mandatory.
        static bool is_initial_configuration_file_names_mandatory()
        {
            return true;
        };

        //! Verifies that the node value is valid.
        bool is_valid_initial_configuration_file_names_values(const std::string node_value)
        {
            return false;
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
