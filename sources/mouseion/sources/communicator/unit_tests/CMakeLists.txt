#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "mpi_communicator_unit_tests")
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
# with the mpi_communicator_unit_test target.                     @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    
    #-----------------------------------------------------
    # Here we define the variable                        -
    # mpi_communicator_unit_tests_header_files.          -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (mpi_communicator_unit_tests_header_files
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/test_mpi_communicator.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # mpi_communicator_unit_tests_implementation_files.  -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (mpi_communicator_unit_tests_implementation_files
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/test_mpi_communicator.cpp )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the implementation and header files associated  @
# with the mpi_communicator_unit_tests target.                    @
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
        PRIVATE ${mpi_communicator_unit_tests_header_files}
                ${mpi_communicator_unit_tests_implementation_files} )

    #-----------------------------------------------------
    # The libraries to use when linking to target.       -
    #                                                    -
    #-----------------------------------------------------
    target_link_libraries( ${target}
                           PUBLIC mpi_communicator
                           ${Boost_LIBRARIES} )

    #-----------------------------------------------------
    # Set the directories to look for  header_files.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property( mpicomm_include_dir mpi_communicator mpi_communicator_include )
    target_include_directories(${target} 
                               PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                               PRIVATE ${mpicomm_include_dir}
                               PRIVATE ${Boost_INCLUDE_DIR} )

    #-----------------------------------------------------
    # Here we set the properties on target               -
    # mpi_communicator_unit_tests.                       -
    #                                                    -
    #-----------------------------------------------------
    set_target_properties( ${target} PROPERTIES
                           CXX_STANDARD ${mpi_communicator_cxx_standard}
                           PUBLIC_HEADER "${mpi_communicator_unit_tests_header_files}" )

    install(TARGETS ${target}
            RUNTIME DESTINATION ${mpi_communicator_install_bin_directory}
            PUBLIC_HEADER DESTINATION ${mpi_communicator_install_include_directory} )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of section for adding various targets and                   @
# target properties, etc.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

