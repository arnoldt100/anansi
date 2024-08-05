#ifndef ANANSI_initial_configuration_type_details_INC
#define ANANSI_initial_configuration_type_details_INC

//! \file initial_configuration_type_details.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//


namespace ANANSI
{
namespace SDPConstructorHelpers
{

//! \brief Stores examples of valid initial configuration file names.
//!
//! \details The values of the map are examples of valid initial configuration
//!          file names. For a single configuration file access element with key
//!          "Single configuration file".
static const std::map<std::string,std::string> valid_initial_configuration_filename_values
{
    {std::string{"Single configuration file"}, std::string{"a_water_box.initialconfiguration.coordinates"}}
};

//! \brief Returns the error message for an invalid initial configuration file name.
//!
//! \param[in] invalid_value The invalid initial configuration file name.
//! \param[in] banned_chars The characters that aren't allowed in the file name.
std::string MessageInvalidInitialConfigurationTypeValues(const std::string invalid_value,
                                                         const std::string_view banned_chars);

}; // ----- End of namespace SDPConstructorHelpers ----- 
}; // ----- End of namespace ANANSI -----

#endif // ANANSI_initial_configuration_type_details_INC
