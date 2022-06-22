
#ifndef  AllOptions_INC
#define  AllOptions_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandLineOptions.h"
#include "HelpOption.h"
#include "ControlFileOption.h"


namespace ANANSI
{

    const std::vector<CommandLineOptions> Alloptions { HelpOption,
                                                       ControlFileOption };

}; /* namespace ANANSI */

#endif   /* ----- #ifndef AllOptions_INC  ----- */
