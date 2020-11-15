#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "string_utilities")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Here we define the sources and header files associated          @
# with the various targets.                                       @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Here we define a list of all header files          -
    # associated with the string_utilities project.      -
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
    # associated with the string_utilities project       -
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

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the memory_management targets.                             @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the  library target called from the source     -
# files listed in the command invocation.            -
#                                                    -
#-----------------------------------------------------
add_library(${target} STATIC 
            "")

#-----------------------------------------------------
#                                                    -
# We associate the source files with the target.     -
#                                                    -
#-----------------------------------------------------
target_sources(${target}
    PRIVATE ${my_public_headers} ${my_public_implementation_files})

#-----------------------------------------------------
# Define the diretories to search for                -
# for the string_utilities library header files.     -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target}  
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files )

#-----------------------------------------------------
# Other dependencies.                                -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${target} 
                      memory_management)

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})


#-----------------------------------------------------
# Here we set the PUBLIC_HEADER property on target   -
# string_utilities. This property will define        -
# the header files associated with the               -
# with the string_utilities library.                 -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      string_utilities_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      PUBLIC_HEADER "${my_public_headers}" )


install(TARGETS ${target}
        ARCHIVE DESTINATION ${string_utilities_install_lib_directory}
        PUBLIC_HEADER DESTINATION ${string_utilities_install_include_directory} )   
