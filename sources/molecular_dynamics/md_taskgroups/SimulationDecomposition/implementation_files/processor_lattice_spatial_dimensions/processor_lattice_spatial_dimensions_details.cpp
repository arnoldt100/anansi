//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/format.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "processor_lattice_spatial_dimensions_details.h"

namespace
{
constexpr char* ErrorMessageHeader_ = R"""(
# ----------------------
# Error Message
# ----------------------)""";

//! The footer for error messages.
constexpr char* ErrorMessageFooter_ = R"""(# ----------------------)""";

};

namespace ANANSI
{
namespace SDPConstructorHelpers {

std::string MessageInvalidProccesorTopologyLatticeSpatialDimensions(const std::string invalid_value)
{
    std::string message;

    
    // Add header to message.
    boost::format s1_frmt("%1%\n");
    s1_frmt % ErrorMessageHeader_;
    message += s1_frmt.str();

    boost::format warning_frmt0("Warning! Invalid input parameter '%1%' for lattice topology spatial dimenssions.\n");
    warning_frmt0 % invalid_value.c_str();
    message += warning_frmt0.str();

    // Add warning. We store the warning message in  raw string literal.
    const char* warning = R"""(
The input parameter must have form  of '<spaces>a<spaces>b<spaces>c<spaces>' where
    - <spaces> is whitespace
    - a, b and c are positive integers
    - There must be at least one space between integers a and b
    - There must be at least one space between integers b and c
    - There can be any numbers spaces before integer a and after integer c

A Valid example is 
      1 2     3)""";

    s1_frmt % warning;
    message += s1_frmt.str();

    // Add footer to message
    s1_frmt % ErrorMessageFooter_;
    message += s1_frmt.str();
    return message;
}

};
}; // namespace ANANSI

