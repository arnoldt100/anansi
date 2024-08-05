#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "__target___unit_tests")
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
# with the __target___unit_test target.                           @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    
    #-----------------------------------------------------
    # Here we define the variable                        -
    # __target___unit_tests_header_files                 -
    # with the target header files.                      -
    #                                                    -
    #-----------------------------------------------------
    set (__target___unit_tests_header_files
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/test___target__.h )


    #-----------------------------------------------------
    # Here we define the variable                        -
    # __target___unit_tests_implementation_files         -
    # associated with target implementation files.       -
    #                                                    -
    #-----------------------------------------------------
    set (__target___unit_tests_implementation_files
        ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/test___target__.cpp )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the implementation and header files associated  @
# with the __target___unit_tests target.                          @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Section for adding various targets and                          @
# target properties, etc.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    add_executable( ${target}
                    "" )

    #-----------------------------------------------------
    #                                                    -
    # We associate the source files with the target.     -
    #                                                    -
    #-----------------------------------------------------
    target_sources(${target}
        PRIVATE ${__target___unit_tests_header_files}
                ${__target___unit_tests_implementation_files} )

    #-----------------------------------------------------
    # Set the directories to look for  header_files.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property( <cla>_include_dir __target__ __target___include )
    target_include_directories(${target} 
                               PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                               PRIVATE ${<cla>_include_dir}
                               PRIVATE ${Boost_INCLUDE_DIR} )

    #-----------------------------------------------------
    # Define the external libraries to link against.     -
    # (1) Boost libraries                                -
    # (2) lib__target__.a                    -
    #                                                    -
    #-----------------------------------------------------
    target_link_libraries(${target}
                          PRIVATE __target__ ${Boost_LIBRARIES} )

    #-----------------------------------------------------
    # Here we set the properties on target               -
    # __target___unit_tests.                 -
    #                                                    -
    #-----------------------------------------------------
    set_target_properties( ${target}
                           PROPERTIES
                           PUBLIC_HEADER "${__target___unit_tests_header_files}" )

    #-----------------------------------------------------
    # Here we define the installations rules for         -
    # this target __target___unit_tests.                 -
    #                                                    -
    #-----------------------------------------------------
    install( TARGETS ${target}
             RUNTIME DESTINATION ${anansi_install_bin_directory} 
             PUBLIC_HEADER DESTINATION ${anansi_install_include_directory} )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of section for adding various targets and                   @
# target properties, etc.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
