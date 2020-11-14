project(STRING_UTILITIES
        VERSION 1.0)
string(TOLOWER ${PROJECT_NAME} my_target_library)

#-----------------------------------------------------
# Here we define a list of all header files          -
# associated with the STRING_UTILITIES project.      -
#                                                    -
#-----------------------------------------------------
set(my_public_headers
    header_files/convert_commandline_to_2d_char_array.h
    header_files/convert_commandline_to_vector_string_array.h
    header_files/convert_vector_to_a_string.h 
    header_files/convert_string_to_char_array.h
    header_files/convert_sequence_of_chars_to_vector_string.h
    header_files/get_maximum_width_of_vector_string.h
    header_files/under_line_string.h )

#-----------------------------------------------------
# Here we define a list of all implementation files  -
# associated with the STRING_UTILITIES project       -
#                                                    -
#-----------------------------------------------------
set(my_public_implementation_files 
    implementation_files/convert_commandline_to_2d_char_array.cpp
    implementation_files/convert_commandline_to_vector_string_array.cpp
    implementation_files/convert_vector_to_a_string.cpp
    implementation_files/convert_string_to_char_array.cpp
    implementation_files/convert_sequence_of_chars_to_vector_string.cpp 
    implementation_files/get_maximum_width_of_vector_string.cpp
    implementation_files/under_line_string.cpp )

#-----------------------------------------------------
# Add the  library target called from the source     -
# files listed in the command invocation.            -
#                                                    -
#-----------------------------------------------------
add_library(${my_target_library} STATIC 
           ${my_public_implementation_files} )

#-----------------------------------------------------
# Define the diretories to search for                -
# for the string_utilities library header files.     -
#                                                    -
#-----------------------------------------------------
target_include_directories(${my_target_library}  PUBLIC 
                           header_files )

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${my_target_library})


#-----------------------------------------------------
# Here we set the PUBLIC_HEADER property on target   -
# string_utilities. This property will define        -
# the header files associated with the               -
# with the string_utilities library.                 -
#                                                    -
#-----------------------------------------------------
set_target_properties(${my_target_library} PROPERTIES
                      PUBLIC_HEADER "${my_public_headers}" )

#-----------------------------------------------------
# Other dependencies.                                -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${my_target_library} 
                      memory_management)

install(TARGETS ${my_target_library}
        ARCHIVE DESTINATION ${BUGGET_LIB}
        PUBLIC_HEADER DESTINATION ${BUGGET_INCLUDE} )   
