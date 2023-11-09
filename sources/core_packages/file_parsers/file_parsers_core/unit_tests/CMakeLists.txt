#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "file_parsers_core_unit_tests")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # This target needs access to the following header   -
    # files:                                             -
    #                                                    -
    #   file_parsers_core target header files            -
    #                                                    -
    #-----------------------------------------------------
    get_target_property(my_file_parsers_core_include file_parsers_core file_parsers_core_include)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Here we define the sources and header files associated          @
# with the file_parsers_core_unit_test target.                    @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    
    #-----------------------------------------------------
    # Here we define the variable                        -
    # file_parsers_core_unit_tests_header_files          -
    # with the target header files.                      -
    #                                                    -
    #-----------------------------------------------------
    set (file_parsers_core_unit_tests_header_files
    ${CMAKE_CURRENT_SOURCE_DIR}/header_files/PathToDataFilesFileParserCore.h
    ${CMAKE_CURRENT_SOURCE_DIR}/header_files/XMLNodeKeys.h
    ${CMAKE_CURRENT_SOURCE_DIR}/header_files/NodeKeysFixture.h
    ${CMAKE_CURRENT_SOURCE_DIR}/header_files/XMLReaderFixture.h
    ${CMAKE_CURRENT_SOURCE_DIR}/header_files/test_file_parsers_core.h )


    #-----------------------------------------------------
    # Here we define the variable                        -
    # file_parsers_core_unit_tests_implementation_files  -
    # associated with target implementation files.       -
    #                                                    -
    #-----------------------------------------------------
    set (file_parsers_core_unit_tests_implementation_files
    ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/PathToDataFilesFileParserCore.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/XMLNodeKeys.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/NodeKeysFixture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/XMLReaderFixture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/test_file_parsers_core.cpp )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the implementation and header files associated  @
# with the file_parsers_core_unit_tests target.                   @
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
        PRIVATE ${file_parsers_core_unit_tests_header_files}
                ${file_parsers_core_unit_tests_implementation_files} )

    #-----------------------------------------------------
    # Set the directories to look for  header_files.     -
    #                                                    -
    #-----------------------------------------------------
    target_include_directories(${target} 
                               PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                               PRIVATE ${my_file_parsers_core_include} 
                               PRIVATE ${Boost_INCLUDE_DIR} )

    #-----------------------------------------------------
    # Define the external libraries to link against.     -
    # (1) Boost libraries                                -
    # (2) libfile_parsers_core.a                         -
    #                                                    -
    #-----------------------------------------------------
    target_link_libraries(${target}
                          PUBLIC file_parsers_core 
                          PUBLIC ${Boost_LIBRARIES})

    #-----------------------------------------------------
    # Here we set the properties on target               -
    # file_parsers_core_unit_tests.                      -
    #                                                    -
    #-----------------------------------------------------
    set_target_properties( ${target}
                           PROPERTIES
                           CXX_STANDARD "${file_parsers_core_cxx_standard}"
                           PUBLIC_HEADER "${file_parsers_core_unit_tests_header_files}" )

    #-----------------------------------------------------
    # Here we define the installations rules for         -
    # this target file_parsers_core_unit_tests.          -
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
