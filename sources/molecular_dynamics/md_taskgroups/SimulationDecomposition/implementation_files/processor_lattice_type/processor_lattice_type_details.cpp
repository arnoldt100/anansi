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
#include "SimulationDecompositionParameters.h"


namespace ANANSI
{
namespace SDPConstructorHelpers
{

bool IsProcessorTopologyLatticeTypeMandatory() 
{
    return true;
}

std::string MessageInvalidProcessorTopologyLatticeTypeValues(const std::string invalid_value)
{
    std::string message;

    boost::format s1_frmt("%1%\n");
    boost::format s2_frmt("    %1%\n");

    // Add header message.
    s1_frmt % ErrorMessageHeader_;
    message += s1_frmt.str();

    // Add warning to message.
    boost::format warning_frmt("Warning! Invalid input parameter '%1%' for lattice topology type.\nValid values are the following:\n");
    warning_frmt % invalid_value.c_str();
    message += warning_frmt.str();
    for (const auto value : SimulationDecompositionParameters::validProcessorTopologyLatticeTypeValues() )
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


}; // End of namespace SDPConstructorHelpers
}; // End of namespace ANANSI

