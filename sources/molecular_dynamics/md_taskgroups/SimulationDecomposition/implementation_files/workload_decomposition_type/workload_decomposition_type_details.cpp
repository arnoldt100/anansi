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
#include "workload_decomposition_type_details.h"

namespace ANANSI
{
namespace SDPConstructorHelpers
{

bool IsWorkLoadDecompositionTypeMandatory()
{
    return true;
}

std::string MessageInvalidWorkloadDecompositionTypeValues(const std::string invalid_value)
{
    std::string message;

    boost::format s1_frmt("%1%\n");
    boost::format s2_frmt("    %1%\n");

    // Add header to message.
    s1_frmt % ErrorMessageHeader_;
    message += s1_frmt.str();

    // Add warning to message.
    boost::format warning_frmt("Warning! Invalid input parameter '%1%' for workload decomposition type.\nValid values are the following:\n");
    warning_frmt % invalid_value.c_str();
    message += warning_frmt.str();
    for (const auto value : SimulationDecompositionParameters::validWorkLoadDecompositionValues())
    {
        s2_frmt % value.c_str();
        message += s2_frmt.str();
    }
    s1_frmt % "";
    message += s1_frmt.str();

    // Add footer to message.
    s1_frmt % ErrorMessageFooter_;
    message += s1_frmt.str();
    return message;
}

};
}; // namespace ANANSI

