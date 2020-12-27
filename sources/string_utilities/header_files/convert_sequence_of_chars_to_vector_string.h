#ifndef CONVERT_SEQUENCE_OF_CHARS_TO_VSTRING_H
#define CONVERT_SEQUENCE_OF_CHARS_TO_VSTRING_H

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>
#include <string>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace STRING_UTILITIES 
{

/*==================================================================================*/
/*                                                                                  */
/* Function name: convert_sequence_of_chars_to_vector_string                        */
/*                                                                                  */
/* Function arguments:                                                              */
/*                                                                                  */
/* Description:                                                                     */
/*                                                                                  */
/*                                                                                  */
/*==================================================================================*/
std::vector<std::string> 
convert_sequence_of_chars_to_vector_string(
       int const & length,
       int const * const start_offsets_ptr,
       int const * const end_offsets_ptr,
       char const * sequence_of_characters );


}; /* namespace STRING_UTILITIES */

#endif /* CONVERT_SEQUENCE_OF_CHARS_TO_VSTRING_H */
