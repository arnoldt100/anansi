#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "receiver_unit_tests")
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
# with the receiver_unit_test target.                             @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    
    #-----------------------------------------------------
    # Here we define the variable                        -
    # receiver_unit_tests_header_files                   -
    # with the target header files.                      -
    #                                                    -
    #-----------------------------------------------------
    set (receiver_unit_tests_header_files
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/test_receiver_main.h)


    #-----------------------------------------------------
    # Here we define the variable                        -
    # receiver_unit_tests_implementation_files           -
    # associated with target implementation files.       -
    #                                                    -
    #-----------------------------------------------------
    set (receiver_unit_tests_implementation_files
        ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/test_receiver_main.cpp)

    #-----------------------------------------------------
    # Get the include paths. 
    #
    #-----------------------------------------------------
    get_target_property(my_reciever_include receiver receiver_include) 


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the implementation and header files associated  @
# with the receiver_unit_tests target.                            @
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
        PRIVATE ${receiver_unit_tests_header_files}
        PRIVATE ${receiver_unit_tests_implementation_files} )

    #-----------------------------------------------------
    # Set the directories to look for  header_files.     -
    #                                                    -
    #-----------------------------------------------------
    target_include_directories(${target} 
                               PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                               PRIVATE ${my_reciever_include}
                               PRIVATE ${Boost_INCLUDE_DIR} )

    #-----------------------------------------------------
    # Define the external libraries to link against.     -
    # (1) Boost libraries                                -
    # (2) libreceiver.a                                  -
    #                                                    -
    #-----------------------------------------------------
    target_link_libraries(${target} 
                          PRIVATE receiver
                          PRIVATE ${Boost_LIBRARIES} )

    #-----------------------------------------------------
    # Here we set the properties on target               -
    # receiver_unit_tests.                               -
    #                                                    -
    #-----------------------------------------------------
    set_target_properties( ${target} PROPERTIES
                           CXX_STANDARD ${receiver_cxx_standard}
                           PUBLIC_HEADER "${receiver_unit_tests_header_files}" )

    #-----------------------------------------------------
    # Here we define the installations rules for         -
    # this target receiver_unit_tests.                   -
    #                                                    -
    #-----------------------------------------------------
    install( TARGETS ${target}
             RUNTIME DESTINATION ${receiver_install_lib_library_directory} 
             PUBLIC_HEADER DESTINATION ${receiver_install_lib_directory} )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of section for adding various targets and                   @
# target properties, etc.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
