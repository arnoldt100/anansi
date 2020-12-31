# This CMakeLists.txt file creates the library libstring_utilities.a
# and its unit tests. To add source files, simply append the appropiate variable
# string_utilities_header_files or string_utilities_implementation_files.
#
# The target for the library is string_utilities.
#
# The following properties are set for the target :
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#   string_utilities_include            ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
#   PUBLIC_HEADER                       ${string_utilities_header_files}                    The list of headers files associated with this librarry.
#
# The build will abort unless the following variables are defined to
# install the library archive, header files, and unit tests:
#   string_utilities_install_lib_directory
#   string_utilities_install_include_directory
#   string_utilities_install_bin_directory

    #-----------------------------------------------------
    # This library needs access to the following header  -
    # files:                                             -
    #                                                    -
    #   memory_management target header files            -
    #   string_utilities target header files             -
    #                                                    -
    # We get the path to the above header files.         -
    #-----------------------------------------------------
    get_target_property(my_mm_include memory_management memory_management_include)

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

    #-----------------------------------------------------
    # Include various functions and macros.              -
    #                                                    -
    #-----------------------------------------------------
    include(cmake_macros_and_functions/string_utilities_build_prerequisites.cmake)

    #-----------------------------------------------------
    # Verify key variables are set.                      -
    #                                                    -
    #-----------------------------------------------------
    verify_key_environmental_are_set()

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
    set(string_utilities_header_files
        header_files/convert_commandline_to_2d_char_array.h
        header_files/convert_commandline_to_vector_string_array.h
        header_files/convert_vector_to_a_string.h 
        header_files/convert_string_to_char_array.h
        header_files/copy_2d_char_array.h
        header_files/convert_sequence_of_chars_to_vector_string.h
        header_files/get_maximum_width_of_vector_string.h
        header_files/under_line_string.h )

    #-----------------------------------------------------
    # Here we define a list of all implementation files  -
    # associated with the string_utilities project       -
    #                                                    -
    #-----------------------------------------------------
    set(string_utilities_implementation_files 
        implementation_files/convert_commandline_to_2d_char_array.cpp
        implementation_files/convert_commandline_to_vector_string_array.cpp
        implementation_files/convert_vector_to_a_string.cpp
        implementation_files/convert_string_to_char_array.cpp
        implementation_files/copy_2d_char_array.cpp
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
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})

#-----------------------------------------------------
#                                                    -
# We associate the source files with the target.     -
#                                                    -
#-----------------------------------------------------
target_sources(${target}
               PRIVATE ${string_utilities_header_files} ${string_utilities_implementation_files})

#-----------------------------------------------------
# Define the diretories to search for                -
# for the string_utilities library header files.     -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target}  
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${my_mm_include} )

#-----------------------------------------------------
# Other dependencies.                                -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${target} 
                      memory_management)


#-----------------------------------------------------
# Here we set the PUBLIC_HEADER property on target   -
# string_utilities. This property will define        -
# the header files associated with the               -
# with the string_utilities library.                 -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      string_utilities_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD ${string_utilities_cxx_standard}
                      PUBLIC_HEADER "${string_utilities_header_files}" )


install(TARGETS ${target}
        ARCHIVE DESTINATION ${string_utilities_install_lib_directory}
        PUBLIC_HEADER DESTINATION ${string_utilities_install_include_directory} )   

add_subdirectory(unit_tests)
