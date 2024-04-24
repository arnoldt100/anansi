//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <filesystem>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorMissingInputFile.h"
#include "verify_file_exists.h"

namespace ANANSI
{

void verify_file_exists(const std::string filename )
{
    namespace fs = std::filesystem;

    fs::path p1{filename.c_str()};

    if (not fs::exists(p1))
    {
        std::string error_message;
        throw ErrorMissingInputFile{error_message};
    
    }
    return;
}   // -----  end of function verify_file_exists  -----


}; // namespace ANANSI

