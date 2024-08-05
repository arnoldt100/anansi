#ifndef ANANSI_coordinate_system_file_name_details_INC
#define ANANSI_coordinate_system_file_name_details_INC

//! \file coordinate_system_file_name_details.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>
#include <string>

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
static const std::map<std::string,std::string> valid_coordinate_system_file_names
{
    {std::string{"Single configuration file"}, std::string{"a_water_box.coordinatesystem"}}
};

std::string MessageInvalidCoordinateSystemNodeValue ( const std::string invalid_value,
                                                      const std::string_view banned_chars);

};
}; // namespace ANANSI

#endif // ANANSI_coordinate_system_file_name_details_INC
