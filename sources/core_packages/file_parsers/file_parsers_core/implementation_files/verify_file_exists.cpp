//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <filesystem>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/format.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorMissingInputFile.h"
#include "verify_file_exists.h"

namespace ANANSI
{
    namespace
    {
    static constexpr char* ErrorMessageHeader = R"""(
# ----------------------
# Error Message
# ----------------------)""";


    static constexpr char* ErrorMessageFooter = R"""(# ----------------------)""";

     std::string message_missing_input_file (const std::string filename)
        {
            std::string message;

            boost::format s1_frmt("%1%\n");

            // Add header to message.
            s1_frmt % ErrorMessageHeader;
            message = s1_frmt.str();

            // Add warning to message.
            boost::format warning_frmt("Warning! The input file '%1%' is missing.\nCheck the spelling of the filename\nand ensure the file actually exists.\n");
            warning_frmt % filename.c_str();
            message += warning_frmt.str();

            // Add footer to message.
            s1_frmt % ErrorMessageFooter;
            message += s1_frmt.str();
            return message;
        }   // -----  end of function message_missing_mandatory_node_tag  -----

    };
void verify_file_exists(const std::string filename )
{
    namespace fs = std::filesystem;

    fs::path p1{filename.c_str()};

    if (not fs::exists(p1))
    {
        std::string error_message = message_missing_input_file(filename);
        throw ErrorMissingInputFile{error_message};
    }
    return;
}   // -----  end of function verify_file_exists  -----


}; // namespace ANANSI

