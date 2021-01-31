#ifndef  Help_INC
#define  Help_INC

#include "CommandLineOptions.h"

namespace ANANSI
{
    const std::string help_key="help";
    const std::string help_description="Produces the help message.";
    const bool help_isRequired=false;
    const std::string help_value="";
    const CommandLineOptions HelpOption(help_key,help_description,help_isRequired,help_value);
};

#endif   /* ----- #ifndef Help_INC  ----- */
