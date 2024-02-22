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
#include "initial_configuration_type_details.h"


namespace
{
//! The header for error messages.
constexpr char* ErrorMessageHeader = R"""(
# ----------------------
# Error Message
# ----------------------)""";

//! The footer for error messages.
constexpr char* ErrorMessageFooter = R"""(# ----------------------)""";

}; // End of anaonymous namespace.



namespace ANANSI
{
namespace SDPConstructorHelpers
{

std::string MessageInvalidInitialConfigurationTypeValues(const std::string invalid_value)
{
    std::string message;
    boost::format s1_frmt("%1%\n");
    boost::format s2_frmt("    %1%\n");

    // Add header message.
    s1_frmt % ErrorMessageHeader;
    message += s1_frmt.str();

    // Add warning to message.
    boost::format warning_frmt("Warning! Invalid input parameter '%1%' for initial configuration.\nValid values are the following:\n");
    warning_frmt % invalid_value.c_str();
    message += warning_frmt.str();
    for (const auto &p : valid_initial_configuration_filename_values)
    {
        s2_frmt % p.second.c_str();
        message += s2_frmt.str();
        message += "\n";
    }
    s1_frmt % "";
    message += s1_frmt.str();

    const char *warning = R"""( 
A filename can contain no whitespace characters or 
semicolons. 
)""";

    s1_frmt % warning;
    message += s1_frmt.str();

    // Add footer to message.
    s1_frmt % ErrorMessageFooter;
    message += s1_frmt.str();

    return message;
}

}; // ----- End of namespace SDPConstructorHelpers ----- 
}; // ----- End of namespace ANANSI -----

