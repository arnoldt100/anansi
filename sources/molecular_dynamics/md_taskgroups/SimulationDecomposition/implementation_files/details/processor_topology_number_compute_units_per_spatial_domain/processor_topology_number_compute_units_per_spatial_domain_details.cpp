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
#include "processor_topology_number_compute_units_per_spatial_domain_details.h"
#include "convert_string_to_int_array.hpp"

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
namespace SDPConstructorHelpers 
{

int ProcessorTopologyNumberComputeUnitsPerSpatialDomainValues(const std::string node_value)
{
    std::array<int,1> my_value = STRING_UTILITIES::convert_string_to_int_array<1>(node_value);
    return my_value[0];
}

std::string MessageInvalidProcessorTopologyNumberComputeUnitsPerSpatialDomain(const std::string invalid_value)
{
    std::string message;

    // Add header to message.
    boost::format s1_frmt("%1%\n");
    s1_frmt % ErrorMessageHeader_;
    message += s1_frmt.str();

    boost::format warning_frmt0("Warning! Invalid input parameter '%1%' for processor topology number compute units per spatial domain.\n");
    warning_frmt0 % invalid_value.c_str();
    message += warning_frmt0.str();

    // Add warning. We store the warning message in  raw string literal.
    const char* warning = R"""(
The input parameter must have form  of '<spaces>a<spaces>' where
    - <spaces> is whitespace
    - a is a positive integer

A Valid example is 
      7 )""";

    s1_frmt % warning;
    message += s1_frmt.str();

    // Add footer to message
    s1_frmt % ErrorMessageFooter_;
    message += s1_frmt.str();
    return message;
}

}; // End of namespace SDPConstructorHelpers
}; // End of namespace ANANSI
