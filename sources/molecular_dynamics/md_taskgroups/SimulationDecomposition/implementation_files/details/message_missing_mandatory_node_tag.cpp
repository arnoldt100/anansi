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
#include "message_missing_mandatory_node_tag.h"

namespace ANANSI
{
    namespace 
    {

    static constexpr char* ErrorMessageHeader = R"""(
    # ----------------------
    # Error Message
    # ----------------------)""";

    //!  Move this outside the class to  helper function.
    static constexpr char* ErrorMessageFooter = R"""(# ----------------------)""";

    }; // End of anonynous namespace.

    namespace SDPConstructorHelpers
    {
        std::string message_missing_mandatory_node_tag (const std::string node_tag)
        {
            std::string message;

            boost::format s1_frmt("%1%\n");

            // Add header to message.
            s1_frmt % ErrorMessageHeader;
            message = s1_frmt.str();

            // Add warning to message.
            boost::format warning_frmt("Warning! The tag for the '%1%' is missing from the input file\nbut the tag is mandatory to run the program.\n");
            warning_frmt % node_tag.c_str();
            message += warning_frmt.str();

            // Add footer to message.
            s1_frmt % ErrorMessageFooter;
            message += s1_frmt.str();
            return message;
        }   // -----  end of function message_missing_mandatory_node_tag  -----

    }; // End of namespace SDPConstructorHelpers
}; // End of namespace ANANSI

