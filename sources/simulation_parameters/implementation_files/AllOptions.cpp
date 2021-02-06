#include "AllOptions.h"

#include "HelpOption.h"
#include "ControlFileOption.h"

namespace ANANSI
{


std::vector<CommandLineOptions> AllOptions = 
{
        HelpOption,
        ControlFileOption
};

};
