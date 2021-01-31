#include "AllOptions.h"

#include "Help.h"

namespace ANANSI
{


const std::string controlfile_key="help";
const std::string controlfile_description="The name of the control file.";

std::vector<CommandLineOptions> AllOptions = 
{
        HelpOption,
        CommandLineOptions(controlfile_key)
};

};
