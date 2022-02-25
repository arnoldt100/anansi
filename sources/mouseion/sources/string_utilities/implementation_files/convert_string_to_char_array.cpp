#include "convert_string_to_char_array.h"
#include "Array1dChar.hpp"
#include "PointerInitializationTraits.hpp"
#include "ExceptionLengthOfCharPointerIsTooSmall.h"

char* convert_string_char_array(std::string const & aString, std::size_t const & length)
{
    MEMORY_MANAGEMENT::Array1d<char> my_char_array_factory;

    char* a_ptr=MEMORY_MANAGEMENT::PointerArrayInitializationTraits<char*>::zero; 

    try
    {
        // Verify that the length of the pointer is sufficient to hold string. 
        // We add 1 to string_length to account for the null char \0.
        auto string_length = aString.size();
        if ( (string_length + 1) > length  ) 
        {
            std::string message("In function convert_string_char_array.");
            throw MEMORY_MANAGEMENT::ExceptionLengthOfCharPointerIsTooSmall(message);
        }

        // Allocate a char array of length number of elements.
        a_ptr = my_char_array_factory.createArray(length);

        // Now fill the character array with the characters from the string.
        for (std::string::size_type ip=0; ip < string_length ; ++ip)
        {
            a_ptr[ip] = aString[ip];
        }
    }
    catch (MEMORY_MANAGEMENT::ExceptionLengthOfCharPointerIsTooSmall const & my_exception)
    {
        std::cout << my_exception.what() << std::endl;
        std::abort();
    }

    return a_ptr;

};
