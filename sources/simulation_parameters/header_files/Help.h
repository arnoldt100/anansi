#ifndef  Help_INC
#define  Help_INC

#include "CommandLineOptions.h"
#include "CommandLineOptionsParameter.h"

namespace ANANSI
{
    const std::string help_key_long="help";
    const std::string help_key_short="h";
    const std::string help_description="Produces the help message.";
    const bool help_isRequired=false;
    const std::string help_value="";

    const struct CommandLineOptionsParameter HelpParameter = {.key_short = help_key_short,
                                                              .key_long = help_key_long,
                                                              .description = help_description,
                                                              .value = help_value,
                                                              .isRequired = help_isRequired};

    static const CommandLineOptions HelpOption(HelpParameter);
};

#endif   /* ----- #ifndef Help_INC  ----- */
