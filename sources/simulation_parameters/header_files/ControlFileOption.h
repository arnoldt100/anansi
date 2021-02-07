#ifndef  ControlFileOption_INC
#define  ControlFileOption_INC

#include "CommandLineOptions.h"
#include "CommandLineOptionsParameter.h"

namespace ANANSI
{
    const std::string controlfile_long_name="controlfile";
    const std::string controlfile_short_name="c";
    const std::string controlfile_description="The name of the simulation control file.";
    const bool controlfile_isRequired=true;
    const bool controlfile_isRequiredOptionValues=true;
    const std::string controlfile_default_value="";

    const struct CommandLineOptionsParameter ControlFileOptionParameter = {.short_name = controlfile_short_name,
                                                              .long_name = controlfile_long_name,
                                                              .description = controlfile_description,
                                                              .default_value = controlfile_default_value,
                                                              .isRequired = controlfile_isRequired,
                                                              .isRequiredOptionValues = controlfile_isRequiredOptionValues};

    static const CommandLineOptions ControlFileOption(ControlFileOptionParameter);
};

#endif   /* ----- #ifndef ControlFileOption_INC  ----- */
