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
#include "processor_lattice_type_details.h"

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


std::string MessageInvalidProcessorTopologyLatticeTypeValues(const std::string invalid_value)
{
    std::string message;

    boost::format s1_frmt("%1%\n");
    boost::format s2_frmt("    %1%\n");

    // Add header message.
    s1_frmt % ErrorMessageHeader;
    message += s1_frmt.str();

    // Add warning to message.
    boost::format warning_frmt("Warning! Invalid input parameter '%1%' for lattice topology type.\nValid values are the following:\n");
    warning_frmt % invalid_value.c_str();
    message += warning_frmt.str();
    for (const auto &p : valid_processor_topology_lattice_type_values)
    {
        s2_frmt % p.first.c_str();
        message += s2_frmt.str();
    }
    s1_frmt % "";
    message += s1_frmt.str();

    // Add footer to message.
    s1_frmt % ErrorMessageFooter;
    message += s1_frmt.str();
    return message;
}


}; // End of namespace SDPConstructorHelpers
}; // End of namespace ANANSI

