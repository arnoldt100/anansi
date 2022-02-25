#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "memory_management_unit_tests")
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
# with the memory_management_unit_test target.                    @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    
    #-----------------------------------------------------
    # Here we define the variable                        -
    # memory_management_unit_tests_header_files          -
    # with the target header files.                      -
    #                                                    -
    #-----------------------------------------------------
    set ( memory_management_unit_tests_header_files
          ${CMAKE_CURRENT_SOURCE_DIR}/header_files/test_cpumemoryallocation.h
          ${CMAKE_CURRENT_SOURCE_DIR}/header_files/test_column_major_layout.h
          ${CMAKE_CURRENT_SOURCE_DIR}/header_files/test_row_major_layout.h
          ${CMAKE_CURRENT_SOURCE_DIR}/header_files/FixtureArray2d.h
          ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ArrayLayoutType.h
          ${CMAKE_CURRENT_SOURCE_DIR}/header_files/Array2dPrintSpecs.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # memory_management_unit_tests_implementation_files  -
    # associated with target implementation files.       -
    #                                                    -
    #-----------------------------------------------------
    set ( memory_management_unit_tests_implementation_files
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/test_cpumemoryallocation.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/test_column_major_layout.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/test_row_major_layout.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/FixtureArray2d.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ArrayLayoutType.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/Array2dPrintSpecs.cpp )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the implementation and header files associated  @
# with the memory_management_unit_tests target.                   @
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
    # Define the source files to build the               -
    # current target "memory_management_unit_tests".     -
    #                                                    -
    #-----------------------------------------------------
    target_sources( ${target}
                    PRIVATE ${memory_management_unit_tests_implementation_files} ${memory_management_unit_tests_header_files}  )

    #-----------------------------------------------------
    # Set the directories to look for  header_files.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property(mm_include_dir memory_management memory_management_include)
    target_include_directories(${target} 
                               PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                               PRIVATE "${mm_include_dir}"
                               PRIVATE ${Boost_INCLUDE_DIR} )

    #-----------------------------------------------------
    # Define the external libraries to link against.     -
    # (1) Boost libraries                                -
    # (2) libmemory_management.a                         -
    #                                                    -
    #-----------------------------------------------------
    target_link_libraries(${target}
                          PRIVATE memory_management ${Boost_LIBRARIES} )

    #-----------------------------------------------------
    # Here we set the properties on target               -
    # memory_management_unit_tests.                      -
    #                                                    -
    #-----------------------------------------------------
    set_target_properties( ${target} PROPERTIES
                           CXX_STANDARD ${memory_management_cxx_standard}
                           PUBLIC_HEADER "${memory_management_unit_tests_header_files}" )

    #-----------------------------------------------------
    # Here we define the installations rules for         -
    # this target memory_management_unit_tests.          -
    #                                                    -
    #-----------------------------------------------------
    install( TARGETS ${target}
             RUNTIME DESTINATION ${memory_management_install_bin_directory} 
             PUBLIC_HEADER DESTINATION ${memory_management_install_include_directory} )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of section for adding various targets and                   @
# target properties, etc.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
