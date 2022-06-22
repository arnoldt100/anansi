#ifndef  CommandLineOptionsUtilityFunctions_INC
#define  CommandLineOptionsUtilityFunctions_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <map>
#include <vector>

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
//  Description:  Returns a value from the map object a_map. If the 
//                key is not found, a default value is returned. 
// 
//   Template parameters : KEY_TYPE - The type of the std::map key
//                         VALUE_TYPE - The type of the std::map value 
//
//   Parameters: key - The key of the pair to return the value.
//               a_map - The std::map object that is to be searched over.
//               default_value - The value returned if the key is not found in the map object a_map. 
//
//        Return: VALUE_TYPE
// =====================================================================================
template <typename KEY_TYPE, typename VALUE_TYPE>
VALUE_TYPE get_option_value( const KEY_TYPE key, const std::map <KEY_TYPE,VALUE_TYPE> a_map, const VALUE_TYPE default_value)
{
    const auto search = a_map.find(key);
    const VALUE_TYPE my_option_value = (search != a_map.end()) ? search->second : default_value;
    return my_option_value;
}   /* -----  end of function get_option_value  ----- */



// ===  FUNCTION  ======================================================================
//         Name:  bool_to_int
//  Description: Converts a bool expression to 0 or 1. If the expression is true then 1 is 
//               returned, otherwise 0 is returned.
// 
//   Parameters: x - A bool expression
//
//        Return: unsigned int 0 or 1.
// =====================================================================================
unsigned int bool_to_int (const bool & x); 


// ===  FUNCTION  ======================================================================
//         Name:  compute_number
//  Description:  Computes a unique number for a given boolean vector.
//
//   Parameters:  x - a boolean vector.
//
//        Return: unsigned int 
// =====================================================================================
unsigned int compute_number (const std::vector<bool> & x);

}; /* namespace ANANSI */

#endif   // ----- #ifndef CommandLineOptionsUtilityFunctions_INC  ----- 
