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
# target and add mouseion package.                   -
#                                                    -
#-----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/mouseion/cmake_macros_and_functions/mouseion_library.cmake )
enable_building_mouseion("${core_packages_minimum_cmake_version}" 
                         "${core_packages_cxx_standard}"  
                         "${core_packages_cmake_c_compiler}" 
                         "${core_packages_cmake_cxx_compiler}" 
                         "${core_packages_install_prefix}"
                         "${core_packages_install_bin_directory}"
                         "${core_packages_install_include_directory}"
                         "${core_packages_install_lib_directory}"
                         "${CMAKE_CURRENT_SOURCE_DIR}/mouseion"
                         "$ENV{ANANSI_BOOST_TOP_LEVEL}"
                         ${core_packages_logfilepath})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mouseion)

#-----------------------------------------------------
# Call the macro that enables building of command    -
# line arguments target.                             -
#                                                    -
#-----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/command_line_arguments/cmake_macros_and_functions/command_line_arguments.cmake)
enable_building_command_line_arguments_library( "${core_packages_install_lib_directory}"
                                                "${core_packages_install_include_directory}"
                                                "${core_packages_install_bin_directory}" 
                                                "${core_packages_cxx_standard}")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/command_line_arguments)

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the simulation_parameters libraries,    -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/simulation_parameters/cmake_macros_and_functions/simulation_parameters.cmake)
enable_building_simulation_parameters_library( "${core_packages_install_lib_directory}"
                                               "${core_packages_install_include_directory}"
                                               "${core_packages_install_bin_directory}" 
                                               "${core_packages_cxx_standard}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/simulation_parameters)

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the file_parsers libraries,             -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/file_parsers/cmake_macros_and_functions/file_parsers.cmake)
enable_building_file_parsers_library( "${core_packages_install_lib_directory}"
                                      "${core_packages_install_include_directory}"
                                      "${core_packages_install_bin_directory}" 
                                      "${core_packages_cxx_standard}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/file_parsers)


# ----------------------------------------------------
# Here we define variables which indicate where
# to install the simulation_state libraries,
# header files, and associated binariers.
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/simulation_state/cmake_macros_and_functions/simulation_state.cmake)
enable_building_simulation_state_library( "${core_packages_install_lib_directory}"
                                          "${core_packages_install_include_directory}"
                                          "${core_packages_install_bin_directory}" 
                                          "${core_packages_cxx_standard}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/simulation_state)

# ----------------------------------------------------
# Here we define variables which indicate where
# to install the simulation_state libraries,
# header files, and associated binariers.
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/simulation/cmake_macros_and_functions/simulation.cmake)
enable_building_simulation_library( "${core_packages_install_lib_directory}"
                                    "${core_packages_install_include_directory}"
                                    "${core_packages_install_bin_directory}" 
                                    "${core_packages_cxx_standard}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/simulation)

# ----------------------------------------------------
# Here we define variales which indicate where
# to install the mpi_communicator libraries,
# header files, and associated binariers.
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/mpi_communicator/cmake_macros_and_functions/mpi_communicator.cmake)
enable_building_mpi_communicator_library( "${core_packages_install_lib_directory}"
                                          "${core_packages_install_include_directory}"
                                          "${core_packages_install_bin_directory}" 
                                          "${core_packages_cxx_standard}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mpi_communicator)

# ----------------------------------------------------
# Here we define variales which indicate where
# to install the logger libraries,
# header files, and associated binariers.
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/logger/cmake_macros_and_functions/logger.cmake)
enable_building_logger_library( "${core_packages_install_lib_directory}"
                                "${core_packages_install_include_directory}"
                                "${core_packages_install_bin_directory}" 
                                "${core_packages_cxx_standard}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/logger)

# ----------------------------------------------------
# Here we define variables which indicate where to install the task_group
# libraries, header files, and associated binaries.
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/task_group/cmake_macros_and_functions/task_group.cmake)
enable_building_task_group_library( "${core_packages_install_lib_directory}"
                                    "${core_packages_install_include_directory}"
                                    "${core_packages_install_bin_directory}" 
                                    "${core_packages_cxx_standard}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/task_group)


