# This CMakeLists.txt file creates the library libsimulationparameters.a
# and its unit tests. To add source files, simply append the appropiate variable
# simulationparameters_header_files or simulationparameters_implementation_files.
#
# The target for the library is simulationparameters.
#
# The following properties are set for the target simulationparameters.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#
# simulation_parameters_include         ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
# PUBLIC_HEADER                         ${simulation_parameters_header_files}               The list of headers files associated with this librarry.
#
# The build will abort unless the following variables are defined to
# install the library archive, header files, and unit tests:
#   simulation_parameters_install_lib_directory
#   simulation_parameters_install_include_directory
#   simulation_parameters_install_bin_directory

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "simulation_parameters")
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
    include(cmake_macros_and_functions/simulation_parameters_build_prerequisites.cmake)

    #-----------------------------------------------------
    # Verify key variables are set.                      -
    #                                                    -
    #-----------------------------------------------------
    verify_key_environmental_are_set()

    #-----------------------------------------------------
    # This library needs access to the following header  -
    # files:                                             -
    #                                                    -
    #   command_line_arguments target header files       -
    #                                                    -
    # We get the path to the above header files.         -
    #-----------------------------------------------------
    get_target_property(mm_include_dir memory_management memory_management_include)
    get_target_property(my_cl_include_dir command_line_arguments command_line_arguments_include)

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
    # Here we define the variable                        -
    # simulation_parameters_header_files.                -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (simulation_parameters_header_files
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/SimulationParameters.h 
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/SimulationParametersFactory.h
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ErrorNoShortName.h
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ErrorNoLongName.h
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ErrorNoOptionDescription.h
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/AllOptions.h
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/Help.h
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/CommandLineOptionsParameter.h
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/CommandLineOptions.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (simulation_parameters_implementation_files
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/SimulationParameters.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/SimulationParametersFactory.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ErrorNoShortName.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ErrorNoLongName.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ErrorNoOptionDescription.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/AllOptions.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/Help.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/CommandLineOptionsParameter.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/CommandLineOptions.cpp )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the command_line_arguments targets.                        @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# command_line_arguments.                            -
#                                                    -
#-----------------------------------------------------
add_library( ${target} STATIC 
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
               PRIVATE ${simulation_parameters_header_files} ${simulation_parameters_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${Boost_INCLUDE_DIR}
                           PRIVATE ${mm_include_dir}
                           PRIVATE ${my_cl_include_dir} )

#-----------------------------------------------------
# The libraries to use when linking to target.       -
#                                                    -
#-----------------------------------------------------
target_link_libraries( ${my_library_target}
                       command_line_arguments)

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      simulation_parameters_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD ${simulation_parameters_cxx_standard}
                      PUBLIC_HEADER "${simulation_parameters_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${anansi_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${anansi_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
add_subdirectory(unit_tests)
