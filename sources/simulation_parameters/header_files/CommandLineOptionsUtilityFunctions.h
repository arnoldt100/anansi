#ifndef  CommandLineOptionsUtilityFunctions_INC
#define  CommandLineOptionsUtilityFunctions_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//


namespace ANANSI
{

// ===  FUNCTION  ======================================================================
//         Name:  get_option_value
//  Description:  Returns a value from the  map object a_map. If the 
//                key is not found, a default value is returned. 
// 
//   Parameters: key - The key of the pair to return the value.
//               a_map - The std::map object that is to be searched over.
//               default_value - The value returned if the key is not found in the map object a_map. 
//
//        Return: VALUE_TYPE object.
// =====================================================================================
template <typename KEY_TYPE, typename VALUE_TYPE>
VALUE_TYPE get_option_value( const KEY_TYPE key, const std::map <KEY_TYPE,VALUE_TYPE> a_map, const VALUE_TYPE default_value)
{
    VALUE_TYPE my_option_value;

    return my_option_value;
}   /* -----  end of function get_option_value  ----- */

}; /* namespace ANANSI */

#endif   // ----- #ifndef CommandLineOptionsUtilityFunctions_INC  ----- 
