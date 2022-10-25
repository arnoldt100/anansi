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

# ----------------------------------------------------
# Call the macro that enables build the receiver target and add the receiver
# package.
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/receiver/cmake_macros_and_functions/receiver.cmake )
enable_building_receiver_package( "${core_packages_install_lib_directory}"
                                  "${core_packages_install_include_directory}"
                                  "${core_packages_install_bin_directory}" 
                                  "${core_packages_cxx_standard}"
                                  "${core_packages_logfilepath}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/receiver)

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
                         "${core_packages_logfilepath}")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mouseion)


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
                                               "${core_packages_cxx_standard}"
                                               "${core_packages_logfilepath}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/simulation_parameters)

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the file_parsers libraries,             -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/file_parsers/cmake_macros_and_functions/file_parsers.cmake)
enable_building_file_parsers_package( "${core_packages_install_lib_directory}"
                                      "${core_packages_install_include_directory}"
                                      "${core_packages_install_bin_directory}" 
                                      "${core_packages_cxx_standard}"
                                      "${core_packages_logfilepath}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/file_parsers)

# ----------------------------------------------------
# Here we define variables which indicate where
# to install the simulation_state libraries,
# header files, and associated binariers.
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/simulation_state/cmake_macros_and_functions/simulation_state.cmake)
enable_building_simulation_state_package( "${core_packages_install_lib_directory}"
                                          "${core_packages_install_include_directory}"
                                          "${core_packages_install_bin_directory}" 
                                          "${core_packages_cxx_standard}"
                                          "${core_packages_logfilepath}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/simulation_state)

# ----------------------------------------------------
# Here we define variables which indicate where
# to install the simulation_state libraries,
# header files, and associated binariers.
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/simulation/cmake_macros_and_functions/simulation.cmake)
enable_building_simulation_package( "${core_packages_install_lib_directory}"
                                    "${core_packages_install_include_directory}"
                                    "${core_packages_install_bin_directory}" 
                                    "${core_packages_cxx_standard}"
                                    "${core_packages_logfilepath}" )
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
                                          "${core_packages_cxx_standard}"
                                          "${core_packages_logfilepath}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mpi_communicator)
add_dependencies(mpi_communicator receiver)

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
# Here we define variables which indicate where to install the tasks
# libraries, header files, and associated binaries.
# 
# ----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/tasks/cmake_macros_and_functions/tasks.cmake)
enable_building_tasks_library( "${core_packages_install_lib_directory}"
                                    "${core_packages_install_include_directory}"
                                    "${core_packages_install_bin_directory}" 
                                    "${core_packages_cxx_standard}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tasks)

#-----------------------------------------------------
# Call the macro that enables build the invoker target and add the invoker
# package.
#
#-----------------------------------------------------
include( ${CMAKE_CURRENT_SOURCE_DIR}/invoker/cmake_macros_and_functions/invoker.cmake )
enable_building_invoker_package( "${core_packages_install_lib_directory}"
                                  "${core_packages_install_include_directory}"
                                  "${core_packages_install_bin_directory}" 
                                  "${core_packages_cxx_standard}"
                                  "${core_packages_logfilepath}" )
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/invoker)
