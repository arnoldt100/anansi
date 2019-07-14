#-----------------------------------------------------
# Check that the cmake minimum version is            -
# satisfied.                                         -
#                                                    -
#-----------------------------------------------------
cmake_minimum_required(VERSION $ENV{ANANSI_MINIMUM_CMAKE_VERSION})

#-----------------------------------------------------
# Define the project.                                -
#                                                    -
#-----------------------------------------------------
project(anansi)

#-----------------------------------------------------
# Turn on verbose debugging.                         -
#                                                    -
#-----------------------------------------------------
set(CMAKE_VERBOSE_MAKEFILE ON)

#-----------------------------------------------------
# Make available the project cmake modules.          -
#                                                    -
#-----------------------------------------------------
include( $ENV{ANANSI_CMAKE_MODULE_PATH}/anansi_build_prerequisites.cmake )
include( $ENV{ANANSI_CMAKE_MODULE_PATH}/anansi_boost.cmake )
include( $ENV{ANANSI_CMAKE_MODULE_PATH}/enable_compile_warnings.cmake )
#-----------------------------------------------------
# Check that key environmental variables are set.    -
#                                                    -
#-----------------------------------------------------
verify_key_environmental_are_set()

#-----------------------------------------------------
# Here we define some variables.                     -
# that are critical for building and deploying.      -
#-----------------------------------------------------
set(anansi_top_level $ENV{ANANSI_TOP_LEVEL}) 
set(anansi_cmake_cxx_compiler $ENV{ANANSI_CMAKE_CXX_COMPILER})
set(anansi_cmake_c_compiler $ENV{ANANSI_CMAKE_C_COMPILER})
set(anansi_install_prefix $ENV{ANANSI_INSTALL_PREFIX})
set(anansi_install_bin_directory $ENV{ANANSI_INSTALL_BIN_DIRECTORY})
set(anansi_install_include_directory $ENV{ANANSI_INSTALL_INCLUDE_DIRECTORY})
set(anansi_install_lib_directory $ENV{ANANSI_INSTALL_LIB_DIRECTORY})
set(anansi_minimum_cmake_version $ENV{ANANSI_MINIMUM_CMAKE_VERSION})

set(memory_management_install_lib_directory ${anansi_install_lib_directory})
set(memory_management_install_include_directory ${anansi_install_include_directory})
set(memory_management_install_bin_directory ${anansi_install_bin_directory} )

set(command_line_arguments_install_lib_directory ${anansi_install_lib_directory})
set(command_line_arguments_install_include_directory ${anansi_install_include_directory})
set(command_line_arguments_install_bin_directory ${anansi_install_bin_directory} )

#-----------------------------------------------------
# This section permits use to find the header files  -
# and link against the BOOST library.                -
#                                                    -
#-----------------------------------------------------
enable_boost($ENV{ANANSI_BOOST_TOP_LEVEL}) # The enable_boost macro 
                                           # sets up the boost library for
                                           # linking against.

#-----------------------------------------------------
# Add the subdirectories for the various             -
# libraries.                                         -
#                                                    -
#-----------------------------------------------------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/CPUMemoryAllocation)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/simulation_parameters)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/command_line_arguments)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/boundary_conditions)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/force_fields)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/neighbor_lists)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/integrators)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/file_parsers)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/molecular_topologies)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/communicator)

#-----------------------------------------------------
# This subdirectory builds the main molecular        -
# dynamics program.                                  -
#                                                    -
#-----------------------------------------------------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/molecular_dynamics)
