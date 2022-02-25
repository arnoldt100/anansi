#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "string_utilities_unit_tests")
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
# with the string_utilities_unit_test target.                     @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    
    #-----------------------------------------------------
    # Here we define the variable                        -
    # string_utilities_unit_tests_header_files           -
    # with the target header files.                      -
    #                                                    -
    #-----------------------------------------------------

    #-----------------------------------------------------
    # Here we define the variable                        -
    # string_utilities_unit_tests_implementation_files   -
    # associated with target implementation files.       -
    #                                                    -
    #-----------------------------------------------------

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the implementation and header files associated  @
# with the string_utilities_unit_tests target.                    @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Section for adding various targets and                          @
# target properties, etc.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the source files to build the               -
    # current target "string_utilities_unit_tests".      -
    #                                                    -
    #-----------------------------------------------------
    set (string_utilities_unit_tests_header_files
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/test_string_utilities.h )

    set (string_utilities_unit_tests_implementation_files
        ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/test_string_utilities.cpp )

    add_executable( ${target}
                    "" )

#-----------------------------------------------------
#                                                    -
# We associate the source files with the target.     -
#                                                    -
#-----------------------------------------------------
    target_sources(${target}
        PRIVATE ${string_utilities_unit_tests_header_files} ${string_utilities_unit_tests_implementation_files} )

    #-----------------------------------------------------
    # Set the directories to look for  header_files.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property( su_include_dir string_utilities string_utilities_include )
    target_include_directories(${target} 
                               PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                               PRIVATE ${su_include_dir}
                               PRIVATE ${Boost_INCLUDE_DIR} )

    #-----------------------------------------------------
    # Define the external libraries to link against.     -
    # (1) Boost libraries                                -
    # (2) libstring_utilities.a                          -
    #                                                    -
    #-----------------------------------------------------
    target_link_libraries(${target}
                          PRIVATE string_utilities ${Boost_LIBRARIES} )

    #-----------------------------------------------------
    # Here we set the properties on target               -
    # string_utilities_unit_tests.                       -
    #                                                    -
    #-----------------------------------------------------
    set_target_properties( ${target}
                           PROPERTIES
                           CXX_STANDARD ${string_utilities_cxx_standard}
                           PUBLIC_HEADER "${string_utilities_unit_tests_header_files}" )

    #-----------------------------------------------------
    # Here we define the installations rules for         -
    # this target string_utilities_unit_tests.           -
    #                                                    -
    #-----------------------------------------------------
    install( TARGETS ${target}
             RUNTIME DESTINATION ${string_utilities_install_bin_directory} 
             PUBLIC_HEADER DESTINATION ${string_utilities_install_include_directory} )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of section for adding various targets and                   @
# target properties, etc.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
