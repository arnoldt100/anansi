//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandLineOptionsUtilityFunctions.h"

namespace ANANSI
{

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//                                                                 @
// This lambda converts a bool to 0 or 1.                          @
//                                                                 @
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
unsigned int bool_to_int (const bool & x) 
{
     const unsigned int y =  x ? 1 : 0; 
     return y;
}; 

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//                                                                 @
// This lambda computes a unique number for a given bool vector.   @
//                                                                 @
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
unsigned int compute_number (const std::vector<bool> & x)
{
    unsigned int num = 0;
    for (auto it = x.begin(); it != x.end(); ++it)
    {
        const auto n1 = bool_to_int(*it);
        if ( it == x.begin() ) 
        {
            num += n1;
        }
        else
        {
            num <<= 1; 
            num += n1;
        } 
    }
    return num;
};

}; /* namespace ANANSI */

