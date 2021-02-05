#ifndef  Help_INC
#define  Help_INC

#include "CommandLineOptions.h"
#include "CommandLineOptionsParameter.h"

namespace ANANSI
{
    const std::string help_long_name="help";
    const std::string help_short_name="h";
    const std::string help_description="Produces the help message.";
    const bool help_isRequired=false;
    const std::string help_default_value="";

    const struct CommandLineOptionsParameter HelpParameter = {.short_name = help_short_name,
                                                              .long_name = help_long_name,
                                                              .description = help_description,
                                                              .default_value = help_default_value,
                                                              .isRequired = help_isRequired};

    static const CommandLineOptions HelpOption(HelpParameter);
};

#endif   /* ----- #ifndef Help_INC  ----- */
