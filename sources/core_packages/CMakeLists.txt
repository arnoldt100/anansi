#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Make available the project cmake modules.          -
    #                                                    -
    #-----------------------------------------------------
    include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/core_packages_build_prerequisites.cmake )
    include( ${CMAKE_CURRENT_SOURCE_DIR}/command_line_arguments/cmake_macros_and_functions/command_line_arguments.cmake)
    include( ${CMAKE_CURRENT_SOURCE_DIR}/simulation_parameters/cmake_macros_and_functions/simulation_parameters.cmake)
    include( ${CMAKE_CURRENT_SOURCE_DIR}/file_parsers/cmake_macros_and_functions/file_parsers.cmake)
    include( ${CMAKE_CURRENT_SOURCE_DIR}/simulation_state/cmake_macros_and_functions/simulation_state.cmake)
    include( ${CMAKE_CURRENT_SOURCE_DIR}/simulation/cmake_macros_and_functions/simulation.cmake)
    include( ${CMAKE_CURRENT_SOURCE_DIR}/mpi_communicator/cmake_macros_and_functions/mpi_communicator.cmake)
    include( ${CMAKE_CURRENT_SOURCE_DIR}/logger/cmake_macros_and_functions/logger.cmake)
    include( ${CMAKE_CURRENT_SOURCE_DIR}/task_group/cmake_macros_and_functions/task_group.cmake)

    
    
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

# ----------------------------------------------------
#  Verify that all beuild prerequisites are satisfied 
# for target 'core_packages'.
# 
# ----------------------------------------------------
verify_core_packages_build_prerequisites_are_set()

#-----------------------------------------------------
# Call the macro that enables building of mouseion   -
# target.                                            -
#                                                    -
#-----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/mouseion/cmake_macros_and_functions/mouseion_library.cmake )
enable_building_mouseion("${anansi_minimum_cmake_version}" 
                         "${anansi_cxx_standard}"  
                         "${anansi_cmake_c_compiler}" 
                         "${anansi_cmake_cxx_compiler}" 
                         "${anansi_install_prefix}"
                         "${anansi_install_bin_directory}"
                         "${anansi_install_include_directory}"
                         "${anansi_install_lib_directory}"
                         "${CMAKE_CURRENT_LIST_DIR}/mouseion"
                         "$ENV{ANANSI_BOOST_TOP_LEVEL}")

#-----------------------------------------------------
# Call the macro that enables building of command    -
# line arguments target.                             -
#                                                    -
#-----------------------------------------------------
enable_building_command_line_arguments_library( "${anansi_install_lib_directory}"
                                                "${anansi_install_include_directory}"
                                                "${anansi_install_bin_directory}" 
                                                "${anansi_cxx_standard}")

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the simulation_parameters libraries,    -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
enable_building_simulation_parameters_library( "${anansi_install_lib_directory}"
                                               "${anansi_install_include_directory}"
                                               "${anansi_install_bin_directory}" 
                                               "${anansi_cxx_standard}" )

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the file_parsers libraries,             -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
enable_building_file_parsers_library( "${anansi_install_lib_directory}"
                                      "${anansi_install_include_directory}"
                                      "${anansi_install_bin_directory}" 
                                      "${anansi_cxx_standard}" )


# ----------------------------------------------------
# Here we define variables which indicate where
# to install the simulation_state libraries,
# header files, and associated binariers.
# 
# ----------------------------------------------------
enable_building_simulation_state_library( "${anansi_install_lib_directory}"
                                          "${anansi_install_include_directory}"
                                          "${anansi_install_bin_directory}" 
                                          "${anansi_cxx_standard}" )

# ----------------------------------------------------
# Here we define variables which indicate where
# to install the simulation_state libraries,
# header files, and associated binariers.
# 
# ----------------------------------------------------
enable_building_simulation_library( "${anansi_install_lib_directory}"
                                    "${anansi_install_include_directory}"
                                    "${anansi_install_bin_directory}" 
                                    "${anansi_cxx_standard}" )

# ----------------------------------------------------
# Here we define variales which indicate where
# to install the mpi_communicator libraries,
# header files, and associated binariers.
# 
# ----------------------------------------------------
enable_building_mpi_communicator_library( "${anansi_install_lib_directory}"
                                          "${anansi_install_include_directory}"
                                          "${anansi_install_bin_directory}" 
                                          "${anansi_cxx_standard}" )

# ----------------------------------------------------
# Here we define variales which indicate where
# to install the logger libraries,
# header files, and associated binariers.
# 
# ----------------------------------------------------
enable_building_logger_library( "${anansi_install_lib_directory}"
                                "${anansi_install_include_directory}"
                                "${anansi_install_bin_directory}" 
                                "${anansi_cxx_standard}" )

# ----------------------------------------------------
# Here we define variables which indicate where to install the task_group
# libraries, header files, and associated binaries.
# 
# ----------------------------------------------------
enable_building_task_group_library( "${anansi_install_lib_directory}"
                                    "${anansi_install_include_directory}"
                                    "${anansi_install_bin_directory}" 
                                    "${anansi_cxx_standard}" )

#-----------------------------------------------------
# Add the subdirectories for the various             -
# libraries.                                         -
#                                                    -
#-----------------------------------------------------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mouseion)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/simulation_state)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/simulation)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/command_line_arguments)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/simulation_parameters)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/file_parsers)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mpi_communicator)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/logger)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/task_group)

