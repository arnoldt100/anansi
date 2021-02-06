#include "AllOptions.h"

#include "Help.h"
#include "ControlFileOption.h"

namespace ANANSI
{


std::vector<CommandLineOptions> AllOptions = 
{
        HelpOption,
        ControlFileOption
};

};
