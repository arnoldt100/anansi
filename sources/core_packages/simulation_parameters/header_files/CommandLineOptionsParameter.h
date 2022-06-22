
#ifndef  CommandLineOptionsParameter_INC
#define  CommandLineOptionsParameter_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

    /*
     * =====================================================================================
     *        Struct :  CommandLineOptionsParameter
     *  Description: The monodic argument for the CommandLineOptions class. 
     * =====================================================================================
     */
    struct CommandLineOptionsParameter
    {
        public:
            std::string short_name;
            std::string long_name;
            std::string description;
            std::string default_value;
            bool isRequired;
            bool isRequiredOptionValues;
    }; /* -----  end of struct CommandLineOptionsParameter  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef CommandLineOptionsParameter_INC  ----- */
