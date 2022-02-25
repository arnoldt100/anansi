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

#include "convert_sequence_of_chars_to_vector_string.h"
#include <algorithm>


namespace STRING_UTILITIES 
{
    std::vector<std::string> 
    convert_sequence_of_chars_to_vector_string( 
       int const & length,
       int const * const start_offsets_ptr,
       int const * const end_offsets_ptr,
       const char * sequence_of_characters)
    {
        std::vector<std::string> aVectorString;

        for (int ip=0; ip < length; ++ip)
        {
            const std::size_t starting_index = start_offsets_ptr[ip];
            const std::size_t ending_index = end_offsets_ptr[ip];
            std::size_t terminating_null_char_location = ending_index;
            bool terminating_null_char_found = false;
            for (std::size_t jp=starting_index; jp <= ending_index; ++jp )
            {
                if ( (sequence_of_characters[jp] == '\0') && ( ! terminating_null_char_found ) )
                {
                       terminating_null_char_location = jp;
                       terminating_null_char_found = true; 
                } 
            }
            std::size_t num_chars = terminating_null_char_location - starting_index; 
            std::string aHostname(std::string(&(sequence_of_characters[starting_index]),num_chars));   
            aVectorString.push_back(aHostname);
        }
        std::sort(aVectorString.begin(),aVectorString.end());

        return aVectorString;
    }

}; /* namespace STRING_UTILITIES */

