
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
            std::string key_short;
            std::string key_long;
            std::string description;
            std::string value;
            bool isRequired;
    }; /* -----  end of struct CommandLineOptionsParameter  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef CommandLineOptionsParameter_INC  ----- */
