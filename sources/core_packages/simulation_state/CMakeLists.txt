# This CMakeLists.txt file creates the library libsimulation_state.a
# and its unit tests. To add source files, simply append the appropiate variable
# simulation_state_header_files or simulation_state_implementation_files.
#
# The target for the library is simulation_state.
#
# The following properties are set for the target simulation_state.
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
    set(my_project_name "simulation_state")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    # ----------------------------------------------------
    # Verify the all build prerequisites are met
    # 
    # ----------------------------------------------------
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/simulation_state_build_prerequisites.cmake)
    verify_simulation_state_build_prerequisites_are_met()

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
    # command_line_arguments_header_files.               -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (simulation_state_header_files
         header_files/SimulationState.h
         header_files/NullSimulation.h
         header_files/InitSimEnv.h  
         header_files/ProcessCmdLine.h
         header_files/InitInitialConditions.h
         header_files/PerformSimulation.h 
         header_files/TerminateSimulation.h)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (simulation_state_implementation_files
         implementation_files/SimulationState.cpp
         implementation_files/NullSimulation.cpp 
         implementation_files/InitSimEnv.cpp
         implementation_files/ProcessCmdLine.cpp
         implementation_files/InitInitialConditions.cpp
         implementation_files/PerformSimulation.cpp
         implementation_files/TerminateSimulation.cpp)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the command_line_arguments targets.                        @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# simulation_state                                   -
#                                                    -
#-----------------------------------------------------
add_library( ${target} STATIC 
             "")

#-----------------------------------------------------
#                                                    -
# We associate the source files with the target.     -
#                                                    -
#-----------------------------------------------------
target_sources(${target}
    PRIVATE ${simulation_state_header_files} ${simulation_state_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files )

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      simulation_state_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD ${simulation_state_cxx_standard}
                      PUBLIC_HEADER "${simulation_state_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${simulation_state_install_lib_directory}
         PUBLIC_HEADER DESTINATION ${simulation_state_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
