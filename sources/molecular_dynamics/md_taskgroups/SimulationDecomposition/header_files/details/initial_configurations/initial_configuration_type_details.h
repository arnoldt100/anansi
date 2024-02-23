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

static const std::map<std::string,std::string> valid_initial_configuration_filename_values
{
    {std::string{"Single configuration file"}, std::string{"a_water_box.initialconfiguration.coordinates"}}
};

std::string MessageInvalidInitialConfigurationTypeValues(const std::string invalid_value,
                                                         const std::string_view banned_chars);

}; // ----- End of namespace SDPConstructorHelpers ----- 
}; // ----- End of namespace ANANSI -----

#endif // ANANSI_initial_configuration_type_details_INC
