//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "boost/format.hpp"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "coordinate_system_file_name_details.h"


namespace
{
//! The header for error messages.
constexpr char* ErrorMessageHeader = R"""(
# ----------------------
# Error Message
# ----------------------)""";

//! The footer for error messages.
constexpr char* ErrorMessageFooter = R"""(# ----------------------)""";

}; // End of anonymous namespace.

namespace ANANSI
{

namespace SDPConstructorHelpers
{

std::string MessageInvalidCoordinateSystemNodeValue ( const std::string invalid_value,
                                                      const std::string_view banned_chars)
{

    std::string message;
    boost::format s1_frmt("%1%\n");
    boost::format s2_frmt("    %1%\n");

    // Add header message.
    s1_frmt % ErrorMessageHeader;
    message += s1_frmt.str();

    // Add warning to message.
    boost::format warning_frmt("Warning! Invalid input parameter '%1%' for initial coordinate system file name.\nValid values are the following:\n");
    warning_frmt % invalid_value.c_str();
    message += warning_frmt.str();
    for (const auto &p : valid_coordinate_system_file_names)
    {
        s2_frmt % p.second.c_str();
        message += s2_frmt.str();
    }
    s1_frmt % "";
    message += s1_frmt.str();

    const char *warning1 = R"""( 
A filename can contain none of the following characters:
)""";
    s1_frmt % warning1;
    message += s1_frmt.str();

    s2_frmt % std::string{banned_chars}.c_str();
    message += s2_frmt.str();

    s1_frmt % "";
    message += s1_frmt.str();

    // Add footer to message.
    s1_frmt % ErrorMessageFooter;
    message += s1_frmt.str();

    return message;

};

};


}; // namespace ANANSI

