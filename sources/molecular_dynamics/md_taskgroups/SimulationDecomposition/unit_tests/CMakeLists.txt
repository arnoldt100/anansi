# This CMakeLists.txt file creates the binary "simulationdecomposition_unit_tests".
# To add source files, simply append the appropiate variable
# simulationdecomposition_unit_tests_header_files or 
# simulationdecomposition_unit_tests_header_files.
#
# The target for this CMakeLists.txt is simulationdecomposition_unit_tests.
#
# The following properties are set for the target simulationdecomposition.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "simulationdecomposition_unit_tests")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # Set various variables for include directories.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property( my_simulationdecomposition_include_dir simulationdecomposition simulationdecomposition_include )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Here we define the sources and header files associated          @
# with the simulationdecomposition_unit_test target.              @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    
    #-----------------------------------------------------
    # Here we define the variable                        -
    # simulationdecomposition_unit_tests_header_files    -
    # with the target header files.                      -
    #                                                    -
    #-----------------------------------------------------
    set (simulationdecomposition_unit_tests_header_files
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/test_simulationdecomposition.h )


    #-----------------------------------------------------
    # Here we define the variable                        -
    # simulationdecomposition_unit_tests_implementation_files -
    # associated with target implementation files.       -
    #                                                    -
    #-----------------------------------------------------
    set (simulationdecomposition_unit_tests_implementation_files
        ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/test_simulationdecomposition.cpp )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the implementation and header files associated  @
# with the simulationdecomposition_unit_tests target.             @
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
                   PRIVATE ${simulationdecomposition_unit_tests_header_files}
                   PRIVATE ${simulationdecomposition_unit_tests_implementation_files} )

    #-----------------------------------------------------
    # Set the directories to look for  header_files.     -
    #                                                    -
    #-----------------------------------------------------
    target_include_directories(${target} 
                               PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                               PRIVATE ${simulationdecomposition_include_dir}
                               PRIVATE ${Boost_INCLUDE_DIR} )

    #-----------------------------------------------------
    # Define the external libraries to link against.     -
    # (1) Boost libraries                                -
    # (2) libsimulationdecomposition.a                   -
    #                                                    -
    #-----------------------------------------------------
    target_link_libraries(${target}
                          PRIVATE simulationdecomposition 
                          PRIVATE ${Boost_LIBRARIES} )

    #-----------------------------------------------------
    # Here we set the properties on target               -
    # simulationdecomposition_unit_tests.                -
    #                                                    -
    #-----------------------------------------------------
    set_target_properties( ${target}
                           PROPERTIES
                           CXX_STANDARD "${simulationdecomposition_cxx_standard}"
                           PUBLIC_HEADER "${simulationdecomposition_unit_tests_header_files}" )

    #-----------------------------------------------------
    # Here we define the installations rules for         -
    # this target simulationdecomposition_unit_tests.    -
    #                                                    -
    #-----------------------------------------------------
    install( TARGETS ${target}
             RUNTIME DESTINATION ${simulationdecomposition_install_bin_directory} 
             PUBLIC_HEADER DESTINATION ${simulationdecomposition_install_include_directory} )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of section for adding various targets and                   @
# target properties, etc.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
